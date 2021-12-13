#pragma once

#ifdef __linux__
    #include <netdb.h>
    #include <sys/socket.h>
    #include <unistd.h>
    #include <arpa/inet.h>

#elif _WIN32
    #include <winsock.h> 
    #include <io.h>
    template<typename T1, typename T2>
    constexpr auto bzero(T1 b, T2 len) { return (memset((b), '\0', (len)), (void) 0); }
#endif


#include <string.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <filesystem>

#include "../utils/datagrama.hpp"


#define SA struct sockaddr

constexpr int MAX = 140;
constexpr int PORT = 8080;
constexpr const char* IP_LOCAL = "0.0.0.0";
constexpr const char* IP_SERVER = "192.168.0.185";