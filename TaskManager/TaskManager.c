#include <stdio.h>
#include <Windows.h>
#include <psapi.h>

#define SIZE_OF_PROCESS_IDS 1000

void getAndDisplayprocessInfo(DWORD processIds[], int totalProcIds);

int main() {

	DWORD *processIds = (DWORD*)malloc(1000 * sizeof(DWORD));

	DWORD countOfBytes;

	int bytesProcessIds = 1000 * sizeof(DWORD);

	printf("sizeof dword: %zu\n", sizeof(DWORD));



	int executedSuccesfully = EnumProcesses(
		processIds,
		bytesProcessIds,
		&countOfBytes
	);

	if (!executedSuccesfully) {
		DWORD error = GetLastError();
		printf("Error occured with EnumProcesses: %lu\n", error);
		//printf("byteCount %d", *countOfBytes);
		exit(1);
	}
	else {
		printf("Executed successfully!\n");
	}

	int totalProcIds = countOfBytes / sizeof(DWORD);

	printf("totalProcIds: %d\n", totalProcIds);

	getAndDisplayprocessInfo(processIds, totalProcIds);

	printf("Finished!\n");

	printf("Press Enter to close the window");

	getchar();


	return 0;
}

void getAndDisplayprocessInfo(DWORD processIds[], int totalProcIds) {
	HANDLE hProcess = NULL;
	DWORD moduleStuff = NULL;
	wchar_t fileName[100];
	for (int i = 0; i < totalProcIds; i++) {
		
		
		hProcess = OpenProcess(
			PROCESS_QUERY_LIMITED_INFORMATION,
			FALSE,
			processIds[i]
		);

		if (hProcess == INVALID_HANDLE_VALUE) {
			printf("Invalid proc handle\n");
		}
		
		
		moduleStuff = GetModuleFileNameExW(
			hProcess,
			NULL,
			&fileName,
			sizeof(fileName) / sizeof(fileName[0])
		);

		if (moduleStuff == 0) {
			DWORD error = GetLastError();
			printf("Failed to getModule for proc: %lu\n", processIds[i]);
			printf("\tError: %lu\n", error);
			if (hProcess != NULL) {
				CloseHandle(hProcess);
			}
			continue;
		}
		else {
			wprintf(L"Process Name : % ls", fileName);
		}


		printf("    ProcessId: %u\n", processIds[i]);

		CloseHandle(hProcess);

	}
	return;
}