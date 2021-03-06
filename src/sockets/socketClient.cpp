#include "../../include/sockets/socket_includes.hpp"
#include "../../include/manejadores/manejador_C.hpp"

void client_listener(int sockfd){

    bool status = true;

    while (status){
        status = manejador_cliente(sockfd);
        // status = manejador_cliente_fuerza_bruta(sockfd);
    }

}

int main(){
    
    
    #ifdef _WIN32
    WSADATA wsa;
    SOCKET sockfd;

    std::cout << "Iniciando Winsock ... \n";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cout << "RIP, error: " << WSAGetLastError() << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << "Iniciado \n";

    #elif __linux__
    int sockfd,connfd;
    #endif

    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0 );
    if (sockfd == INVALID_SOCKET ){
        std::cout << "Creacion del socket fallida" << std::endl;
        return EXIT_FAILURE;
    }

    else
        std::cout << "Socket creado exitosamente" << std::endl;
    bzero(&server, sizeof(server));

    //asignar IP, PORT
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(IP_SERVER);
	server.sin_port = htons(PORT);

    //connect
    if (connect(sockfd, (SA*)&server, sizeof(server)) != 0){
        std::cout << "Conexion con el servidor fallo" << std::endl;
        close(sockfd);
        return EXIT_FAILURE;
    }
    else
        std::cout << "Conexion con el servidor exitosa" << std::endl;
    
    client_listener(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}