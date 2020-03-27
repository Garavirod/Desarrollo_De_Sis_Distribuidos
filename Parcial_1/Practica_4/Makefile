programa4-1: programa4-1.cpp Rectangulo.o
	g++ programa4-1.cpp Rectangulo.o Coordenada.o -o programa4-1
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
clean:
	rm -f programa4-1 *.o