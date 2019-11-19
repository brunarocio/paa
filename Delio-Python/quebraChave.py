import math

fatores = []
z = 0

def pollardRho(n,e):
    #Utiliza a chave publica para quebrar a chave privada
    x = e
    xp = ((x**2+1)%n)
    p = mdc(x - xp,n)
    i = 0
    while p == 1:
        #print('Tentativa ',i)
        x = ((x**2+1)%n)
        xp = ((xp**2+1)%n)
        xp = ((xp**2+1)%n)
        p = mdc(x-xp,n)
        i = i+1
    if p == n:
        return [i,-1]
    else:
        return [i,p]

def mdc(a,b):
    #resto = 1
    #maximo divisor comum
    while (b!=0):
        resto = a%b
        a = b
        b = resto
    return a


def calcularFator(num):
    print('Numero: ',num)
    i = num
    j = 0
    k = 0
    while True:
        i +=j
        k = int(math.sqrt(i))
        if ((j%2) == 0):
            j += 1
        else:
            j += 2
        if ((i-(k*k) > 0)):
            break
    k += j
    num /= k
    if (num > k):
        return k
    else:
        return num

def isqrt(num):
    return (int(math.sqrt(num)))
 
def bruteForce(num):
    global fatores
    global z
 
    while num % 2 == 0:
        num = num/2
        fatores.append(2)
 
    if num == 1:
        fatores.append(z)
        return fatores
 
    r = isqrt(num)
    is_prime = True
    while r < (num+1)/2:
        z = z+1
        m = (r ** 2) - num
 
        if m >= 0 and math.sqrt(m) == math.floor( math.sqrt(m) ):
            s = isqrt(m)
            bruteForce(r - s)
            bruteForce(r + s)
            is_prime = False
            fatores.append(z)
            return fatores
 
        r = r+1
     
    if is_prime == True:
        fatores.append(num)