#include "../../include/sockets/socket_includes.hpp"
#include "../../include/manejadores/manejador_S.hpp"
#include "../../include/utils/read_file.hpp"

void server_listener(int sockfd){
    std::string pass = read_password("../../password.txt");

    bool status = true;

    while (status){
        status = manejador_servidor(sockfd, pass);
    }
}


int main() {
	
	int sockfd,connfd;
    socklen_t len;
	struct sockaddr_in server, cli;
	
	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		std::cout << "Creacion del Socket fallo..." << std::endl;
		EXIT_FAILURE;
	}
	else {
		std::cout << "Socket creado exitosamente..." << std::endl;
	}
	
	bzero(&server, sizeof(server));
	
	// assign IP, PORT
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY); 
	server.sin_port = htons(PORT);
	
	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&server, sizeof(server))) != 0) {
		std::cout << "Socket bind fallo..." <<std::endl;
		EXIT_FAILURE;
	}
	else
		std::cout << "Socket bindedado..." << std::endl;
	
	
	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		std::cout << "Fallo el listener..." << std::endl;
		EXIT_FAILURE;
	}
	else 
		std::cout << "Server escuchando..." << std::endl;
	
	
	len = sizeof(cli);
	
	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if ( connfd < 0 ) {
		std::cout << "Server no acepto al cliente..." << std::endl;
		EXIT_FAILURE;
	}
	else 
		std::cout << "Server acepto al client..." << std::endl;
	
	
	// Function for chatting between client and server
	server_listener(connfd);
	
	// After chatting close the socket
	close(sockfd);
}