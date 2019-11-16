from time import time
from random import *
import sys
import math
print(sys.getrecursionlimit())


#verificar parametros informados
param = sys.argv[1:]
if (len(param) != 2):
    print('Informa 1 parametro para prosseguir\n')
    print('Formado: main.py <operacao> <arquivo>\n')
    print('Operacoes disponiveis:\n')
    print('c = criptografar')
    print('d = descriptografar')
    sys.exit()

#definir variaveis para parametros informados
opcao = param[0]
nmArquivo = param[1]

#Verificar se o arquivo informaod existe
try:
   with open(nmArquivo, 'r') as f:
       print()
except IOError:
    print('Arquivo não encontrado!')
    sys.exit()

#funcao principal
def main():
    if (opcao == 'c'):
        criptografar()
    elif (opcao == 'd'):
        descriptografar()
    else:
        print('Escolha uma opcao valida!\n')

def criptografar():
    i = 0
    j = 0
    seed()
    p = randint(1000,2000)
    q = randint(1000,2000)
    #2**128
    #p = randint(1000000000000000000000000000000000000000,10000000000000000000000000000000000000000)
    #q = randint(1000000000000000000000000000000000000000,10000000000000000000000000000000000000000)
    #2**32#p = randint(10000000000,100000000000)
    #p = randint(10000000000,100000000000)
    #q = randint(10000000000,100000000000)
    
    #print('Numero gerado P: ',p,'\nQ: ',q,'\n')
    if ((p%2) == 0):
        p = p+1
    if ((q%2) == 0):
        q = q+1
    while (verificaPrimalidade(p)==0):
        i=i+1
        #print('2 - Tentativa ',i,'Numero ',p,' nao e primo')
        #print('.')
        p = p+2
    #print('\n')
    #print('Primeiro numero primo encontrado\n')
    while (verificaPrimalidade(q)==0):
        j=j+1
        #print('2 - Tentativa ',j,'Numero ',q,' nao e primo')
        #print('.')
        q = q+2
    print('\n')
    print('Segundo numero primo encontrado \nP: ',p,'\nQ: ',q)
    print('Definindo variaveis para criação da chave privada')
    n = p*q

    #definindo e
    PhiN = phiN(p,q)

    auxe = 32
    while (mdc(auxe,PhiN)!=1):
        #print('.. ',auxe)
        auxe+=1
    e = auxe
    #e = 3
    
    print("E: ",e)    
    #Calcular euclides estendido
    #auxd = mdc(PhiN,e)
    #print('d?: ',auxd)
    #definindo d
    x = 1
    y = 1
    #eX = euclidesExt(e,PhiN,x,y)
    eX = int(eucliedesExt2(e,PhiN,x))
    print('eX D: ',eX)
    auxd = gerarChavePrivada(p,q,n,e)
    d = round(auxd,0)
    #d = euclidesEst(PhiN,e)
    print('N: ',n)
    print('D: ',d)
    print('Cifrando o arquivo..\n')
    gerarChavePublica(n,e)
    cifrarArquivo()
    criptoArquivoCifrado(e,n)

def descriptografar():
    #decifrarArquivo()
    descriptografarArquivo()
    decifrarArquivo()

def verificaPrimalidade(num):
    a = num
    b = num-1
    #c = (a**b)
    ##print('aplicando pow\n')
    for i in range (5):
        a = a // 2
        c = pow(a,b)
        #print('C: ',c)
        primo = c%num
        #primo = pow(b,a,num)
        ##print('Primo: ',primo)
        if (primo != 1):
            return 0
    return 1

def gerarChavePublica(n,e):
    nmArquivoPublicKey = 'public.key'
    arquivoPublicKey = open(nmArquivoPublicKey,'w')
    arquivoPublicKey.write(str(n))
    arquivoPublicKey.write('\n')
    arquivoPublicKey.write(str(e))
    arquivoPublicKey.close()

def phiN(p,q):
    PhiN = (p-1)*(q-1)
    return PhiN

def gerarChavePrivada(p,q,n,e):
    PhiN = phiN(p,q)
    print('Phi de N: ',PhiN)
    #g = PhiN-1
    x = 1
    privatekey = int(eucliedesExt2(e,PhiN,x))
    nmArquivoPrivateKey = 'private.key'
    arquivoPrivateKey = open(nmArquivoPrivateKey,'w')
    arquivoPrivateKey.write(str(privatekey))
    arquivoPrivateKey.close()
    return privatekey

