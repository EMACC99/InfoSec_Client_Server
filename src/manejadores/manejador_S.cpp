#include "../../include/manejadores/manejador_S.hpp"
#include "../../include/manejadores/mensajes.hpp"

bool bad_string_checker(const std::string &a, const std::string &b, const size_t size){
    //esto es adrede
    for (int i = 0; i < size; ++i){
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool not_so_bad_string_checker(const std::string &a, const std::string&b, const size_t size){
    return a == b ? true : false;
}

bool manejador_servidor(int sockfd, const std::string &correct_pass){
    std::string mensaje;
    recibir_mensaje(sockfd, mensaje);

    if (mensaje == "exit")
        return false;
    
    if (not_so_bad_string_checker(mensaje, correct_pass, correct_pass.size()))
        enviar_mensaje(sockfd, "logeado");
    
    else
        enviar_mensaje(sockfd, "no logeado");

    return true;
}