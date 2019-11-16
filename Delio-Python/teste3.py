import sys
import random
from fractions import gcd
from datetime import datetime, timedelta

  
#	Testar se valor é primo
#   primo = 2 ^ n-1 MOD n ou (2**n-1%n)
def gerarPrimo(ini, nPrimo):
  q = 0  
  while q == 0:
    testeprimo = random.randrange(ini,nPrimo)
    q2 = pow(2,testeprimo-1,testeprimo)	
    q1 = pow(3,testeprimo-1,testeprimo)
    q0 = pow(4,testeprimo-1,testeprimo) 
    q01 = pow(5,testeprimo-1,testeprimo)
    q02 = pow(6,testeprimo-1,testeprimo)	
    if (q2 == 1) and (q1 == 1) and (q0 == 1) and (q01 == 1) and (q02 == 1):
      return testeprimo      
    else:
      q = 0

#Encontrar D
def euclides_est(a, b, c):
   r = b % a
   if r == 0:
     return ( (c / a) % ( b / a) )
    
   return ( ( euclides_est(r, a, -c) * b + c) / (a % b) )

def f(x):
	""" function for pollard's rho """
	return x**2 + 1

def factorRho(n,x_1):
	""" Factor using pollard's rho method """
	#ed = 1 mod ((p-1)(q-1))
	x = x_1;
	xp = f(x) % n
	p = gcd(x - xp,n)

	while p == 1:
		x = f(x) % n
		xp = f(xp) % n
		xp = f(xp) % n
		p = gcd(x-xp,n)

	if p == n: return -1
	else: return p

p = 0
q = 0
e = 0

print ("Tamanho da Chave Primaria (bits): ")
opcao = int(input("16bits a 128bits: "))
primof = 2**(opcao/2)-1

#gerar valor para P e Q
p = gerarPrimo(1,primof)
q = gerarPrimo(1,primof)
print("p: ",p)
print("q: ",q)

#gerar valor de N
n = p*q     #O(1)
print ("n: ", n)
#Valor de Z "z = (p-1)*(q-1)")
z = (p-1)*(q-1)     #O(1)
print ("z: " , z) 

#Encontrar E
e = gerarPrimo(1,primof)

print ("Chave Publica N: " , n)
print ("Chave Publica E: " , e)


#gerar D
# forçar D a ser integer
d = int(euclides_est(e, z, 1))
print ("Chave Privada D: " , d)

#Executar criptografia
print ("\nCriptografar..." )
lista = ["T","E","S","T","E"]
#formula padrão
#c = (m**e) % n  ou (m ^ e MOD n)
#Convertendo letras para ASCII e depois criptografando) 
#Complexidade O(N), depende do tam. da mensagem
i = 0
NN = len(lista)
while i < NN:
  lista [i] = pow(ord(lista [i]),e,n) 
  i = i+1

print ("\nMensagem Criptografada: \n" , lista)


# decifrar a mensagem
# 2^N , pois D varia de P e Q
#Descriptografando e depois convertendo de ASCII para letras
print ("Descriptografar...")
if opcao < 56 :
  #m = c ^ d % n
  i = 0
  while i < NN:
    lista [i] = chr(pow(lista [i],d,n))
    i = i+1
    
  print ("Mensagem Descriptografada: \n" , lista)
else:
  print ("Chave muito Grande")

hora_inicio_quebra = datetime.now()
print("\nInicio Quebra: ", hora_inicio_quebra)

  

pEncontrado = factorRho(n,e)
print ("Busca por p/q: ",pEncontrado)
print ("Buca por q/p: ", int(n/pEncontrado))
print ("E (Publico): " , e)

hora_fim = datetime.now()
print("Fim Quebra: ", hora_fim)
tempoExec = hora_fim - hora_inicio_quebra
print ("Tempo Quebra da Chave : ", tempoExec)