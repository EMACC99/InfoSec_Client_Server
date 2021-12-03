#include "../../include/sockets/socket_includes.hpp"
#include "../../include/manejadores/manejador_S.hpp"

void server_listener(int sockfd, std::unique_ptr<sql::Connection> &conn){

    bool status = true;

    while (status){
        status = manejador_servidor(sockfd, conn);
    }
}

std::unique_ptr<sql::Connection> connect_db(){
	sql::Driver *driver = sql::mariadb::get_driver_instance();
	
	sql::SQLString url("jdbc:mariadb://localhost:3306/todo");
	sql::Properties properties({{"user", "app_user"}, {"password", "Password123!"}});

	std::unique_ptr<sql::Connection> conn (driver -> connect(url, properties));

	return conn;
}

int main() {
	
	int sockfd,connfd;
    socklen_t len;
	struct sockaddr_in server, cli;
	
	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		std::cout << "Creacion del Socket fallo..." << std::endl;
		return EXIT_FAILURE;
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
		return EXIT_FAILURE;
	}
	else
		std::cout << "Socket bindedado..." << std::endl;
	
	
	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		std::cout << "Fallo el listener..." << std::endl;
		return EXIT_FAILURE;
	}
	else 
		std::cout << "Server escuchando..." << std::endl;
	
	
	len = sizeof(cli);
	
	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if ( connfd < 0 ) {
		std::cout << "Server no acepto al cliente..." << std::endl;
		return EXIT_FAILURE;
	}
	else 
		std::cout << "Server acepto al cliente..." << std::endl;
	
	
	// Function for chatting between client and server
	std::unique_ptr<sql::Connection> conn = connect_db();
	server_listener(connfd, conn);
	
	// After chatting close the socket
	close(sockfd);
	return EXIT_SUCCESS;
}