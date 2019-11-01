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
	if (argv[1] == "c"){
		printf("Opção criptografar\n");
	}
	else if (argv[1] == "1"){
		printf("Opção descriptografar\n");
	}
	else {
		printf("Escolha uma das opções validas\n%s",argv[1]);
	}
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
	printf("Tentando quebrar a chave por forÃ§a bruta..\n");
	printf("Quebrando a chave utiliznado o algoritmo xxx\n");
	return 0;
}
