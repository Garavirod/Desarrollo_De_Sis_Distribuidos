programa5-2: programa5-2.cpp PoligonoIrreg.o
	g++ programa5-2.cpp PoligonoIrreg.o Coordenada.o -o programa5-2
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
clean:
	rm -f programa5-2 *.o