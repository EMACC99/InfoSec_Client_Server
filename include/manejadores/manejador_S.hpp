#pragma once
#include <cstring>
#include <mariadb/conncpp.hpp>
#include <fmt/format.h>

#include "../sockets/socket_includes.hpp"

bool manejador_servidor(int sockfd, std::unique_ptr<sql::Connection> &conn);