def calcularPhiN(p,q):
    #como calcular phi de N
    PhiN = (p-1)*(q-1)
    return PhiN

def cifrarArquivo():
    arquivo = open(nmArquivo,'r')
    nmArquivoCif = nmArquivo+'.cif'
    arquivocif = open(nmArquivoCif,'w')
    ##print(nmArquivoCif)
    for linha in arquivo:
        #print(linha)
        for caracter in linha:
            ##print(ord(caracter))  
            arquivocif.write(str(ord(caracter)))
            arquivocif.write('\n')  
    arquivocif.close()

def criptoArquivoCifrado(e,n):
    nmArquivoCif = nmArquivo+'.cif'
    arquivoCif = open(nmArquivoCif,'r')
    nmArquivoCrypto = nmArquivo+'.crypto'
    arquivoCrypto = open(nmArquivoCrypto,'w')
    ##print(nmArquivoCrypto)
    for linha in arquivoCif:
        valorCrypto = int(linha)
        ##print(valorCrypto)
        ##print((valorCrypto**e)%n)
        arquivoCrypto.write(str((valorCrypto**e)%n))
        arquivoCrypto.write('\n')
    arquivoCrypto.close()

def decifrarArquivo():
    arquivo = open(nmArquivo+'.decrypto','r')
    nmArquivoDeCif = nmArquivo+'.orig'
    arquivoDecif = open(nmArquivoDeCif,'w')
    print(nmArquivo)
    for linha in arquivo:
        print(linha)
        print(chr(int(linha)))  
        arquivoDecif.write(chr(int(linha)))
    arquivoDecif.close()

def getChavePublica():
    arquivoPublicKey = open('public.key','r')
    key = arquivoPublicKey.readlines()
    arquivoPublicKey.close()
    return key

def getChavePrivada():
    arquivoPrivateKey = open('private.key','r')
    key = arquivoPrivateKey.readlines()
    arquivoPrivateKey.close()
    return key[0]

def descriptografarArquivo():
    nmArquivoCrypto = nmArquivo
    nmArquivoDecrypto = nmArquivo+'.decrypto'
    arquivoCrypto = open(nmArquivoCrypto,'r')
    arquivoDecrypto = open(nmArquivoDecrypto,'w')
    publicKey = getChavePublica()
    n = int(publicKey[0])
    e = int(publicKey[1])
    d = int(getChavePrivada())

    for linha in arquivoCrypto:
        print('Valor n: ')
        print(n)
        print('Valor e: ')
        print(e)
        print('Valor d: ')
        print(d)
        valorCrypto = int(linha)
        print("valor linha: ")
        print(valorCrypto)
        #print(math.pow(valorCrypto,(d-0.5)))
        #print(1367631 ** 2174328) % n
        print('valor descriptografado: ',pow(valorCrypto,d,n))
        #valorDecrypto = (valorCrypto**d)%n
        valorDecrypto = pow(valorCrypto,d,n)
        #print(pow(valorCrypto,d))
        arquivoDecrypto.write(str(valorDecrypto))
        arquivoDecrypto.write('\n')
    arquivoDecrypto.close()

def mdc(a,b):
    #resto = 1
    #maximo divisor comum
    while (b!=0):
        resto = a%b
        a = b
        b = resto
    return a
def eucliedesExt2(a,b,c):
    r = b % a
    if r == 0:
        return ( (c / a) % ( b / a) )
    
    return ( ( eucliedesExt2(r, a, -c) * b + c) / (a % b) )

def euclidesExt(p,q,x,y):
    if p==0:
        x = 0
        y = 1
        return q
    x1 = 1
    y1 = 1
    ##print("recursao1")
    eucExt = euclidesExt(q%p,p,x1,y1)
    x = y1 - (q/p) * x1
    y = x1
    return eucExt

def euclidesEst(e,PhiN):
    vetor = [0,0,0]
    d = 0
    x = 0
    y = 0
    a = PhiN
    b = e
    if (b == 0):
        vetor[0] = a
        vetor[1] = 1
        vetor[2] = 0
        return vetor
    vetor = euclidesEst(b,a%b)
    d = vetor[0]
    x = vetor[1]
    y = vetor[2]
    vetor[0] =d
    vetor[1] = y
    vetor[2] = (x-(a/b)*y)
    
    d = vetor[1]
    return vetor

main()
