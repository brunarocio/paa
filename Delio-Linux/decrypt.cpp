#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "decrypt.h"
#include "BigInt.h"


bool descriptografar(){
	printf("descriptografar\n");
	return 0;
}

/**
Funcao para encontrar o maximo divisor comum entre os parametros a e b
Euclides Estendido
**/
BigInt mdc(BigInt a, BigInt b)
{
    BigInt resto;

    printf("Maximo Divisor Comum\n");
    while (b != 0) {
        resto = fmodl(a,b); //divisao inteira
        a = b;
        b = resto;
    }
    return a;
}


//Implementar Pollard Rho, pg 709 Cormen
BigInt PollardRho(BigInt num){ //recebe o randomico gerado
	int i = 1, k = 2;
	BigInt x = (fmodl(rand(),(num-2)))+2;
	BigInt y = num; //armazena o valor original na primeira iteracao, nas proximas vai armazenar o calculado
	BigInt fator, res;

	printf("Pollard Rho");

    do  {
		printf("Iteracao %d\n", i);
        i++;
        res = fmodl((x * x + 1),num);
        fator = mdc((y - res), num); //calcula o fator maximo de divisao entre os numeros
        if (fator != 1 && fator != num)
        	printf("Fator %i\n", fator);
		if (i == k ){
			y = res;
			k = 2 * k;
		}
    } while (fator == 1);

	printf("Fatoracao com Pollard Rho Completa\n");
	return fator;
}

void heuristicaRho(BigInt num){
	BigInt fator;

	fator = PollardRho(num);

	printf("Fator com Rho:%i\n",fator);
}

//Calcula Fator para Forca Bruta com Fermat
BigInt calcFator(BigInt num) {

	BigInt i = num, j = 0, k = 0;

	do {
		i += j;
		k = (int) sqrt((double)i);
		j += ((!j)?1:2);
	} while (i-k*k>0);

	k += (j-1)<<1;
	num /= k;

	return (num>k?k:num);
}


/* Fatoracao de Fermat
   Se n eh primo, a-b = 1, a+b=n; */
BigInt bruteForce(BigInt num) {

	BigInt p = 1, q = 1;

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
			printf ("%i\n", p);
		else
			printf ("%i\n", num);
	} while (p > 1);

	printf("Fatoracao completa\n");
	return 0;
}

bool quebraForcaBruta(BigInt num){

	bruteForce(num);
}
