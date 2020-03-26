run: compile	
compile: compile-libs
	g++ cliente.cpp -o cliente.out PaqueteDatagrama.o SocketDatagrama.o -lpthread
	g++ servidor.cpp -o servidor.out PaqueteDatagrama.o SocketDatagrama.o -lpthread
	g++ PaqueteDatagrama.o SocketDatagrama.o Respuesta.cpp servidor.cpp -o servidor
	g++ PaqueteDatagrama.o SocketDatagrama.o Solicitud.cpp cliente.cpp -o cliente
compile-libs: 
	g++ -c PaqueteDatagrama.cpp
	g++ -c SocketDatagrama.cpp
clean:
	rm PaqueteDatagrama.o
	rm SocketDatagrama.o
	rm cliente.out
	rm servidor.out
	rm Respuesta.out
	rm Solicitud.out

