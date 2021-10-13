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
		std::cout << "Socket creation failed..." << std::endl;
		EXIT_FAILURE;
	}
	else {
		std::cout << "Socket successfully created..." << std::endl;
	}
	
	bzero(&server, sizeof(server));
	
	// assign IP, PORT
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY); 
	server.sin_port = htons(PORT);
	
	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&server, sizeof(server))) != 0) {
		std::cout << "Socket bind failed..." <<std::endl;
		EXIT_FAILURE;
	}
	else
		std::cout << "Socket successfully binded..." << std::endl;
	
	
	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		std::cout << "Listen failed..." << std::endl;
		EXIT_FAILURE;
	}
	else 
		std::cout << "Server listening..." << std::endl;
	
	
	len = sizeof(cli);
	
	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if ( connfd < 0 ) {
		std::cout << "Server acccept failed..." << std::endl;
		EXIT_FAILURE;
	}
	else 
		std::cout << "Server acccept the client..." << std::endl;
	
	
	// Function for chatting between client and server
	server_listener(connfd);
	
	// After chatting close the socket
	close(sockfd);
}