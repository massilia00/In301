#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int len_iter(char *str){
    int i = 0;
    for(i = 0; str[i] != '\0'; i++){}
    return i;
}

int len_rec(char *str){
    return (str[0] == '\0')? 0 : len_rec(str + 1) + 1;
}

int cmp(char *a, char *b){
    int la , lb ;
    la=len_iter(a);
}


int miroir(char *a, char *b){
    if(strlen(a) == strlen(b)){
        int i, k;
        for(i = 0, k = strlen(b) - 1; i < strlen(a) && k >=0 && a[i] == b[k] ; i++, k--){}

        if(a[i] == b[k])
            return 1;
        else
            return 0;
        
    }
    return 0;
}

int sub_str(char *a, char* b){
    int i, k;
    for(i = 0; i < strlen(a); i++){
        for(k = 0; k < strlen(b) && k + i < strlen(a)  && a[k + i] == b[k]; k++){}

        if(k >= strlen(b))
            return 1;
    }
    return 0;
}


int main(int argc, char *argv[]){
    if(sub_str(argv[1], argv[2]))
        printf("%s est ss de %s\n", argv[2], argv[1]);
    else    
        printf("%s est !ss de %s\n", argv[2], argv[1]);
}