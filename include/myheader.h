#include <iostream>
#include <string.h>
#include <cstdio>

#ifdef WINDOWS
    #include <direct.h>
    #include <windows.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
    #include <signal.h>
#endif
