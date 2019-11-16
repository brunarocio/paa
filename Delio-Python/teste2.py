b = pow(100,3)
b = b%2723361
print(b)
c  = pow(100,35,3122225)
print(c)
d = (pow(10,35))
e = d%3122225
print(e)
print('mensagem: ',pow(855125,178211,3122225))
print('modulo: ',22%64)

def mdc(a,b):
    #resto = 1
    #maximo divisor comum
    while (b!=0):
        resto = a%b
        a = b
        b = resto
    return a