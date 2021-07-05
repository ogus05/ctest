#include <stdio.h>
#include <string.h>

int main(){
    char a[] = "wewewe sdsdsd adadad";
    char *result = strtok(a, " ");
    char b[30] = "457";
    while(result != NULL){
        strcat(b,result);
        result = strtok(NULL, " ");
    }
    printf("%s",b);
    return 0;
} 