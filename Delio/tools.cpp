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
	fclose(fmat);
}


long double *gerarNumeroAleatorio(int tamanho){
	long double numeroFinal;
	char numero[50];
	char *pNumero = &numero[0];
	char *pnumeroIni;
	int partNumero;
	srand(time(NULL));
	for(int i = 0; i<tamanho;i++){
		partNumero = rand() % 10;
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

	//printf("Numero: %s\n",numero);
	//char *pnmArquivo = &nmArquivo[0];
	numero[1] = '.';
	numero[tamanho-1]= '\O';
	pnumeroIni = pNumero;
	
	char *e;
	printf("Numero 1: %s\n",numero);
	numeroFinal = strtold(pnumeroIni,&e);
	printf("Numero 2: %s\n",numero);
	return &numeroFinal;
}

int testeConversao(){
	char *string;
   char *stopstring;
   long double x;

   string = "3.1415926535898This stopped it";
   x = strtold(string, &stopstring);
   printf("string = %s\n", string);
   printf("   strtold = %.13Lf\n", x);
   printf("   Stopped scan at: %s\n\n", stopstring);

  return 0;

}
