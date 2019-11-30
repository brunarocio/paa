
from random import *
from datetime import *

def gerarChaves():
    h = 8
    arqTesteChave = open('ArquivoChaves','a')
    while (h<=1024):
        for m in range(10):
            print('Gerando chave de ',h,' bits')
            hr_ini = datetime.now()
            chaves = gerarChave(h)
            hr_fim = datetime.now()
            tempoTotal = hr_fim-hr_ini

            texto = (str(h)+';'+str(tempoTotal)+';'+str(chaves))
            arqTesteChave.write(texto)
            arqTesteChave.write('\n')
            print(chaves)
        h = h+8
    arqTesteChave.close()


def gerarChave(qtdeBits):
    i = 0
    j = 0
    seed()
    #print('Gerando números aleatórios de ',qtdeBits,' bits...')
    #print('Numeros aleatórios gerados com sucesso!')
    p = randint(2**qtdeBits,2**(qtdeBits+1)-1)
    q = randint(2**qtdeBits,2**(qtdeBits+1)-1)
    if ((p%2) == 0):
        p = p+1
    if ((q%2) == 0):
        q = q+1
    #print('Verificando primalidade do primeiro número gerado...')
    while (verificaPrimalidade(p)==0):
        i=i+1
        p = p+2
    #print('Verificando primalidade do segundo número gerado...')
    while (verificaPrimalidade(q)==0):
        j=j+1
        q = q+2
    #print('Numeros primos encontrados: \nP: ',p,'\nQ: ',q)
    #print('Definindo variaveis para criação da chave publica & privada..')
    n = p*q
    #definindo e
    PhiN = phiN(p,q)
    auxe = 32
    while (mdc(auxe,PhiN)!=1):
        auxe+=1
    e = auxe
    #e = 3
      
    #definindo d
    x = 1
    y = 1
    #eX = euclidesExt(e,PhiN,x,y)
    d = int(eucliedesExt2(e,PhiN,x))
    gerarChavePublica(n,e)
    #print("E: ",e)  
    #print('D: ',d)
    #print('Gerando chave publica..')
    #print('Gerando chave privada...')
    #auxd = gerarChavePrivada(p,q,n,e)
    #d = round(auxd,0)
    #d = euclidesEst(PhiN,e)
    #print('N: ',n)
    #print('D: ',d)
    return(n,d,e)

def criptografar(nmArquivo,qtdeBits=8):
    i = 0
    j = 0
    seed()
    print('Gerando números aleatórios de ',qtdeBits,' bits...')
    print('Numeros aleatórios gerados com sucesso!')
    p = randint(2**qtdeBits,2**(qtdeBits+1)-1)
    q = randint(2**qtdeBits,2**(qtdeBits+1)-1)
    if ((p%2) == 0):
        p = p+1
    if ((q%2) == 0):
        q = q+1
    print('Verificando primalidade do primeiro número gerado...')
    while (verificaPrimalidade(p)==0):
        i=i+1
        p = p+2
    print('Verificando primalidade do segundo número gerado...')
    while (verificaPrimalidade(q)==0):
        j=j+1
        q = q+2
    print('Numeros primos encontrados: \nP: ',p,'\nQ: ',q)
    print('Definindo variaveis para criação da chave publica & privada..')
    n = p*q
    #definindo e
    PhiN = phiN(p,q)
    auxe = 32
    while (mdc(auxe,PhiN)!=1):
        auxe+=1
    e = auxe
    #e = 3
    print("E: ",e)    
    #definindo d
    x = 1
    y = 1
    #eX = euclidesExt(e,PhiN,x,y)
    d = int(eucliedesExt2(e,PhiN,x))
    print('D: ',d)
    print('Gerando chave publica..')
    gerarChavePublica(n,e)
    print('Gerando chave privada...')
    auxd = gerarChavePrivada(p,q,n,e)
    #d = round(auxd,0)
    #d = euclidesEst(PhiN,e)
    print('N: ',n)
    print('D: ',d)
    print('Cifrando o arquivo..\n')
    nmArquivoCifrado = cifrarArquivo(nmArquivo)
    print('Arquivo ',nmArquivoCifrado,' cifrado com sucesso!')
    nmArquivoCriptografado = criptoArquivoCifrado(nmArquivo,e,n)
    print('Arquivo ',nmArquivoCriptografado,' criptografado com sucesso!')

def verificaPrimalidade(num):
    a = num
    b = num-1
    #c = (a**b)
    ##print('aplicando pow\n')
    for i in range (5):
        a = a // 2
        #c = pow(a,b)
        #print('C: ',c)
        #primo = c%num
        primo = pow(a,b,num)
        #primo = pow(b,a,num)
        ##print('Primo: ',primo)
        if (primo != 1):
            return 0
    return 1


def phiN(p,q):
    PhiN = (p-1)*(q-1)
    return PhiN

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
        #return ( (c / a) % ( b / a) )
        return ( (c // a) % ( b // a) )
    
    #return ( ( eucliedesExt2(r, a, -c) * b + c) / (a % b) )
    return ( ( eucliedesExt2(r, a, -c) * b + c) // (a % b) )

def gerarChavePublica(n,e):
    nmArquivoPublicKey = 'public.key'
    arquivoPublicKey = open(nmArquivoPublicKey,'w')
    arquivoPublicKey.write(str(n))
    arquivoPublicKey.write('\n')
    arquivoPublicKey.write(str(e))
    arquivoPublicKey.close()

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

def cifrarArquivo(nmArquivo):
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
    return nmArquivoCif

def criptoArquivoCifrado(nmArquivo,e,n):
    nmArquivoCif = nmArquivo+'.cif'
    arquivoCif = open(nmArquivoCif,'r')
    nmArquivoCrypto = nmArquivo+'.crypto'
    arquivoCrypto = open(nmArquivoCrypto,'w')
    ##print(nmArquivoCrypto)
    for linha in arquivoCif:
        valorCrypto = int(linha)
        ##print(valorCrypto)
        ##print((valorCrypto**e)%n)
        arquivoCrypto.write(str(pow(valorCrypto,e,n)))#(valorCrypto**e)%n))
        arquivoCrypto.write('\n')
    arquivoCrypto.close()
    return nmArquivoCrypto