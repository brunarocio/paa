#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "decrypt.h"


bool descriptografar(){
	printf("descriptografar\n");
	return 0;
}

/**
Funcao para encontrar o maximo divisor comum entre os parametros a e b
Euclides Estendido
**/
long double mdc(long double a, long double b)
{
    long double resto;

    printf("Maximo Divisor Comum\n");
    while (b != 0) {
        resto = fmodl(a,b); //divisao inteira
        a = b;
        b = resto;
    }
    return a;
}


//Implementar Pollard Rho, pg 709 Cormen
long double PollardRho(long double num){ //recebe o randomico gerado
	int i = 1, k = 2;
	long double x = (fmodl(rand(),(num-2)))+2;
	long double y = num; //armazena o valor original na primeira iteracao, nas proximas vai armazenar o calculado
	long double fator, res;

	printf("Pollard Rho");

    do  {
		printf("Iteracao %d\n", i);
        i++;
        res = fmodl((x * x + 1),num);
        fator = mdc((y - res), num); //calcula o fator maximo de divisao entre os numeros
        if (fator != 1 && fator != num)
        	printf("Fator %lf\n", fator);
		if (i == k ){
			y = res;
			k = 2 * k;
		}
    } while (fator == 1);

	printf("Fatoracao com Pollard Rho Completa\n");
	return fator;
}

//Calcula Fator para Forca Bruta com Fermat
long double calcFator(long double num) {

	long double i = num, j = 0, k = 0;

	do {
		i += j;
		k = (int) sqrt((double)i);
		j += ((!j)?1:2);
	} while (i-k*k>0);

	k += j;
	num /= k;

	return (num>k?k:num);
}


/* Fatoracao de Fermat
   Se n eh primo, a-b = 1, a+b=n; */
long double quebraForcaBruta(long double num) {

	long double p = 1, q = 1;

	printf("Tentando quebrar com metodo de Fermat\n");
	do {
		p = calcFator (num);

		do {	// este loop usa o fator encontrado anteriormente e se
			    // assegura de que ele seja o menor
			q = calcFator (p);
			p /= q;
		} while (q > 1);
		num /= p;

		if (p != 1)
			printf ("%lf\n", p);
		else
			printf ("%lf\n", num);
	} while (p > 1);

	printf("Fatoracao completa\n");
	return 0;
}

/*int main(){

    quebraForcaBruta(98764321234);

    Return 0;
}*/

