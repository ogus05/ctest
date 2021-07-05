#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define STR_LEN 256
#define CMD_TOKEN_NUM 10

TCHAR ERR_CMD[] = _T("'%s'는 실행할 수 있는  프로그램이 아닙니다. \n");

int CmdProcessing(void);
TCHAR * StrLower(TCHAR *);


int _tmain(int argc, TCHAR *argv[]){
    _tsetlocale(LC_ALL,_T("Korean"));
    DWORD isExit;
    while(1){
        isExit = CmdProcessing();
        if(isExit == TRUE){
            _fputts(_T("명령어 처리를 종료합니다. \n"),stdout);
            break;
        }
    }
    return 0;
}

TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");
TCHAR cmdNext[STR_LEN]; 

int CmdProcessing(void){
    _fputts(_T("Best command prompt>> "),stdout);
    _getts(cmdString);
    TCHAR* token = _tcstok(cmdString, seps);
    TCHAR options[CMD_TOKEN_NUM][STR_LEN];
    int tokenNum = 0;
    int optionNum = 0;
    while(TRUE){
        if(token[0] == '/'){
            _tcscpy(options[optionNum++], StrLower(token));
        } else{
            _tcscpy(cmdTokenList[tokenNum++], StrLower(token));
        }
        token = _tcstok(NULL, seps);
        if(token == NULL){
            break;
        }
        else{
            _tcscat(cmdNext,token);
            _tcscat(cmdNext,_T(" "));
        }
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
        TCHAR command[STR_LEN] = _T("main.exe ");
        _tcscat(command, cmdNext);
        _tprintf(_T("%s"),command);
        TCHAR* tokenBundle = cmdTokenList[1];
        CreateProcess(
            NULL, command, NULL,NULL, TRUE,
            CREATE_NEW_CONSOLE, NULL, NULL,
            &si, &pi
        );
    } else if(!_tcscmp(cmdTokenList[0],_T("명령어2"))){

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