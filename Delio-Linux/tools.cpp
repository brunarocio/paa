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


long double gerarNumeroAleatorio(int tamanho){
	long double numeroFinal;
	long double *pNumeroFinal = NULL;
	pNumeroFinal = &numeroFinal;
	char numero[50];
	char *pNumero = &numero[0];
	char *pnumeroIni;
	int partNumero;
	srand(time(NULL));
	for(int i = 0; i<tamanho;i++){
		partNumero = rand() % 10;
		numero[i] = partNumero+'0';
		//printf("Numero %i: %i | ",i,partNumero);
	}
	//printf("Numero char: %s",numero);
	//printf("Ultimo numero %i\n",partNumero);
	//Verificando se o numero é par, se for, acrescenta +1
	if (partNumero%2 == 0){
		printf("Numero é par\n");
		partNumero +=1;
		numero[tamanho-1] = partNumero+'0';
	}
	numero[1] = '.';
	numero[tamanho-1]= NULL;
	pnumeroIni = pNumero;
	
	char *e = NULL;
	//Covnertendo char para long double
	numeroFinal = strtold(pnumeroIni,&e);
	printf("Valor do char: %s\nValor do Long Double: %.17Lf\n",numero,numeroFinal);
	return numeroFinal;
}

/*int testeConversao(){
	char *string;
   char *stopstring;
   long double x;

   string = "3.1415926535898This stopped it";
   x = strtold(string, &stopstring);
   printf("string = %s\n", string);
   printf("   strtold = %.13Lf\n", x);
   printf("   Stopped scan at: %s\n\n", stopstring);

  return 0;

}*/

/*int modBI(char num, int a) 
{ 
    // Initialize result 
    int res = 0; 
  
    // One by one process all digits of 'num' 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
  
    return res; 
} */
