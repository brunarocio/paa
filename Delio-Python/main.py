from random import *
import sys
param = sys.argv[1:]
if (len(param) != 1):
    print('Informa 1 parametro para prosseguir')
    sys.exit()
nmArquivo = param[0]
try:
   with open(nmArquivo, 'r') as f:
       print()
except IOError:
    print('Arquivo não encontrado!')
    sys.exit()

def main():
    i = 0
    j = 0
    seed()
    p = randint(1000,2000)
    q = randint(1000,2000)
    #2**128p = randint(1000000000000000000000000000000000000000,10000000000000000000000000000000000000000)
    #2**32#p = randint(10000000000,100000000000)
    
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
    print('Definindo variaveis para criação da chave privada')
    n = p*q
    e = 3
    d = gerarD(p,q,n,e)
    print('D: ',d)
    print('Cifrando o arquivo..\n')
    cifrarArquivo()
    decifrarArquivo("arquivo.cif")


def verificaPrimalidade(num):
    a = 3
    b = num-1
    c = (a**b)
    #print('C: ',c)
    primo = c%num
    #primo = pow(b,a,num)
    print('Primo: ',primo)
    if (primo != 1):
        return 0
    return 1

def gerarChavePublica():
    return 1

def gerarD(p,q,n,e):
    PhiN = (p-1)*(q-1)
    privatekey = ((2*(PhiN)) + 1)/2
    return privatekey

def calcularPhiN(p,q):
    #como calcular phi de N
    PhiN = (p-1)*(q-1)
    return PhiN

def cifrarArquivo():
    #nmArquivo = param[0]
    arquivo = open(nmArquivo,'r')
    nmArquivoCif = nmArquivo+'.cif'
    arquivocif = open(nmArquivoCif,'w')
    print(nmArquivoCif)
    for linha in arquivo:
        print(linha)
        for caracter in linha:
            print(ord(caracter))  
            arquivocif.write(str(ord(caracter)))
            arquivocif.write('\n')  
    arquivocif.close()

def decifrarArquivo(nmArquivo):
    arquivo = open(nmArquivo,'r')
    nmArquivoDeCif = nmArquivo+'.orig'
    arquivoDecif = open(nmArquivoDeCif,'w')
    print(nmArquivo)
    for linha in arquivo:
        print(linha)
        print(chr(int(linha)))  
        arquivoDecif.write(chr(int(linha)))
    arquivoDecif.close()

main()
