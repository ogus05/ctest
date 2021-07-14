#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define CREATE_DIRECTORY 0

int _tmain(int argc, TCHAR* argv[]){
    TCHAR dirReletivePath[] = _T("GoodDirectoryOne");
    TCHAR dirFullPath[] = _T("C:\\GoodDirectoryTwo");

    #if CREATE_DIRECTORY
        CreateDirectory(dirReletivePath,NULL);
        CreateDirectory(dirFullPath,NULL);
    #else
        RemoveDirectory(dirReletivePath);
        RemoveDirectory(dirFullPath);
    #endif
    return 0;
    }