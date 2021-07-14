#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define VALUE_LEN 1024

int _tmain(int argc, TCHAR* argv[]){
    TCHAR fileName[] = _T("data.txt");
    TCHAR fileData[VALUE_LEN];
    HANDLE hFile = CreateFile(
        fileName,GENERIC_READ, FILE_SHARE_READ, 0,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 
    );
    if(hFile == INVALID_HANDLE_VALUE){
        _tprintf(_T("File read fault!"));
        return 1;
    }
    DWORD rcvLen;
    ReadFile(hFile, fileData, sizeof(fileData), &rcvLen, NULL);
    fileData[rcvLen/sizeof(TCHAR)] = 0;
    _tprintf(_T("%s\n"),fileData);
    _tprintf(_T("%u\n"),rcvLen);
    CloseHandle(hFile);

}