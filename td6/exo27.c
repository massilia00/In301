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

List* ajout_avant(List* t, int val){
    List *l = malloc(sizeof(List)); // nouvell tete
    
    l->val = val; // remplissage de la nouvelle tete
    l->next = t; // next nouvelle tete = tete precedente
    t = l;  // nouvelle tete = l

    return l;
}

List* supp_deb(List *l){
    List *tmp = l->next; // 4 6 3
    free(l);
    return tmp;
}

void supp_deb(List **l){
    List *tmp = (*l)->next; // 4 6 3
    free(*l);
}

void ajout_avant(List** t, int val){
    List *l = malloc(sizeof(List)); // nouvell tete
    
    l->val = val; // remplissage de la nouvelle tete
    l->next = *t; // next nouvelle tete = tete precedente
    *t = l;  // nouvelle tete = l
}

int main(int argc, char *argv[]){
    List *l = inti_list(1);
    /*ajouter*/
    l = supp_deb(l);
}