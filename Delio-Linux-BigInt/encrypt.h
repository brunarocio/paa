#include <stdio.h>
#include <stdlib.h>
using namespace std;

int criptografar();

long double gerarChavePublica(long double p, long double q);

long double gerarChavePrivada(long double p, long double q, int e);

int gerarE();

bool verificaPrimalidade(long double num);


bool verificarParImpar(long double num);