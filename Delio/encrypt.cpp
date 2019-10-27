#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "encrypt.h"

int criptografar(){
	printf("criptografar");
	return 0;
}

int gerarChave(){
	for (int i = 0; i < 2; i++){
		long double limIni = pow(10,101);
		long double numRand = ((long double)rand() % limIni);
		printf("Tamanho %d",sizeof(numRand));		
		printf("numero %Lf\n", pow(10,100) + numRand);
	}
	return 0;
}

bool verificaPrimalidade(int num){
	
}

bool verificarParImpar(){
	
}
