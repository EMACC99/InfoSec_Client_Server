#include "../../include/manejadores/manejador_C.hpp"
constexpr int ESC = 27;

bool manejador_cliente(int sockfd){
    std::cout << "Coso de contraseñas, precione esc para salir" << std::endl;    
    std::string pass;

    while(true){
        std::cout << "Introduzca la contraseña";
        std::cin >> pass;
        if (pass[0] == ESC){
            pass = "exit";
            enviar_mensaje(sockfd, pass);
            break;
        }
        
        enviar_mensaje(sockfd, pass);
    }
    return false;
}