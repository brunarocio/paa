#include <stdio.h>
#include <stdlib.h>

int criptografar();

long double gerarChavePublica(long double p, long double q);

long double gerarChavePrivada(long double p, long double q, int e);

int gerarE();

bool verificaPrimalidade(long double num);

bool verificaPrimalidadeBI(int num);

bool verificarParImpar(long double num);
