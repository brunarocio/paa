#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "tools.h"
#include "encrypt.h"
#include "decrypt.h"
#include "BigInt.hpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//comando programa -c 'arquivo a ser encriptado' (ser� gerado o arquivo a ser encriptado )
//comando programa -d 'arquivo a ser decriptado' (ser� gerado o arquivo a ser decriptado)

bool verificaPrimalidadeBI(BigInt num){
	bool bPrimo;
	BigInt c,a,b,prime;
	a = 3;
	b = num-1;
	std::cout << "A: " << a << "\n";
	std::cout << "B: " << b << "\n";
		
	if (num <= 1)
		return false;  

	//if (verificarParImpar(num))
	//	num +=1;
	
	//Teorema de Fermat para verificar primalidade
	for (int i=0;i<=5;i++){ //teste um certo numero de vezes, definir quanto
		//c = pow(a,10);
		//std::cout << "Bpow: " << b << "\n";
		//prime = c % num;
		//std::cout << "Prime: " << prime << "\n";

		/*int_c = pow(int_a,int_b);
		printf("Numero gerado potencia: %li\n",int_c);
		int_prime = fmodl(int_c,int_num);
		printf("Numero primo: %li\n",int_prime);
		int_c = pow(int_a,int_b);
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
		if (trunc(int_prime) != 1)
			return false;*/
	}

	//se chegou ao fim do laco sem sair, eh primo
	return true; //o numero eh primo
	
}

int main(int argc, char *argv[]) {
	long double num1, num2, chavep;
	//numero = &numero2;
	int i = 0;
	int j = 0;
	int k = 0;
	long double n,e,d;
	char mensagem[100];
	char msgCifrada[200];
	FILE *file;
	FILE *arqCifrado;
	FILE *arqPrivateKey;
	FILE *arqPublicKey;
	if (argc != 3){
		printf ("ERRO: Numero de parametros %s <d ou c> <arquivo>\n", argv[0]);
		exit (1);
	}
	//char opcao = *(argv[1]);
			
		//Leitura arquivo
		
	if (strcmp(argv[1],"c")==0){
		BigInt p,q,n;
		//opcoes para criptografia
		printf("======== Opcao criptografar =========\n");
		sleep(1);
		printf("Passo 1 - Gerar a chave\n");
		sleep(1);
		//Gerando numero aleat�rio e atribuindo a uma variavel
		printf("1.1-Gerando o primeiro numero aleatório..\n");
		p = big_random(50);
		sleep(1);
		std::cout << "P: " << p << "\n";
		printf("1.2-Gerando o segundo numero aleatório..\n");
		q = big_random(50);
		sleep(1);
		std::cout << "Q: " << q << "\n";
		printf("1.3-Gerando N..\n");
		n = p*q;
		sleep(1);
		std::cout << "N: " << n << "\n";
		if ((p%2)!=1){
			p = p+1;
		}
		if ((q%2)!=1){
			p = p+1;
		}		
		//Verifica primalidade
		printf("1.2-Verificando primalidade do número..\n");
		while (!(verificaPrimalidadeBI(p))){
			printf("1 - Tentativa %i: Numero %.Lf não é primo\n",i,num1);
			sleep(1);
			num1 = num1+2;		
			//num1 = gerarNumeroAleatorio(55);
			//sleep(1);
			i++;
		}
		printf("Encontrado primeiro numero primo..%.17Lf\n",num1);
		num2 = gerarNumeroAleatorio(1);
		while (!(verificaPrimalidade(num2))){
			printf("2 - Tentativa %i: Numero %.Lf não é primo\n",j,num2);
			num2 = gerarNumeroAleatorio(55);
			sleep(1);
			j++;
		}
		printf("Encontrado segundo numero primo..%.Lf\n",num2);
		
		//Gerar chave publica e privada.
		n = gerarChavePublica(num1,num2);
		//Incluir chave publica em uma arquivo;
		arqPublicKey = fopen("public.key","w");
		fclose(arqPublicKey);
		e = gerarE();
		d = gerarChavePrivada(num1,num2,e);
		arqPrivateKey = fopen("private.key","w");

		fclose(arqPrivateKey);
		//Cifrar arquivo para, em seguida, criptografar
		file = fopen(argv[2], "r");
		if (file == NULL){
			printf("Arquivo não foi encontrado!\n");
			return 0;
		}
		while (fgets(mensagem,100,file) != NULL){
			printf("%s",mensagem);
			codificarString(mensagem);
			k++;
			
		}
		//printf("Mensagem cifrada: %s",msgCifrada);
		//fscanf(file,);
		fclose(file);
		
		//long double gerarChavePublica(num1,)


		//inserir leitura do arquivo aquiprintf()

		printf("Numero primo 1: %.17Lf\nNumero primo 2: %.17Lf\n",num1,num2);
		printf("Chave publica: %.20Lf\n",chavep);


		printf("Passo 2 - Criptografando o arquivo\n");
		printf("=====================================\n");
		int chave = 1;	//gerarChave();
		printf("chave: %i",chave);
		char informacao[] = "Progrma em andamento.....";
		char *pInformacao;
		pInformacao = &informacao[0];
		printf("Gravando arquivo...\n");
		gravarArquivo(pInformacao);
		printf("Arquivo gravado com sucesso!\n");
		printf("Gerando numero primo da ordem 10^100\n");
		printf("Verificando se o numero eh primo ou nao\n");
		printf("Criptografando arquivo..\n");
		
	}
	else if (strcmp(argv[1],"d")==0){
		//opcoes para descriptografia
		printf("Opcao descriptografar\n");
		descriptografar();
		printf("Tentando quebrar a chave por forca bruta..\n");
		///quebraForcaBruta(chavep);
		printf("Quebrando a chave utilizando o algoritmo Pollard Rho\n");
		//PollardRho(chavep);
	}
	else if (strcmp(argv[1],"t")==0){
		codificarMensagem();
	}
	else if (strcmp(argv[1],"b")==0){
		printf("Teste bing int\n");
		//BigInt big1 = 3, big2;
		//big2 = "231254548748541561451484751451515";
		//big2 = big_random(5);
		//std::cout << big1 * big2 * 1 << "\n";
		//std::cout << big2 * 1 << "\n";
		//printf("Big: %i",big2);

	}
	else {
		printf("ERRO: Opcao %s nao definida.\nOpcoes disponiveis:\nd: para descriptografar\nc: para criptografar <arquivo>\nComando completo: CryptoRSA <opcao> <arquivo>\n", argv[1]);
		return 0;
	}
	
	return 0;
}



