#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "decrypt.h"

bool descriptografar(){
	printf("descriptografar\n");
	return 0;
}

/**
Fun��o para encontrar o m�nimo divisor comum entre os par�metros a e b
**/
long double mdc(long double a, long double b) 
{
    long double resto;
    
    while (b != 0) {
        resto = fmodl(a,b); //divis�o inteira
        a = b;
        b = resto;
    }
    return a;
}


//Implementar Pollard Rho, pg 709 Cormen
long double PollardRho(long double num){ //recebe o randomico gerado
	int i = 1, k = 2;
	long double x = fmodl(num,2); //tem que come�ar a testar de algum lugar, ver qual o melhor inicio
	long double y = num; //armazena o valor original na primeira itera��o, nas pr�ximas vai armazenar o calculado
	long double fator, res; 

    while (fator == 1) {
        i++;
        res = fmodl((x * x + 1),num);
        fator = mdc((y - res), num); //calcula o fator m�nimo de divis�o entre os numeros
        if (fator != 1 && fator != num)
        	printf("Fator %d", fator);
		if (i == k ){
			y = res;
			k = 2 * k;
		} 
    } 
	return fator;
}

long double quebraForcaBruta(long double num){
	long double chave;
	
	chave = PollardRho(num);
	
	return chave;
	
}
