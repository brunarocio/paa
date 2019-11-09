#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "tools.h"
#include "encrypt.h"
#include "decrypt.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//comando programa -c 'arquivo a ser encriptado' (ser� gerado o arquivo a ser encriptado )
//comando programa -d 'arquivo a ser decriptado' (ser� gerado o arquivo a ser decriptado)

int main(int argc, char *argv[]) {
	long double num1, num2, chavep;
	//numero = &numero2;
	int i,j = 0;
	if (argc != 2){
		printf ("ERRO: Numero de parametros %s <d ou c> <arquivo>\n", argv[0]);
		exit (1);
	}
	//char opcao = *(argv[1]);
	if (strcmp(argv[1],"c")==0){
		//op?oes para criptografia
		printf("======== Op??o criptografar =========\n");
		printf("Passo 1 - Gerando a chave\n");
		//Gerando numero aleat�rio e atribuindo a uma variavel
		printf("1.1-Gerando numero aleatório..\n");
		num1 = gerarNumeroAleatorio(55);
		
		printf("Numero gerado: %Lf\n",num1);
		//Verifica primalidade
		printf("1.2-Verificando primalidade do número..\n");
		while (!(verificaPrimalidade(num1))){
			num1 = gerarNumeroAleatorio(55);
			printf("1 - Tentativa %i: Numero %.19Lf não é primo\n",i,num1);
			sleep(1);
			i++;
		}
		printf("Encontrado primeiro numero primo..%.17Lf\n",num1);
		num2 = gerarNumeroAleatorio(55);
		while (!(verificaPrimalidade(num2))){
			num2 = gerarNumeroAleatorio(55);
			printf("2 - Tentativa %i: Numero %.19Lf não é primo\n",j,num1);
			sleep(1);
			j++;
		}
		printf("Encontrado segundo numero primo..%.17Lf\n",num2);
		chavep = gerarChavePublica(num1,num2);
		printf("Numero primo 1: %.17Lf\nNumero primo 2: %.17Lf\n",num1,num2);
		printf("Chave publica: %.20Lf\n",chavep);
		gerarChavePrivada();

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
		quebraForcaBruta(chavep);
		printf("Quebrando a chave utilizando o algoritmo Pollard Rho\n");
		PollardRho(chavep);
	}
	else {
		printf("ERRO: Opcao %s nao definida.\nOpcoes disponiveis:\nd: para descriptografar\nc: para criptografar <arquivo>\nComando completo: CryptoRSA <opcao> <arquivo>\n", argv[1]);
		return 0;
	}
	
	return 0;
}

