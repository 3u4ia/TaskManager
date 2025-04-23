This project uses the Win32 API to list out all the PID's and filePaths of the executing processes in a system.

While making this project I've learned I have a sincere hatred for Visual Studio. 
I feel that it's very bloated with all of it's files just to make a c project, at least compared to gcc.



Also when running this project there are a lot of "errors" where the program outputs "Failed to getModule" along with an Error number of 6. 
  The reason this is happeneing is because the handle I supply to the GetModuleFileNameExW function doesn't have sufficient permissions to get those modules. If you'd like a lot more permissions to be able to see more file names just change the first parameter in the OpenProcess function to PROCESS_ALL_ACCESS.
    Be careful! Windows defender may flag your program as a virus and prevent you from being able to execute/build the program.
Most of the PIDs of those processes you didn't get modules for are svchost.exes and other win32 system processes. If you go to go to the file location of the 
