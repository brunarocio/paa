#include <iostream>
#include <string.h>
#include "tools.h"
#include "encrypt.h"
#include "decrypt.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	gerarChave();
	char informacao[] = "Progrma em andamento.....";
	char *pInformacao;
	pInformacao = &informacao[0];
	printf("Gravando arquivo...\n");
	gravarArquivo(pInformacao);
	printf("Arquivo gravado com sucesso!\n");
	printf("Gerando numero primo da ordem 10^100\n");
	printf("Verificando se o numero é primo ou não\n");
	printf("Criptografando arquivo..\n");
	printf("Tentando quebrar a chave por força bruta..\n");
	pritnf("Quebrando a chave utiliznado o algoritmo xxx\n");
	return 0;
}
