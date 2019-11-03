#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "decrypt.h"

bool descriptografar(){
	printf("descriptografar\n");
	return 0;
}

/**
Funcao para encontrar o m�nimo divisor comum entre os par�metros a e b
**/
long double mdc(long double a, long double b) 
{
    long double resto;
    
    printf("Minimo Divisor Comum\n");
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
	//long double x = 23478629; //tem que come�ar a testar de algum lugar, ver qual o melhor inicio
	long double x = (fmodl(rand(),(num-2)))+2;
	long double y = num; //armazena o valor original na primeira itera��o, nas pr�ximas vai armazenar o calculado
	long double fator, res; 

	printf("Pollard Rho");

    do  {
		printf("Iteracao %i\n", i);
        i++;
        res = fmodl((x * x + 1),num);
        fator = mdc((y - res), num); //calcula o fator m�nimo de divis�o entre os numeros
        if (fator != 1 && fator != num)
        	printf("Fator %ld\n", fator);
		if (i == k ){
			y = res;
			k = 2 * k;
		} 
    } while (fator == 1);
	return fator;
}

long double quebraForcaBruta(long double num){
	long double chave;
	
	chave = PollardRho(num);
	
	return chave;
}
