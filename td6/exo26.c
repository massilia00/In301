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
}

List* ajout_avant(List* l, int val){
    List *tmp = malloc(sizeof(List));
    
    tmp->val = val;
    tmp->next = l;
    l = tmp; 

    return l;
}


void affiche_iter(List *l){
    while(l != NULL){
        printf("val : %d\n", l->val);
        l = l->next;
    }
}


void affiche_rec(List* l){
    if(l != NULL){
        printf("val : %d\n", l->val);
        affiche_rec(l->next);
    }
}

void freeList(List *l){
    while(l != NULL){
        List *tmp = l->next;
        free(l);
        l = tmp;
    }
}


int nb_elem_iter(List *l){
    int cpt = 0;
    while(l!=NULL){
        cpt++;
    }
    return cpt;
}


int nb_elem_rec(List *l){
    if(l == NULL)
        return 0;
    else
        return 1 + nb_elem_rec(l->next);   
}

int est_present_iter(List *l, int val){
    while(l != NULL){
        if(l->val = val)
            return 1;
    }

    return 0;
}

int est_present_rec(List *l, int val){
    if(l == NULL)
        return 0;
    
    if(l->val == val)
        return 1;
    else
        return est_present_rec(l->next, val);
    
}

int main(int argc, char *argv[]){
    List *l = inti_list(17);

    l = ajout_avant(l, 23);

    List *tmp = malloc(sizeof(List));
    tmp->val = 42;
    tmp->next = l->next; // 42 -> 17
    l->next = tmp; // 23 -> 42

    affiche_rec(l);
    printf("nb elem : %d\n", est_present_rec(l, 40));
    freeList(l);
}