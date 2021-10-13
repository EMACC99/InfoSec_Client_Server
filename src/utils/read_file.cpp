#include "../../include/utils/read_file.hpp"

std::string read_password(const std::string &path){
    std::cout << std::filesystem::current_path() << std::endl;
    std::ifstream archivoPassword;
    archivoPassword.open(path, std::ifstream::in);
    std::string pass;

    if (!archivoPassword.is_open()){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        pass = "1234";
    }

    else{
        std::string linea;
        getline(archivoPassword, linea);
        pass = linea;
        archivoPassword.close();
    }
    return pass;
    
}