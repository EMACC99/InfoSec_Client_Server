#include "../../include/manejadores/mensajes.hpp"

void recibir_mensaje(int sockfd, std::string &mensaje){
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