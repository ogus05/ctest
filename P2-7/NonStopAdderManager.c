#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define STR_LEN 256

int _tmain(int argc, TCHAR* argv[]){
    STARTUPINFO si1 = {0,};
    STARTUPINFO si2 = {0,};
    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;
    TCHAR command1[STR_LEN] = _T("PartAdder.exe 1 5");
    TCHAR command2[STR_LEN] = _T("PartAdder.exe 6 10");
    CreateProcess(
        NULL, command1, NULL, NULL,
        TRUE, 0, NULL, NULL, &si1, &pi1
    );CreateProcess(
        NULL, command2, NULL, NULL,
        TRUE, 0, NULL, NULL, &si2, &pi2
    );
    CloseHandle(pi1.hThread);
    CloseHandle(pi2.hThread);
    HANDLE hpr[] = {pi1.hProcess,pi2.hProcess};
    DWORD state1 = WaitForMultipleObjects(2,hpr,TRUE,INFINITE);
    DWORD a,b;
    GetExitCodeProcess(pi1.hProcess,&a);
    GetExitCodeProcess(pi2.hProcess,&b);
    _tprintf("%d",a + b);
    return 0;
}
