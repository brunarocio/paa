#include <stdio.h>
#include <stdlib.h>
#include "crypto.h"

int criptografar(){
	printf("Teste");
	return 0;
}

int descriptografar(){
	
}

void gravarArquivo(char *info){
	//char filename[100];
	//filename = ('teste');
	FILE *fmat;
	fmat = fopen("arquivo.txt", "w");
	fprintf(fmat,info);
	//sprintf(fmat,"teste 2 sprint");
	fclose(fmat);
}

void quebraBruta(){
	
}


