#include <iostream>
#include <string.h>
#include "tools.h"
#include "encrypt.h"
#include "decrypt.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//comando programa -c 'arquivo a ser encriptado' (será gerado o arquivo a ser encriptado )
//comando programa -d 'arquivo a ser decriptado' (será gerado o arquivo a ser decriptado)

int main(int argc, char *argv[]) {
	long double *numero;
	if (argc != 2){
		printf ("ERRO: Numero de parametros %s <d ou c> <arquivo>\n", argv[0]);
		exit (1);
	}
	//char opcao = *(argv[1]);
	if (strcmp(argv[1],"c")==0){
		//op?oes para criptografia
		printf("======== Op??o criptografar =========\n");
		printf("Passo 1 - Gerando a chave\n");
		//gerando numero aleatório e atribuindo a uma variavel
		testeConversao();
		numero = gerarNumeroAleatorio(100);
		printf("passou daqui..\n");
		if (verificaPrimalidade(*numero)){
			printf("numero é primo");
		} else{
			printf("Numero não é primo");
		}
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
		printf("Verificando se o numero é primo ou não\n");
		printf("Criptografando arquivo..\n");
		
	}
	else if (strcmp(argv[1],"d")==0){
		//opcoes para descriptografia
		printf("Op??o descriptografar\n");
		printf("Tentando quebrar a chave por força bruta..\n");
		printf("Quebrando a chave utiliznado o algoritmo xxx\n");
	}
	else {
		printf("ERRO: Op??o %s n?o definida.\nOp??es dispon?veis:\nd: para descriptografar\nc: para criptografar <arquivo>\nComando completo: CryptoRSA <opcao> <arquivo>\n", argv[1]);
		return 0;
	}
	
	return 0;
}

