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

/* Um dos otimizadores do teste de primalidade é checar se o número é par */
bool verificarParImpar(long double num){
	long double r = 0;
	
	if (num > 2)
	{
		r = fmodl(num, 2);
		if(r = 0)
			return false;
		return true;
	}
	else
		return false;
	
}

bool verificaPrimalidade(long double num){
	bool bPrimo;
	long double a = 3; //usar a função de gerador de randômicos para gerar uma lista de possíveis números para testes
	long double prime;
	
	if (num <= 1)
		return true;  
	
	bPrimo = verificarParImpar(num);
	if(bPrimo)
		return false; //não é primo
	else{
		//Teorema de Fermat para verificar primalidade
		
		prime = fmodl(pow(a, (num-1)),  num); //se o resto for 1, entao o número é primo, pois, esse deve ser o maximo divisor comum entre os números 
		if (prime = 1)
			return true; //o número é primo
		return false; //o número não é primo, pois, o resultado diferente de 1 indica que se trata de um número composto
	}	
}






