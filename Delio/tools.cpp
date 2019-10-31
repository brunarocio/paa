#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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


long double *gerarNumeroAleatorio(int tamanho){
	char numero[50];
	char *pNumero = &numero[0];
	int partNumero;
	srand(time(NULL));
	for(int i = 0; i<tamanho;i++){
		partNumero = rand() % 10;
		//numero[i] = partNumero+'0';
		numero[i] = partNumero+'0';
	}
	//printf("Numero: %s\n",numero);
	//printf("ultim numero: %i",partNumero);
	if (partNumero%2 == 0){
		partNumero +=1;
		//printf("novo ultimo numero %i\n",partNumero);
		numero[tamanho-1] = partNumero+'0';
		//numero[tamanho-1] = partNumero
	}
	//printf("NOvo numero impar %s",numero);

	printf("Numero: %s\n",numero);
	gravarArquivo(pNumero);
	numero[1] = '.';
	numero[tamanho-1]= '\O';
	char *pnumeroIni = pNumero;
	char *e;
	long double numeroFinal = strtold(pnumeroIni,&e);
	return &numeroFinal;
	
	
}

