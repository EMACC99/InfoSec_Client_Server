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

void login (std::unique_ptr<sql::Connection> &conn, const Datagrama &datos, std::string &message){
    try{
        std::unique_ptr<sql::PreparedStatement> stmnt (conn -> prepareStatement("SELECT pass FROM users WHERE userName = ?"));
        stmnt -> setString(1, datos.user);

        sql::ResultSet *res = stmnt -> executeQuery();
    
        while(res -> next()){
            if(!strcmp(res -> getString("pass"), datos.pass.c_str())){
                message = "se encontro el usuario, loggeado";
                return;

            }
        }
        message = "no se encontro el usuario";
        delete &stmnt;
        delete res;
    }
    catch(sql::SQLException &e){
        std::cerr << "Error making queries: " << e.what() << std::endl;
        message = "Error en la base de datos";

    }
}


void registro(std::unique_ptr<sql::Connection> &conn, const Datagrama &datos, std::string &message){
    try{
        std::unique_ptr<sql::PreparedStatement> stmnt (conn -> prepareStatement("SELECT COUNT(userName) FROM users WHERE userName = ?"));
        stmnt -> setString(1,datos.user);
        
        sql ::ResultSet *res = stmnt -> executeQuery();

        while (res -> next()){
            if (res -> getInt(1) > 0){
                message = "El usuario ya existe";
                return;
            }
        }
        delete &stmnt;
        std::unique_ptr<sql::PreparedStatement> stmnt2 (conn -> prepareStatement("INSERT INTO users (userName, pass) VALUES (?, ?)"));

        stmnt2 -> setString(1, datos.user);
        stmnt2 -> setString(2, datos.pass);
        stmnt2 -> executeQuery();
        message = "Registro exitoso";

        delete &stmnt2;
        delete res;
    }
    catch(const sql::SQLException &e){
        std::cerr << e.what() << '\n';
        message = "ah ocurrido un error en la base de datos";
    }
    
}

bool manejador_servidor(int sockfd, std::unique_ptr<sql::Connection> &conn){
    std::string mensaje;
    recibir_mensaje(sockfd, mensaje);   
    if (mensaje == "3")
        return false;
    
    Datagrama data(mensaje);

    if (data.operacion == "2"){
        login(conn, data, mensaje);
    }
    else if (data.operacion == "1"){
        registro(conn, data, mensaje);
        
    }

    enviar_mensaje(sockfd, mensaje);
    return true;
}