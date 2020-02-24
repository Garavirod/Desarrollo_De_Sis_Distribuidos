import random

cadenota = ""
cad = ""

for i in range(0,100000): #5
    aux = ""
    for x in range (0,3):
        cad = random.randrange(65,90)
        aux = aux + str(chr(cad))
    #print(aux)
    cadenota = cadenota + aux + " "
    
#print(cadenota)
print((len(cadenota)) / 4)
print("Apariciones de IPN: ", cadenota.count("IPN"))
