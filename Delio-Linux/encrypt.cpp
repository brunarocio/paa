#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"
#include "encrypt.h"

int criptografar(){
	printf("criptografar\n");
	return 0;
}

long double gerarChavePublica(long double p, long double q){
	printf("Gerar chave publica..\n");
	long double n;
	n = (p * q);
	return n;
	
}

void cifrarMensagem(char *mensagem){
	//while(mensagem != '\0')`{

	//}
}

void gerarChavePrivada(){
	printf("Gerar chave privada..\n");
}

/*int gerarChave(){
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
	return 1;
}*/

/* Um dos otimizadores do teste de primalidade � checar se o n�mero � par */
/* Verificar se inv�s de retornar true ou false, apenas soma mais um e retorna */
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
	int i;
	long double a = num; //recebe o numero gerado randomicamente
	long double prime;
	
	if (num <= 1)
		return true;  
	
	bPrimo = verificarParImpar(num);
	if(bPrimo)
		return false; //n�o � primo
	else{
		//Teorema de Fermat para verificar primalidade
		for (i=0;i<=30;i++){ //teste um certo numero de vezes, definir quanto
			a = a / 2; //usa a metade do numero gerado
			prime = fmodl(pow(a, (num-1)),  num); //se o resto for 1, entao o n�mero � primo, pois, esse deve ser o maximo divisor comum entre os n�meros 
			
			if (prime != 1)
				return false; //o n�mero n�o � primo, pois, o resultado diferente de 1 indica que se trata de um n�mero composto
		}
	
		//se chegou ao fim do la�o sem sair, � primo
		return true; //o n�mero � primo
	}	
}
