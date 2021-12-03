# InfoSec Client Server
Un Simple Cliente Servidor para la materia de seguridad informatica escrito en C++, con algunos componentes de C. El objetivo es simular ataques de cierta forma.

## Compilacion
El programa consta de dos partes, un cliente y un servidor, aunque compartan archivos, se compilan por separado.

Las librerias requeridas son:
* gcc/g++
* make
* libfmt-dev Para instalar esta libreria, se puede consultar [aqui](https://mariadb.com/docs/clients/mariadb-connectors/connector-cpp/install/)
* libboost-all-dev

### Servidor
Para compilar el servidor, se tiene que ejecutar lo siguente:
```
make server
```

### Cliente
Para compilar el cliente, es de la siguente manera:
```
make cliente
```
