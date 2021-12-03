#pragma once

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <filesystem>

#include "../utils/datagrama.hpp"


#define SA struct sockaddr

constexpr int MAX = 140;
constexpr int PORT = 8080;
constexpr const char *IP_LOCAL = "0.0.0.0";
constexpr const char *IP_SERVER = "192.168.0.185";
