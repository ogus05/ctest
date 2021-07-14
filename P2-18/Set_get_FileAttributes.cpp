#include <stdio.h>
#include <tchar.h>
#include <windows.h>

void ShowAttributes(DWORD attrib);

int _tmain(int argc, TCHAR* argv[]){
    TCHAR fileName[] = _T("C:\\mingw64");

    _tprintf(_T("Original file attributes \n"));
    DWORD attrib = GetFileAttributes(fileName);
    ShowAttributes(attrib);

    attrib ^= (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN);
    SetFileAttributes(fileName, attrib);

    _tprintf(_T("Changed file attributes \n"));
    attrib = GetFileAttributes(fileName);
    ShowAttributes(attrib);
    return 0;
}

void ShowAttributes(DWORD attrib){
    if(attrib & FILE_ATTRIBUTE_NORMAL){
        _tprintf(_T("Normal \n"));
    } else{
        if(attrib & FILE_ATTRIBUTE_READONLY){
            _tprintf(_T("ReadOnly\n"));
        } if(attrib & FILE_ATTRIBUTE_HIDDEN){
            _tprintf(_T("Hidden\n"));
        }
        _tprintf(_T("\n"));
    }
}