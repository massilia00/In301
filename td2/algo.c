#include <stdlib.h>
#include <stdio.h>
#include "canstante.h"

int t[N+1];

void lecture(){
	FILE* fic = fopen(NOMFIC, "r");
	int i = 0;
	
	if(fic == NULL){
		fprintf(stderr, "Error: faild not open");
		exit(1);
	}
	while(fscanf(fic, "%6d", &t[i]) != EOF){
		i++;	
	}	
	
	fclose(fic);
}


int recherche (int x){
	int cmp ;
	for(int i = 0; i < N; i++){
		if( t[i] == x){ 
			printf("Nb comparaison : %d\n", cmp);
			return 0;
		}
		cmp++ ;
	}
	return 1;
}

int stat_recherche (int x){
	int cmp ;
	for(int i = 0; i < N; i++){
		if( t[i] == x){
			return cmp;
		}
		cmp++;
	}
	return 0;
}

int main(){
	srand(getpid());
	
	lecture();
 
	double moy = 0;
	
	for(int i=0 ; i<10 ; i++){
		moy += stat_recherche (rand() % (5*MAX)) ;
		printf("%d\n", moy);
	}
		
	moy /= 10000;
	
	printf("Moyenne de recherche : %lf\n", moy);

	return 0;
	
}
