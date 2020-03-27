programa6-1: programa6-1.cpp PoligonoIrreg.o
	g++ programa6-1.cpp PoligonoIrreg.o Coordenada.o -o programa6-1
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
clean:
	rm -f programa6-1 *.o