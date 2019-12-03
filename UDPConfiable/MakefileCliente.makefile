Cliente: Cliente.cpp Solicitud.o SocketDatagrama.o PaqueteDatagrama.o
	g++ Cliente.cpp Solicitud.o SocketDatagrama.o PaqueteDatagrama.o -o Cliente
Solicitud.o: Solicitud.cpp Solicitud.h
	g++ Solicitud.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp  PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c