#pragma once

#include "../sockets/socket_includes.hpp"

void recibir_mensaje(int sockfd, std::string &mensaje);
void enviar_mensaje(int sockfd, std::string &mensaje);