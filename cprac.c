#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <tchar.h>

TCHAR op[100];

void func1(int num){
    TCHAR* res;
    res = op;
    res = _T(" ");
}

int _tmain(int argc, TCHAR* argv[]){
    func1(2);
    _tprintf("%s",op);
    return 0;
} 