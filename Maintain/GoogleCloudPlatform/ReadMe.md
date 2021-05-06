Setting Up LAMP on Compute Engine
https://cloud.google.com/community/tutorials/setting-up-lamp

https://help.ubuntu.com/community/ApacheMySQLPHP#Troubleshooting_Phpmyadmin_.26_mysql-workbench

https://help.ubuntu.com/community/phpMyAdmin

Important

Setting SQL User



sudo nano /etc/apache2/apache2.conf

Include the following line at the bottom of the file, save and quit.

Include /etc/phpmyadmin/apache.conf

sudo systemctl restart apache2
