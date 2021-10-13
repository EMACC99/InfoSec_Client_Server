#include <sstream>
#include <iomanip>
#include "../../include/manejadores/manejador_C.hpp"
#include "../../include/manejadores/mensajes.hpp"

constexpr int ESC = 27;
constexpr int MAX_NUM = 10000;


std::string zero_pading(const int &num, const int &number_of_zeros = 4){
    std::ostringstream ss;
    ss << std::setw(number_of_zeros) << std::setfill('0') << num;
    return ss.str();
}

bool manejador_cliente_fuerza_bruta(int sockfd){
    std::string pass, message;
    for (int i = 0; i < MAX_NUM; ++i){
        pass = zero_pading(i);
        enviar_mensaje(sockfd, pass);
        recibir_mensaje(sockfd, message);
        if (message == "logeado"){
            std::cout << message << "\n" ;
            std::cout << "exito, la contra es " << pass << std::endl;
            break;
        }
    }
    return false;
}


bool manejador_cliente(int sockfd){
    std::cout << "Coso de contraseñas, precione esc para salir" << std::endl;    
    std::string pass;

    while(true){
        std::cout << "Introduzca la contraseña: ";
        std::cin >> pass;
        if (pass[0] == ESC){
            pass = "exit";
            enviar_mensaje(sockfd, pass);
            break;
        }
        
        enviar_mensaje(sockfd, pass);
        recibir_mensaje(sockfd, pass);
        std::cout << pass << std::endl;
    }
    return false;
}