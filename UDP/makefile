all: servidorUDP2 clienteUDP2
	@echo "Compílados."

servidorUDP2: servidorUDP2.cpp
	g++ PaqueteDatagrama.cpp SocketDatagrama.cpp servidorUDP2.cpp -o servidorUDP2

clienteUDP2: clienteUDP2.cpp
	g++ PaqueteDatagrama.cpp SocketDatagrama.cpp clienteUDP2.cpp -o clienteUDP2
