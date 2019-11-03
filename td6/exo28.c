#include <stdlib.h>
#include <stdio.h>

struct  list{
    int val;
    struct list *next;
};

typedef struct list List;

List* inti_list(int val){
    List *l = malloc(sizeof(List)); // Declarer et initiliser une liste vide

    l->val = val;
    l->next = NULL;

    return l;
}

List* append(List *t, int val){
    List *l = t;
    while(l->next != NULL)
        l = l->next;
    
    List *tmp = malloc(sizeof(List));
    tmp->val = val;
    tmp->next = NULL;
    l->next = tmp;

    return l;
}

void append_rec(List *t, int val){
    if(t->next == NULL){
        List *tmp = malloc(sizeof(List));
        tmp->val = val;
        tmp->next = NULL;
        t->next = tmp;
    }else{
        append_rec(t->next, val);
    }
}

void supp_fin(List *t){
    List *tmp = t;
    while(t->next != NULL){
        tmp = t;
        t = t->next;
    }

    tmp->next = NULL;
    free(t);
}

void supp_mil(List *t, int val){
    List *tmp = t;
    while(t->val != val){
        tmp = t;
        t = t->next;
    }
    tmp->next = t->next;
    free(t);
}

int main(int argc, char *argv[]){

}