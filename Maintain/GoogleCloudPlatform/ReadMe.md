Setting Up LAMP on Compute Engine
https://cloud.google.com/community/tutorials/setting-up-lamp

https://help.ubuntu.com/community/ApacheMySQLPHP#Troubleshooting_Phpmyadmin_.26_mysql-workbench


Important!!!

https://askubuntu.com/questions/763336/cannot-enter-phpmyadmin-as-root-mysql-5-7
Setting SQL User
Create a user for phpMyAdmin

sudo mysql

CREATE USER 'username'@'localhost' IDENTIFIED BY 'password';

remind this line!!! ON *.*
GRANT ALL PRIVILEGES ON *.* TO 'username'@'localhost' WITH GRANT OPTION;

FLUSH PRIVILEGES;


If you dont' setting up the above, your apache server will show you Not Found. lol


sudo nano /etc/apache2/apache2.conf

Include the following line at the bottom of the file, save and quit.

Include /etc/phpmyadmin/apache.conf

sudo systemctl restart apache2
