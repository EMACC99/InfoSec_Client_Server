#pragma once


#include "../sockets/socket_includes.hpp"

constexpr int ESC = 27;


bool manejador_servidor(int sockfd, const std::string &correct_pass){
    std::cout << "Coso de contraseñas, precione esc para salir" << std::endl;
    
    std::string pass;

    do{
        std::cout << "Introduzca la contraseña";
        std::cin >> pass;

    } while (pass[0] != ESC);
    
    

}
