#include <stdlib.h>
#include <stdio.h>

#include "canstante.h"


void lecture(){
	FILE* fic = fopen(NOMFIC, "r");
	int t[N+1], i = 0;
	
	if(fic == NULL){
		fprintf(stderr, "Error: faild not open");
		exit(1);
	}
	
	while(!feof(fic)){
		fscanf(fic, "%6d", &t[i]);
		printf("%d\n", t[i]);
		i++;	
	}
	
	
	int a;
	int n = fscanf(fic, "%6d", &a);
	int t[n];
	
	
	fclose(fic);
}



int main(){
	srand(getpid());
	
	lecture();

	return 0;
}
