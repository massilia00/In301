#include <stdlib.h>
#include <stdio.h>

#include "canstante.h"

void ecrire(){
	FILE* fichier = NULL;
	fichier = fopen(NOMFIC, "a");
	
	if(fichier == NULL){
		fprintf(stderr, "Error : failed opennig file");
		exit(1);
	}
	
	fprintf(fichier, "%6d\n", rand() % MAX);
	
	fclose(fichier);
}

int main(){
	srand(getpid());
	
	for(int i = 0; i < N; i++){
		ecrire();
	}

	return 0;
}
