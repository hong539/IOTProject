all:
	gcc `mysql_config --cflags --libs`  -o connectSQL connectSQL.c
	gcc `mysql_config --cflags --libs`  -o createdb createdb.c
	gcc `mysql_config --cflags --libs`  -o create_populate create_populate.c
	gcc `mysql_config --cflags --libs`  -o retrieva_data retrieva_data.c
	gcc `mysql_config --cflags --libs`  -o read_humidility read_humidility.c

clean:
	rm connectSQL createdb create_populate retrieva_data read_humidility