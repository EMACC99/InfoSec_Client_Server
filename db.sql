CREATE DATABASE IF NOT EXISTS MY_SERVICE;

CREATE TABLE MY_SERVICE.users(
    id int AUTO_INCREMENT PRIMARY KEY, 
    userName varchar(200) NOT NULL,
    pass varchar(200) NOT NULL
);