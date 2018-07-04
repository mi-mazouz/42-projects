FROM php:7.2.2-apache

LABEL version="0.1"

RUN apt-get update && apt-get install -y libpng-dev libjpeg-dev wget
RUN  wget http://pear.php.net/go-pear.phar && php go-pear.phar && pear install Mail Auth_SASL pear/Net_SMTP
RUN docker-php-ext-configure gd --with-png-dir=/usr/include/ --with-jpeg-dir=/usr/include/
RUN docker-php-ext-install pdo_mysql gd