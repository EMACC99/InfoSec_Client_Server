#pragma once

#include "../sockets/socket_includes.hpp"

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