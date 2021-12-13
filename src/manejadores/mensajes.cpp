#include "../../include/manejadores/mensajes.hpp"



#ifdef _WIN32
void recibir_mensaje(SOCKET s, std::string& message) {
    char buff[MAX];
    bzero(buff, MAX);
    recv(s, buff, sizeof(buff), 0);
    message = buff;
}

void enviar_mensaje(SOCKET s, std::string& message) {

    char buff[MAX];
    bzero(buff, MAX);

    const char* x = message.c_str();
    send(s, x, sizeof(buff), 0);
} 

void enviar_mensaje(SOCKET s, const char* message) {
    char buff[MAX];
    bzero(buff, MAX);

    send(s, message, sizeof(buff), 0);
}



#elif __linux__
void recibir_mensaje(int sockfd, std::string& mensaje) {
    char buff[MAX];
    bzero(buff, MAX);
    read(sockfd, buff, sizeof(buff));
    mensaje = buff;
}

void enviar_mensaje(int sockfd, std::string &mensaje){
    char buff[MAX];
    bzero(buff, MAX);

    const char *x = mensaje.c_str();
    write(sockfd, x, sizeof(buff));
}

void enviar_mensaje(int sockfd, const char *mensaje){
    char buff[MAX];
    bzero(buff, MAX);
    write(sockfd, mensaje, sizeof(buff));
}
#endif