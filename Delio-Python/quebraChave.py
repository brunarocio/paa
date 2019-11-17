import math

def pollardRho(n,e):
    #Utiliza a chave publica para quebrar a chave privada
    x = e
    xp = ((x**2+1)%n)
    p = mdc(x - xp,n)
    i = 0
    while p == 1:
        print('Tentativa ',i)
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

def bruteForce(num):
    p = 1
    q = 1
    while True:
        p = calcularFator (num)
        while True:
            q = calcularFator (p)
            p /= q
            if (q>1):
                break
        num /= p
        if (p != 1):
            print('Valor p : ',p)
        else:
            print('Valor num: ',num)
        if (p>1):
            break

    print('Fatoracao completa!')

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
