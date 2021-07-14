#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[]){
    TCHAR* sysPathBuf;
    TCHAR* winPathBuf;
    GetSystemDirectory(sysPathBuf, MAX_PATH);
    GetWindowsDirectory(winPathBuf, MAX_PATH);

    _tprintf(_T("System dir: %s \n"), sysPathBuf);
    _tprintf(_T("Windows dir: %s \n"),winPathBuf);
    return 0;
}