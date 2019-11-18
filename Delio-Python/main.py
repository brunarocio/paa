from time import time
from random import *
from datetime import *
import sys
import math
from criptografia import *
from quebraChave import *
#print(sys.getrecursionlimit())


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

#Verificar se o arquivo informado existe
print('Verificando arquivo informado...')
try:
   with open(nmArquivo, 'r') as f:
       print('Arquivo encontrado com sucesso!')
except IOError:
    print('Arquivo não encontrado!')
    sys.exit()

#funcao principal
def main():
    if (opcao == 'c'):
        criptografar(nmArquivo,16)
    elif (opcao == 'd'):
        descriptografar()
    elif (opcao == 'qp'):
        quebraChavePollardRho()
    elif (opcao == 'qb'):
        quebraChaveForcaBruta()
    elif (opcao == 'ta'):
        testeAutomatizado()
    elif (opcao == 'tn'):
        testeNexecucoes()
    else:
        print('Escolha uma opcao valida!\n')

##--

def testeNexecucoes(j=48,k=100):
    i = 0
    nmArqTesteAuto = 'testeNauto'
    while (i<=k):
        criptografar(nmArquivo,j)
        publicKey = getChavePublica()
        n = int(publicKey[0])
        e = int(publicKey[1])
        #for j in range(5)
        hr_ini = datetime.now()
        chaveQueb = pollardRho(n,e)
        hr_fim = datetime.now()
        tempoTotal = hr_fim-hr_ini
        arqTesteAuto = open(nmArqTesteAuto,'a')
        #arquivo: qtde bits ; tipo quebra; tempo decorrido; total interações; valor chave quebrada; tempo decorrido.
        valorEncontrado = str(chaveQueb[1])
        qtdeIteracoes = str(chaveQueb[0])
        texto = (str(j)+';Pollard;'+str(tempoTotal)+';'+str(qtdeIteracoes)+';'+str(valorEncontrado))
        print('Texto: ',texto)
        #text_str = str(texto)
        arqTesteAuto.write(texto)
        arqTesteAuto.write('\n')
        print(i)
        i = i+1
    arqTesteAuto.close()

def testeAutomatizado():
    i = 8
    nmArqTesteAuto = 'testeautonovo'
    while (i<=128):
        criptografar(nmArquivo,i)
        publicKey = getChavePublica()
        n = int(publicKey[0])
        e = int(publicKey[1])
        #for j in range(5)
        hr_ini = datetime.now()
        chaveQueb = pollardRho(n,e)
        hr_fim = datetime.now()
        tempoTotal = hr_fim-hr_ini
        arqTesteAuto = open(nmArqTesteAuto,'a')
        #arquivo: qtde bits ; tipo quebra; tempo decorrido; total interações; valor chave quebrada; tempo decorrido.
        valorEncontrado = str(chaveQueb[1])
        qtdeIteracoes = str(chaveQueb[0])
        texto = (str(i)+';Pollard;'+str(tempoTotal)+';'+str(qtdeIteracoes)+';'+str(valorEncontrado))
        print('Texto: ',texto)
        #text_str = str(texto)
        arqTesteAuto.write(texto)
        arqTesteAuto.write('\n')
        print(i)
        i = i+8
    arqTesteAuto.close()

def quebraChavePollardRho():
    print("Quebra Chave POllard Rho")
    nmArquivoChave = nmArquivo
    arquivoChave = open(nmArquivoChave,'r')
    publicKey = getChavePublica()
    n = int(publicKey[0])
    e = int(publicKey[1])
    d = int(getChavePrivada())
    hr_inicio = datetime.now()
    print('Tentando quebrar a chave as ...')
    chaveQuebrada = pollardRho(n,e)
    hr_fim = datetime.now()
    print('Tempo total para quebra: ',hr_fim-hr_inicio)
    if (chaveQuebrada[1] < 0):
        print('Nao foi possível quebrar a chave!')
    else: 
        print('Chave quebrada: ',chaveQuebrada[1])

def quebraChaveForcaBruta():
    print("Quebra Chave Forca Bruta")
    publicKey = getChavePublica()
    n = int(publicKey[0])
    print('Public Key: ',publicKey)
    bruteForce(n)

def descriptografar():
    #decifrarArquivo()
    print('Descriptografando arquivo..')
    descriptografarArquivo()
    print('Arquivo descriptografado com sucesso!')
    print('Decifrando arquivo..')
    decifrarArquivo()
    print('Arquivo decifrado com sucesso!')

##-verificaprimalidade

##-gerarchavepublica

##-phin

##-gerarchaveprivada

def calcularPhiN(p,q):
    #como calcular phi de N
    PhiN = (p-1)*(q-1)
    return PhiN

##-cifrar e criptografar

def decifrarArquivo():
    arquivo = open(nmArquivo+'.decrypto','r')
    nmArquivoDeCif = nmArquivo+'.orig'
    arquivoDecif = open(nmArquivoDeCif,'w')
    #print(nmArquivo)
    for linha in arquivo:
        #print(linha)
        #print(chr(int(linha)))  
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
        #print('Valor n: ')
        #print(n)
        #print('Valor e: ')
        #print(e)
        #print('Valor d: ')
        #print(d)
        valorCrypto = int(linha)
        #print("valor linha: ")
        #print(valorCrypto)
        #print(math.pow(valorCrypto,(d-0.5)))
        #print(1367631 ** 2174328) % n
        ##print('valor descriptografado: ',pow(valorCrypto,d,n))
        #valorDecrypto = (valorCrypto**d)%n
        valorDecrypto = pow(valorCrypto,d,n)
        #print(pow(valorCrypto,d))
        arquivoDecrypto.write(str(valorDecrypto))
        arquivoDecrypto.write('\n')
    arquivoDecrypto.close()

##--mdc
##-euclidesext2

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