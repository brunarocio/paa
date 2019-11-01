#include <iostream>
#include <string.h>
#include "tools.h"
#include "encrypt.h"
#include "decrypt.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//comando programa -c 'arquivo a ser encriptado' (serÃ¡ gerado o arquivo a ser encriptado )
//comando programa -d 'arquivo a ser decriptado' (serÃ¡ gerado o arquivo a ser decriptado)

int main(int argc, char *argv[]) {
	if (argc != 2){
		printf ("ERRO: Numero de parametros %s <d ou c> <arquivo>\n", argv[0]);
		exit (1);
	}
	//char opcao = *(argv[1]);
	if (strcmp(argv[1],"c")==0){
		//opçoes para criptografia
		printf("Opção criptografar\n");
		gerarChave();
		char informacao[] = "Progrma em andamento.....";
		char *pInformacao;
		pInformacao = &informacao[0];
		printf("Gravando arquivo...\n");
		gravarArquivo(pInformacao);
		printf("Arquivo gravado com sucesso!\n");
		printf("Gerando numero primo da ordem 10^100\n");
		printf("Verificando se o numero Ã© primo ou nÃ£o\n");
		printf("Criptografando arquivo..\n");
		
	}
	else if (strcmp(argv[1],"d")==0){
		//opcoes para descriptografia
		printf("Opção descriptografar\n");
		printf("Tentando quebrar a chave por forÃ§a bruta..\n");
		printf("Quebrando a chave utiliznado o algoritmo xxx\n");
	}
	else {
		printf("ERRO: Opção %s não definida.\nOpções disponíveis:\nd: para descriptografar\nc: para criptografar <arquivo>\nComando completo: CryptoRSA <opcao> <arquivo>\n", argv[1]);
		return 0;
	}
	
	return 0;
}
