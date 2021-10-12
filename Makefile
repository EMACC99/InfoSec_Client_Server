CC = g++
CFLAGS = -Wall -g
LIBFLAGS =
DEPS = 
OBJ = 
SERVER_BIN =
CLIENT_BIN =

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(SERVER)