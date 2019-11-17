def forcaBruta():
    print('Forca Bruta')

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
        return -1
    else:
        return p

def mdc(a,b):
    #resto = 1
    #maximo divisor comum
    while (b!=0):
        resto = a%b
        a = b
        b = resto
    return a