from random import *

def main():
    i = 0
    j = 0
    teste = 2**32
    #print('2 na 128 ',teste)
    seed()
    #2**128p = randint(1000000000000000000000000000000000000000,10000000000000000000000000000000000000000)
    #2**32p = randint(10000000000,100000000000)
    p = randint(1000,2000)
    q = randint(1000,2000)
    #p = randint(10000000000,100000000000)
    #q = randint(10000000000,100000000000)
    
    print('Numero gerado P: ',p,'\nQ: ',q,'\n')
    if ((p%2) == 0):
        p = p+1
    if ((q%2) == 0):
        q = q+1
    while (verificaPrimalidade(p)==0):
        i=i+1
        print('2 - Tentativa ',i,'Numero ',p,' nao e primo')
        p = p+2
    print('Primeiro numero primo encontrado')
    while not (verificaPrimalidade(q)==0):
        j=j+1
        print('2 - Tentativa ',j,'Numero ',q,' nao e primo')
        q = q+2
    print('Segundo numero primo encontrado \nP: ',p,'\nQ: ',q)

def verificaPrimalidade(num):
    a = 3
    b = num-1
    c = (a**b)
    print('C: ',c)
    primo = c%num
    #primo = pow(b,a,num)
    print('Primo: ',primo)
    if (primo != 1):
        return 0
    return 1
    

main()
