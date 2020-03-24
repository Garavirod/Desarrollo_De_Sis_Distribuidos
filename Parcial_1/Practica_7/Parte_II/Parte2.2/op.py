import math

max = 9999999 #50000000
i = 1
aux = 0.0
seno = 0.0
coseno = 0.0
tang = 0.0
log = 0.0
raiz = 0.0


while i < max:
    seno += math.sin(i)
    coseno += math.cos(i)
    tang += math.tan(i)
    log += math.log(i)
    raiz += math.sqrt(i)
    i += 1

