#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

void gravarArquivo(char *info){
	//char filename[100];
	//filename = ('teste');
	FILE *fmat;
	fmat = fopen("arquivo.txt", "w");
	fprintf(fmat,info);
	//sprintf(fmat,"teste 2 sprint");
	fclose(fmat);
}


