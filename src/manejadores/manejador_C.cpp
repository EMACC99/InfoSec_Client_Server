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

void menu(){
    std::cout << "Menu de cosa de contraseña \n";
    std::cout << "1) Crear cuenta \n";
    std::cout << "2) iniciar sesion \n";
    std::cout << "3) Salir" << std::endl;
}


void pedir_datos(Datagrama &data){
    std::cout << "Usuario: ";
    std::cin >> data.user;
    std::cout << "Password: ";
    std::cin >> data.pass;
}


bool manejador_cliente(int sockfd){
    std::cout << "Coso de contraseñas" << std::endl;    
    std::string choice;

    while(true){
        menu();
        Datagrama data;
        if (choice == "3"){
            enviar_mensaje(sockfd, "3");
            break;
        }
        
        data.operacion = choice;
        pedir_datos(data);
        data.pass = std::to_string(std::hash<std::string>{}(data.pass));

        std::string mensaje = data.construct_string();

        std::cout << mensaje << std::endl;
        enviar_mensaje(sockfd, mensaje);
        
        
        recibir_mensaje(sockfd, mensaje);
        std::cout << mensaje << std::endl;
    }
    return false;
}