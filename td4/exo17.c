#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    printf("double : %lf %lf %lf\n", a, b, c);
}