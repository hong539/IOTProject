#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *host = "localhost";
static char *user = "pi";
static char *pass = "mysql";
static char *dbanme = "testc";
static char *selrow_Name = "SELECT humidity FROM SensorData WHERE id=(SELECT max(id) FROM SensorData)";
//Better yet, don't do a "SELECT * FROM mytable" in a program. It would be much better to name the fields you expect, so that you can be sure of the order of the fields returned.

unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
    fprintf(stderr, "mysql_init() failed\n");
    exit(1);
  }

  if (mysql_real_connect(con, host, user, pass, dbanme, port, unix_socket, flag) == NULL)
  {
    finish_with_error(con);
  }

  //Better yet, don't do a "SELECT * FROM mytable" in a program. It would be much better to name the fields you expect, so that you can be sure of the order of the fields returned.
  if (mysql_query(con, selrow_Name))
  {
    finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
    finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result)))
  {
    for (int i = 0; i < num_fields; i++)
    {
      printf("%s ", row[i] ? row[i] : "NULL");
    }

    printf("\n");
  }

  mysql_free_result(result);
  mysql_close(con);

  exit(0);
}