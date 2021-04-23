#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

static char *host = "localhost";
static char *user = "pi";
static char *pass = "mysql";
static char *dbanme = "calculations";

unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;

int main(void)
{
  MYSQL *conn;

  conn = mysql_init(NULL);

  
  /* Use any MySQL API functions here */
  if (!(mysql_real_connect(conn, host, user, pass, dbanme, port, unix_socket, flag)))
  {
    fprintf(stderr, "could not initialize MySQL client library\n");
    exit(1);
  }
  printf("Connection Successful!\n");
  printf("MySQL client version: %s\n", mysql_get_client_info());

  mysql_library_end();

  return EXIT_SUCCESS;
}