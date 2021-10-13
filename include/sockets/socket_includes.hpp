#pragma once

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cstdlib>


#define SA struct sockaddr

constexpr int MAX = 140;
constexpr int PORT = 8080;
