#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"
#include "encrypt.h"
#include "BigInt.hpp"

long double criptografar(long double mensagem, long double n, long double e){
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


long double gerarChavePrivada(long double p, long double q, int e){
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
bool verificarParImpar(BigInt num){
	BigInt r = 0;

	if (num > 2)
	{
		r = num%2;
		if(r == 0)
			return false;
		return true;
	}
	else
		return false;

}

bool verificaPrimalidade(BigInt num){
	bool bPrimo;
	int i;
	BigInt a = num; //recebe o numero gerado randomicamente
	BigInt prime;
	BigInt b, c;
	BigInt int_num = num;
	unsigned const long int_a = a.to_long(); //Tem fazer cast porque a função pow só aceita const long no primeiro e int no segundo parametro
	int int_b = num.to_int()-1; //Estamos com problema, pois o overload do pow espera um const long e um int
	BigInt int_c=0;
	BigInt int_prime = prime;
	printf("Valor de\nA:%i\nB:%i\nC:%i\nPrime:%i\n",int_a,int_b,int_c,int_prime);

	if (num <= 1)
		return false;

	//Teorema de Fermat para verificar primalidade
	for (i=0;i<=5;i++){ //teste um certo numero de vezes, definir quanto
		int_c = pow(int_a,int_b);
		printf("Numero gerado potencia: %i\n",int_c);
		int_prime = int_c%int_num;
		printf("Numero primo: %i\n",int_prime);
		/*printf("NUM: %Lf\n",num);
		int_c = pow(int_a,int_b);
		printf("Valor de\nA:%Li\nB:%Li\nC:%i\nNum: %Li\nPrime:%Li\n",int_a,int_b,int_c,int_num,int_prime);

		a = pow(a,a);
		b = num - 1;
		c = pow(a, b);
		printf("A: %Lf\n",c);
		prime = fmodl(c, num); //se o resto for 1, entao o numero eh primo, pois, esse deve ser o maximo divisor comum entre os n�meros
		int_prime = fmodl(int_c,int_num);
		printf("numero intprime? %i",int_prime);
		printf("Valor de\nA:%Li\nB:%Li\nC:%i\nNum: %Li\nPrime:%Li\n",int_a,int_b,int_c,int_num,int_prime);
		printf("Resultado de %i",int_c);
		printf("Resultado prime de Int: %i\n",int_prime);
		printf("Resultado prime %Lf\n",prime);
		if (trunc(int_prime) != 1)
			return false; //o numero nao eh primo, pois, o resultado diferente de 1 indica que se trata de um numero composto
		*/
		if (int_prime != 1) //Não há trunc ao trabalhar com big int
			return false;
	}

	//se chegou ao fim do laco sem sair, eh primo
	return true; //o numero eh primo

}
