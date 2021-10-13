#include "../../include/sockets/socket_includes.hpp"
#include "../../include/manejadores/manejador_C.hpp"

void client_listener(int sockfd){

    bool status = true;

    while (status){
        status = manejador_cliente(sockfd);
    }

}

int main(){
    int sockfd,connfd;
    
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0 );
    if (sockfd == -1){
        std::cout << "Creacion del socket fallida" << std::endl;
        exit(1);
    }

    else
        std::cout << "Socket creado exitosamente" << std::endl;
    
    bzero(&server, sizeof(server));

    //asignar IP, PORT
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(PORT);

    //connect
    if (connect(sockfd, (SA*)&server, sizeof(server)) != 0){
        std::cout << "Conexion con el servidor fallo" << std::endl;
        close(sockfd);
        exit(1);
    }
    else
        std::cout << "Conexion con el servidor exitosa" << std::endl;
    
    client_listener(sockfd);

    close(sockfd);
}