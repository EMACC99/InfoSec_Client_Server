#pragma once

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>


#define SA struct sockaddr

constexpr int MAX = 140;
constexpr int PORT = 8080;

void recibir_mensaje(int sockfd, std::string &mensaje);
void enviar_mensaje(int sockfd, std::string &mensaje);

