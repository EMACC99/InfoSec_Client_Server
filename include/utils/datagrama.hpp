#include <string>

#include "../utils/split_strings.hpp"

class Datagrama {

public:
    std::string user;
    std::string pass;
    std::string operacion;

    Datagrama(const std::string &user, const std::string &pass, const std::string &operacion){
        this -> user = user;
        this -> pass = pass;
        this -> operacion = operacion;
    }

    Datagrama(std::string message){
        std::vector splitted_string = split_by_char(message);
        this -> operacion = splitted_string[0];
        this -> user = splitted_string[1];
        this -> pass = splitted_string[2];
    }

    std::string construct_string(){
        std::string temp;
        temp.append(this -> operacion);
        temp.append(";");
        temp.append(this -> user);
        temp.append(";");
        temp.append(this -> pass);

        return temp;
    }

};
