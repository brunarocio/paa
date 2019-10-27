#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "encrypt.h"

//aula sobre fermat -> https://pt.khanacademy.org/computing/computer-science/cryptography/random-algorithms-probability/v/fermat-primality-test-prime-adventure-part-10
//
int criptografar(){
	printf("criptografar");
	return 0;
}

int gerarChave(){
	for (int i = 0; i < 2; i++){
		long double limIni = pow(10,101);
		long double numRand = fmodl((long double)rand(), limIni);
		printf("Tamanho %d",sizeof(numRand));		
		printf("numero %Lf\n", pow(10,100) + numRand);
	}
	return 0;
}

/* Um dos otimizadores do teste de primalidade � checar se o n�mero � par */
bool verificarParImpar(int num){
	int r = 0;
	
	if (num > 2)
	{
		r = num % 2;
		if(r = 0)
			return false;
		return true;
	}
	else
		return false;
	
}

bool verificaPrimalidade(int num){
	bool bPrimo;
	int a = 3;
	int prime;
	
	if (num <= 1)
		return true;
	
	bPrimo = verificarParImpar(num);
	if(bPrimo)
		return false; //n�o � primo
	else{
		//Teorema de Fermat para verificar primalidade
		
		prime = (a ^ (num-1)) % num; //se o resto for 1, entao o n�mero � primo, pois, esse deve ser o maximo divisor comum entre os n�meros 
		if (prime = 1)
			return true; //o n�mero � primo
		return false; //o n�mero n�o � primo, pois, o resultado diferente de 1 indica que se trata de um n�mero composto
	}	
}






