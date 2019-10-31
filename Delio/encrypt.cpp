#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"
#include "encrypt.h"

bool criptografar(){
	printf("criptografar\nNão implementado\n");
	return true;
}

int gerarChavePublica(){
	printf("Gerar chave publica\nNão implementado\n");
}

int gerarChavePrivada(){
	printf("Gerar chave privada\nNão implementado\n");
}

int gerarChave(){
	printf("Gerar chave");
	long double *numBig_1;
	numBig_1 = gerarNumeroAleatorio(100);
	printf("O numero � %c",numBig_1);
	
	for (int i = 0; i < 2; i++){
		
		long double limIni = pow(10,101);
		long double teste;
		//long double numRand = ((long double)rand() % limIni);
		printf("Tamanho %d",sizeof(teste));		
		//printf("numero %Lf\n", pow(10,100) + numRand);
	}
	return 0;
}

bool verificaPrimalidade(int num){
	
}

bool verificarParImpar(){
	
}
