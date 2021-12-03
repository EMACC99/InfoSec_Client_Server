CC = g++
CFLAGS = -Wall -g -Wpedantic -Wno-sign-compare -std=c++14
LIBFLAGS = -lmariadbcpp
MANEJADORES = src/manejadores/manejador_
MENSAJES = src/manejadores/mensajes.cpp
# UTILS = src/utils/read_file.cpp
UTILS = 
DEPS_C = $(MANEJADORES)C.cpp $(MENSAJES)
DEPS_S = $(MANEJADORES)S.cpp $(MENSAJES) $(UTILS)
SERVER_BIN = socketServer
CLIENT_BIN = socketClient

cliente:
	$(CC) $(CFLAGS) src/sockets/$(CLIENT_BIN).cpp $(DEPS_C) $^ -o $@

server: 
	$(CC) $(CFLAGS) src/sockets/$(SERVER_BIN).cpp $(DEPS_S) $(LIBFLAGS) $^ -o $@

clean:
	rm server cliente
