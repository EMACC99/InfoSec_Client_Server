# InfoSec Client Server
Un Simple Cliente Servidor para la materia de seguridad informatica escrito en C++, con algunos componentes de C. El objetivo es simular ataques de cierta forma.

Al ser la mayoria un cliente servidor, se puede usar para distintas cosas, en esta ocasion, se ha juntando con la libreria de mariadb para hacer conecciones a una base de datos
## Compilacion
El programa consta de dos partes, un cliente y un servidor, aunque compartan archivos, se compilan por separado.

Las librerias requeridas son:
* gcc/g++
* make
* mariadb
* mariadb-connector-cpp Para instalar esta libreria, se puede consultar [aqui](https://mariadb.com/docs/clients/mariadb-connectors/connector-cpp/install/)
* libboost-all-dev
* libfmt-dev


### Base de datos
Para configurar la base de datos, se tiene que tener instalado y condfigurador mariadb, y posteriormente ejecutar el script llamado `db.sql` para crear la base de datos, tablas y usuario que se va a usar.
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
Para cualquier cambio en las compilaciones, se puede modificar el `Makefile`