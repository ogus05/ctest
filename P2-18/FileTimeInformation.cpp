#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define STR_LEN 100

int _tmain(int argc, TCHAR* argv[]){
    TCHAR fileName[] = _T("RealScaleViewer.exe");

    TCHAR fileCreateTimeInfo[STR_LEN];
    TCHAR fileAccessTimeInfo[STR_LEN];
    TCHAR fileWriteTimeInfo[STR_LEN];

    FILETIME ftCreate, ftAccess, ftWrite;

    SYSTEMTIME stCreateUTC, stCreateLocal;
    SYSTEMTIME stAccessUTC, stAccessLocal;
    SYSTEMTIME stWriteUTC, stWriteLocal;

    HANDLE hFile = CreateFile(
        fileName, GENERIC_READ, 0, 0,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
    );

    if(hFile == INVALID_HANDLE_VALUE){
        _tprintf(_T("File open fault! \n"));
        return -1;
    }

    if(!GetFileTime(hFile,&ftCreate, &ftAccess, &ftWrite)){
        _tprintf(_T("GetFileTime function call fault! \n"));
        return FALSE;
    }

    FileTimeToSystemTime(&ftCreate, &stCreateUTC);
}