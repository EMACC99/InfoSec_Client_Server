#pragma once

#include <fstream>
#include <sstream>

#include "../sockets/socket_includes.hpp"

std::string read_password(const std::string &path){
    std::ifstream archivoPassword;
    archivoPassword.open(path, std::ifstream::in);

    if (!archivoPassword.is_open())
        std::cout << "No se pudo abrir el archivo" << std::endl;
    
    std::string linea;
    getline(archivoPassword, linea);
    std::string pass = linea;

    archivoPassword.close();

    return pass;
    
}