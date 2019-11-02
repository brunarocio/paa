#include <iostream>
#include <string.h>
#include "tools.h"
#include "encrypt.h"
#include "decrypt.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	gerarChave();
	char informacao[] = "Progrma em andamento....";
	char *pInformacao;
	pInformacao = &informacao[0];
	printf("Gravando arquivo...\n");
	gravarArquivo(pInformacao);
	printf("Arquivo gravado com sucesso!\n");
	return 0;
}
