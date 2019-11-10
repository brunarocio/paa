#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"
#include "encrypt.h"

int criptografar(long double mensagem, long double n, long double e){
	printf("criptografar\n");
	long double cryptoMensagem;
	cryptoMensagem = fmodl(pow(mensagem, (e)), n); 
	return cryptoMensagem;
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


long double gerarChavePrivada(long double p, long double q, long double e){
	printf("Gerar chave privada..\n");
	long double chavePrivada;
	chavePrivada = ((2*((p-1)*(q-1)))+1)/e;
	
	return chavePrivada;
}

int gerarE(){
	int i = 3;
	return i;
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
/* Verificar se inves de retornar true ou false, apenas soma mais um e retorna */
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
	long double a = 3; //recebe o numero gerado randomicamente
	long double prime;
	long double b, c;
	
	if (num <= 1)
		return false;  

	if (verificarParImpar(num))
		num +=1;
	
	//Teorema de Fermat para verificar primalidade
	for (i=0;i<=5;i++){ //teste um certo numero de vezes, definir quanto
		printf("NUM: %Lf\n",num);

		a = pow(a,a);
		b = num - 1;
		c = pow(a, b);
		printf("A: %Lf\n",c);
		prime = fmodl(c, num); //se o resto for 1, entao o numero eh primo, pois, esse deve ser o maximo divisor comum entre os n�meros 
		printf("Resultado prime %Lf\n",prime);
		if (trunc(prime) != 1)
			return false; //o numero nao eh primo, pois, o resultado diferente de 1 indica que se trata de um numero composto
	}

	//se chegou ao fim do laco sem sair, eh primo
	return true; //o numero eh primo
	
}