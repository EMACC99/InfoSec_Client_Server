#pragma once

#include "../sockets/socket_includes.hpp"


#ifdef _WIN32
void recibir_mensaje(SOCKET s, std::string &message);
void enviar_mensaje(SOCKET s, std::string& message);
void enviar_mensaje(SOCKET s, const char* message);

#elif __linux__

void recibir_mensaje(int sockfd, std::string &mensaje);
void enviar_mensaje(int sockfd, std::string &mensaje);
void enviar_mensaje(int sockfd, const char *mensaje);
#endif // __WIN32
