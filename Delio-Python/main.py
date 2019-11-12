from random import *
import sys

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
    d = gerarChavePrivada(p,q,n,e)
    print('D: ',d)
    print('Cifrando o arquivo..\n')
    gerarChavePublica(n,e)
    cifrarArquivo()
    criptoArquivoCifrado(e,n)

def descriptografar():
    decifrarArquivo()
    descriptografarArquivo()

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

def gerarChavePublica(n,e):
    nmArquivoPublicKey = 'public.key'
    arquivoPublicKey = open(nmArquivoPublicKey,'w')
    arquivoPublicKey.write(str(n))
    arquivoPublicKey.write('\n')
    arquivoPublicKey.write(str(e))
    arquivoPublicKey.close()

def gerarChavePrivada(p,q,n,e):
    PhiN = (p-1)*(q-1)
    privatekey = ((2*(PhiN)) + 1)/2
    nmArquivoPrivateKey = 'private.key'
    arquivoPrivateKey = open(nmArquivoPrivateKey,'w')
    arquivoPrivateKey.write(str(privatekey))
    arquivoPrivateKey.close()

def calcularPhiN(p,q):
    #como calcular phi de N
    PhiN = (p-1)*(q-1)
    return PhiN

def cifrarArquivo():
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

def criptoArquivoCifrado(e,n):
    nmArquivoCif = nmArquivo+'.cif'
    arquivoCif = open(nmArquivoCif,'r')
    nmArquivoCrypto = nmArquivo+'.crypto'
    arquivoCrypto = open(nmArquivoCrypto,'w')
    print(nmArquivoCrypto)
    for linha in arquivoCif:
        valorCrypto = int(linha)
        print(valorCrypto)
        print((valorCrypto**e)%n)
        arquivoCrypto.write(str((valorCrypto**e)%n))
        arquivoCrypto.write('\n')
    arquivoCrypto.close()

def decifrarArquivo():
    arquivo = open(nmArquivo,'r')
    nmArquivoDeCif = nmArquivo+'.orig'
    arquivoDecif = open(nmArquivoDeCif,'w')
    print(nmArquivo)
    for linha in arquivo:
        print(linha)
        print(chr(int(linha)))  
        arquivoDecif.write(chr(int(linha)))
    arquivoDecif.close()

def descriptografarArquivo():
    print("descobriptografando..\n")



main()
