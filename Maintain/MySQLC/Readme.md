Referrence
https://zetcode.com/db/mysqlc/
https://textsegment.com/mysql-c-api/

Raspberry Pi

sudo apt-get update

sudo apt-cache search libmariadb-dev

pi@raspberrypi:~/dev/test $ sudo apt-cache search libmariadb-dev
libmariadb-dev - MariaDB Connector/C, development files
libmariadb-dev-compat - MariaDB Connector/C, compatibility symlinks

sudo apt-get install libmariadb-dev
sudo apt-get install libmariadb-dev-compat

pi@raspberrypi:~/dev/test $ sudo apt-cache search libmariadbclient-dev
libmariadb-dev - MariaDB Connector/C, development files
libmariadbclient-dev - MariaDB database development files
libmariadbclient-dev-compat - MariaDB database development files (libmysqlclient compatibility)

sudo apt-get install libmariadbclient-dev-compat

Makefile
all:
	gcc `mysql_config --cflags --libs`  -o connectSQL connectSQL.c
	gcc `mysql_config --cflags --libs`  -o createdb createdb.c
	gcc `mysql_config --cflags --libs`  -o create_populate create_populate.c
	gcc `mysql_config --cflags --libs`  -o retrieva_data retrieva_data.c

clean:
	rm connectSQL createdb create_populate retrieva_data



plugins:
fork
fifo
pipe
































Ubuntu 20.04 server

MariaDB Connector/C
If you plan to install MariaDB Connector/C on Linux using APT, YUM, or ZYpp, you will need to configure your system to use the proper package repository.

https://mariadb.com/docs/clients/connector-c/


sudo apt-get install libmariadb3 libmariadb-dev

build from source code
sudo apt-cache search [keyword]
gcc
OpenSSL
cmake
Curl
Kerberos V5

done
sudo apt-get install gcc
sudo apt-get install openssl
sudo apt-get install cmake
sudo apt-get install curl







source code
wget https://dlm.mariadb.com/1591653/Connectors/c/connector-c-3.1.12/mariadb-connector-c-3.1.12-src.tar.gz

tar zxvf mariadb-connector-c-3.1.12-src.tar.gz

sudo cmake ../mariadb-connector-c-3.1.12-src -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local

sudo cmake --build . --config Release






























wget https://dlm.mariadb.com/1591628/Connectors/c/connector-c-3.1.12/mariadb-connector-c-3.1.12-ubuntu-focal-amd64.tar.gz

tar zxvf mariadb-connector-c-3.1.12-ubuntu-focal-amd64.tar.gz
