#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int main(int argc, char** argv){
    DWORD a = 10;
    LPVOID b = (LPVOID)a;
    _tprintf(_T("%d"),(DWORD)b);
}