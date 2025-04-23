While making this project I've learned I have a sincere hatred for Visual Studio. 
I feel that it's very bloated with all of it's files just to make a c project, at least compared to gcc.

Also when running this project there are a lot of "errors" where the program outputs "Failed to getModule" along with an Error number of 6.
  The reason this is happeneing is because the handle I supply to the GetModuleFileNameExW function doesn't have sufficient permissions to get those modules.
Most of the PIDs of those processes you didn't get modules for are svchost.exes and other win32 system processes. If you go to go to the file location of the 
