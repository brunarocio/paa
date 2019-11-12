#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "tools.h"

void gravarArquivo(char *info){
	//char filename[100];
	//filename = ('teste');
	FILE *fmat;
	fmat = fopen("arquivo.txt", "w");
	fprintf(fmat,info);
	fclose(fmat);
}

void gravarArquivoCifrado(char *info){
	//char filename[100];
	//filename = ('teste');
	FILE *fmat;
	fmat = fopen("arqcifrado.txt", "w");
	fprintf(fmat,info);
	fclose(fmat);
}

char cifraMensagem(char *mensagem){

	printf("Teste");
	return printf("mensagem cifrada com sucesso! %s\n",*mensagem);
}

char decifraMensagem(char *mensagem){

	return printf("Mensagem decifrada com sucesso!\n");
}

char codificarMensagem(){
	char *msgOriginal, *msgCifrada;
	msgOriginal = (char *)malloc(100);
	msgCifrada = (char *)malloc(100);
	char msgs[] = "495849739483948394839476";
	//char *texto = 
	char *pMsgs = &msgs[0];
	msgOriginal[0] = 'a';
	int x = msgOriginal[0];
	gravarArquivo(msgs);
	//cifraMensagem(msgs[0]);
	return printf("a :%i\n",x);
}





char codificarString(char *mensagem){
	//printf("codificando mensagem\n");
	int i = 0;
	int numAsci;
	char teste[100];
	char *testando = &teste[0];
	char strcodificada[100];
	FILE *arqCifrado;
	//arqCifrado = fopen("arqcifrado","w");
	//fputc('\0',arqCifrado);
	//fclose(arqCifrado);
	
	while(mensagem[i] != NULL){
		//testando = dicionario('i',mensagem[i]);
		//numAsci = mensagem[i]
		//printf("Mensagem: %i\n",numAsci)
		//mostrar mensagemprintf("mensagem: %c\n",mensagem[i]);
		numAsci = mensagem[i];
		//char frase[3] = (char*)numAsci;
		//mostrar codificaçãoprintf("Mensagem codificada: %i\n",numAsci);
		//char frase[] = "xxx";
		//frase[0]= numAsci + '0';
		//puts(frase);
		arqCifrado = fopen("arqcifrado","a");
		char frase[3];
		sprintf(frase,"%d",numAsci);
		//mostrarcodificaçãoprintf("teste: %s",frase);
		fputc('\n',arqCifrado);
		fputs(frase,arqCifrado);
		//fputc(numAsci,arqCifrado);
		//fputs("\n",arqCifrado);

		fclose(arqCifrado);
		//gravarArquivo(dicionario('i',mensagem[i]));
		//gravarArquivoCifrado(dicionario('i',mensagem[i]));
		//strcodificada[i*2] = 
		//fprintf(arqCifrado,teste);
		//fputc(mensagem[i],arqCifrado);
		//fputc('\n',arqCifrado);
		i++;
	}
	//printf("teste: %s",*testando);
	//printf("passou por aqui..\n");
	//fclose(arqCifrado);
	return *strcodificada;
}

char *dicionario(char opcao, char msg){
	//Haverao 2 opções inverter e reverter (inverter dará a cada caracter um número hexadecimal de 2 posições)
	//char retorno;
	char vet[] = "00";
	char *pVet = &vet[0];
	if (opcao = 'i'){
		switch (msg){
			case '1':
				printf("01\n");
				//*vet = "01";
				pVet = "01";
				return pVet;
				break;
			case '2':
				printf("02\n");
				break;
			case '3':
				printf("03\n");
				break;
			default:
				printf("99\n");
				break;
		}


	} else if (opcao = 'r'){

	}
}


long double gerarNumeroAleatorio(int tamanho){
	long double numeroFinal;
	long double *pNumeroFinal = NULL;
	pNumeroFinal = &numeroFinal;
	char numero[10];
	char *pNumero = &numero[0];
	char *pnumeroIni;
	int partNumero;
	srand(time(NULL));
	for(int i = 0; i<tamanho;i++){
		partNumero = rand() % 10;
		/*if (i == 0){
			if (partNumero < 3){
				partNumero = 3;
			}
		}*/
		numero[i] = partNumero+'0';
		//printf("Numero %i: %i | ",i,partNumero);
	}
	//printf("Numero char: %s",numero);
	//printf("Ultimo numero %i\n",partNumero);
	//Verificando se o numero é par, se for, acrescenta +1
	
	if ((partNumero%2) == 0){
	//printf("Esse é o ultimo numero..%i\n",partNumero);
	//detectar no principal se o número é par.if (partNumero%2 == 0){
		//printf("Numero é par\n");
		partNumero = partNumero +1;
		numero[tamanho-1] = partNumero+'0';
	}
	//numero[10] = '.';
	//numero[tamanho-1]= NULL;
	pnumeroIni = pNumero;
	
	char *e = NULL;
	//Covnertendo char para long double
	numeroFinal = strtold(pnumeroIni,&e);
	//printf("Valor do char:         %s\nValor do Long Double: %.Lf\n",numero,numeroFinal);
	return numeroFinal;
}

long double modpow(long double x, long double n, long double m) {

	long double u = modpow(x, n/2, m);

	if (n == 0) 
		return (fmodl(1,m));
	
	u = fmodl((u*u),m);
	if (fmodl(n,2) == 1) 
		u = fmodl((u*x),m);
	return u;
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
