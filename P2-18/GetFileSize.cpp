#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[]){
    TCHAR fileName[] = _T("");
    HANDLE hFile = CreateFile(
        fileName, GENERIC_READ, 0, 0, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, 0
    );
    if(hFile == INVALID_HANDLE_VALUE){
        _tprintf(_T("File open fault!\n"));
        return -1;
    }

    DWORD high4byteFileSize = 0;
    DWORD low4ByteFileSize= GetFileSize(hFile, &high4byteFileSize);
    _tprintf(_T("High : %u byte\n"),high4byteFileSize);
    LARGE_INTEGER fileSize;
    GetFileSizeEx(hFile, &fileSize);
    _tprintf(_T("Total file size: %u byte \n"), fileSize.QuadPart);
}