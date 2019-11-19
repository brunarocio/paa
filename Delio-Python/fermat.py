import math
import sys
 
factors = []
 
def isqrt(number):
    return (int(math.sqrt(number)))
 
def fermat(number):
    global factors
 
    while number % 2 == 0:
        number = number/2
        factors.append(2)
 
    if number == 1:
        return
 
    r = isqrt(number)
    is_prime = True
    while r < (number+1)/2:
        m = (r ** 2) - number
 
        if m >= 0 and math.sqrt(m) == math.floor( math.sqrt(m) ):
            s = isqrt(m)
            fermat(r - s)
            fermat(r + s)
 
            is_prime = False
            return
 
        r = r+1
     
    if is_prime == True:
        factors.append(number)
 
 
num = int(sys.argv[1])
 
fermat(num)
 
print(factors)