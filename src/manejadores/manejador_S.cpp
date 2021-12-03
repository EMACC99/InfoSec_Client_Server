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

bool login (std::unique_ptr<sql::Connection> &conn, const Datagrama &datos){
    try{
        std::unique_ptr<sql::PreparedStatement> stmnt (conn -> prepareStatement("SELEC pass FROM users WHERE user = ?"));
        stmnt -> setString(1, datos.user);

        sql::ResultSet *res = stmnt -> executeQuery();
        
        bool succes = false;

        while(res -> next()){
            if(!strcmp(res -> getString("pass"), datos.pass.c_str()))
                succes = true;
        }

        return succes;
    }
    catch(sql::SQLException &e){
        std::cerr << "Error making queries: " << e.what() << std::endl;
        return false;
    }
}


void registro(std::unique_ptr<sql::Connection> &conn, const Datagrama &datos){
    try{
        std::unique_ptr<sql::PreparedStatement> stmnt (conn -> prepareStatement("INSERT INTO users (user, pass) VALUES (?, ?)"));

        stmnt -> setString(1, datos.user);
        stmnt -> setString(2, datos.pass);
        stmnt -> executeQuery();
    }
    catch(const sql::SQLException &e){
        std::cerr << e.what() << '\n';
    }
    
}

bool manejador_servidor(int sockfd, std::unique_ptr<sql::Connection> &conn){
    std::string mensaje;
    recibir_mensaje(sockfd, mensaje);   
    if (mensaje == "3")
        return false;
    
    Datagrama data(mensaje);

    if (data.operacion == "1"){
        if (login(conn, data))
            enviar_mensaje(sockfd, "logeado");
        enviar_mensaje(sockfd, "no logeado");
    }
    else if (data.operacion == "2")
        registro(conn, data);

    return true;
}