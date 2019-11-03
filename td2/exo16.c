#include <stdlib.h>
#include <stdio.h>

int N;
int *T;

int nb_entiers(char *nom){
    int nb = 0, a;
    FILE* fic = fopen(nom, "r");

    while(fscanf(fic, "%6d", &a) != EOF)
        nb++;

    fclose(fic);
    return nb;
}


void remplir(char *nom){
    N = nb_entiers(nom);
    T = malloc(sizeof(int) * N);
    int a, i = 0;

    FILE* fic = fopen(nom, "r");
    while(fscanf(fic, "%6d", &a) != EOF){
        T[i] = a;
        i++;
    }
    fclose(fic);
}

int indice_max(int k){
    int index = 0, max = T[0];

    for(int i = 1; i < k; i++){
        if(max < T[i]){
            max = T[i];
            index = i;
        }
    }

    return index;
}


void echange(int *T, int a, int b){
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;    
}


void echange_max(int k){
    int a ;
    if(k < N && k > 0){
        a = indice_max(k);
        echange(T, a, k);
    }
}

void trie (){
    for(int i=N-1; i>1; i--){
        echange_max(i);
    }
}

int main(){
    remplir("nombre.data");
    for(int i = 0; i < N; i++){
        printf("-> %d\n", T[i]);
    }
    printf("-------\n");
    trie();

    for(int i = 0; i < N; i++){
        printf("-> %d\n", T[i]);
    }
    
    return 0;
}