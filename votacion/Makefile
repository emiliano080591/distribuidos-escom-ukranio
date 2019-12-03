all: Servidor Cliente

Servidor: SocketDatagrama.o PaqueteDatagrama.o Respuesta.o SocketMulticast.o receptor.cpp
		g++ receptor.cpp SocketDatagrama.o PaqueteDatagrama.o Respuesta.o SocketMulticast.o -o receptor

Cliente: SocketDatagrama.o PaqueteDatagrama.o Respuesta.o Solicitud.o SocketMulticast.o emisor.cpp
		g++ emisor.cpp SocketDatagrama.o PaqueteDatagrama.o Solicitud.o Respuesta.o SocketMulticast.o -o emisor

SocketMulticast.o: SocketMulticast.cpp SocketMulticast.h
		g++ SocketMulticast.cpp -c

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
		g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
		g++ PaqueteDatagrama.cpp -c

Respuesta.o: Respuesta.cpp Respuesta.h
		g++ Respuesta.cpp -c

Solicitud.o: Solicitud.cpp Solicitud.h
		g++ Solicitud.cpp -c