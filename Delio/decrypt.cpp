#include <stdio.h>
#include <stdlib.h>
#include "decrypt.h"

bool descriptografar(){
	printf("descriptografar\n");
	return 0;
}

/**
Função para encontrar o mínimo divisor comum entre os parâmetros a e b
**/
long double mdc(long double a, long double b) 
{
    long double resto;
    while (b != 0) {
        resto = a % b; //divisão inteira
        a = b;
        b = resto;
    }
    return a;
}


//Implementar Pollard Rho, pg 709 Cormen
bool quebraForcaBruta(long double num){ //recebe o randomico gerado
	int i = 1, k = 2;
	long double x = fmodl(num,2); //tem que começar a testar de algum lugar, ver qual o melhor inicio
	long double y = num; //armazena o valor original na primeira iteração, nas próximas vai armazenar o calculado
	long double fator, res; 

    do {
        i++;
        res = fmodl((x * x + 1),num);
        fator = mcd((y - res), num); //calcula o fator mínimo de divisão entre os numeros
        if (fator != 1 && fator != num)
        	printf("Fator %d", %d)
		if (i == k ){
			y = res;
			k = 2 * k;
		}
       
    } while (fator == 1);
	
}
