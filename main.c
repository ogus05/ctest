#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define STR_LEN 256
#define CMD_TOKEN_NUM 10

TCHAR ERR_CMD[] = _T("'%s'�� ������ �� �ִ�  ���α׷��� �ƴմϴ�. \n");

int CmdProcessing(void);
TCHAR* StrLower(TCHAR *);
void CmdInput(void);
TCHAR cmdString[STR_LEN];

int _tmain(int argc, TCHAR *argv[]){
    _tsetlocale(LC_ALL,_T("Korean"));
    DWORD isExit;
    if(argc != 1){
        for(int i = 1;i<argc;i++){
            _tcscat(cmdString,argv[i]);
            _tcscat(cmdString,_T(" "));
        }
        CmdProcessing();
    }
    while(1){
        CmdInput();
        isExit = CmdProcessing();
        if(isExit == TRUE){
            _fputts(_T("��ɾ� ó���� �����մϴ�. \n"),stdout);
            break;
        }
    }
    return 0;
}


TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

void CmdInput(void){
    _fputts(_T("Best command prompt>> "),stdout);
    _getts(cmdString);
}

int CmdProcessing(void){
    TCHAR* token = _tcstok(cmdString, seps);
    int tokenNum = 0;
    while(token != NULL){
        _tcscpy(cmdTokenList[tokenNum++], StrLower(token));
        token = _tcstok(NULL, seps);
    }
    if(!_tcscmp(cmdTokenList[0],_T("exit"))){
        return TRUE;
    } else if(!_tcscmp(cmdTokenList[0],_T("start"))){
        STARTUPINFO si = {0,};
        PROCESS_INFORMATION pi;
        si.cb = sizeof(si); 
        si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
        si.dwX = 100;
        si.dwY = 200;
        si.dwXSize = 300;
        si.dwYSize = 200;
        TCHAR command[STR_LEN] = _T("main.exe");
        CreateProcess(
            NULL, command, NULL,NULL, TRUE,
            CREATE_NEW_CONSOLE, NULL, NULL,
            &si, &pi
        );
    } else if(!_tcscmp(cmdTokenList[0],_T("dir"))){
         
    } else{
        STARTUPINFO si = {0,};
        PROCESS_INFORMATION pi;
        si.cb = sizeof(si);
        TCHAR *command = cmdTokenList[0];
        ZeroMemory(&pi,sizeof(pi));
        int status = CreateProcess(
            NULL, command, NULL, NULL,
            TRUE, 0, NULL, NULL, &si, &pi
        );
        if(status == 0) _tprintf(ERR_CMD, cmdTokenList[0]);
    }
    return 0;
}

TCHAR *StrLower(TCHAR *pStr){
    TCHAR *ret = pStr;
    while(*pStr){
        if(_istupper(*pStr)){
            *pStr = _totlower(*pStr);
            pStr++;
        }
        return ret;
    }
}