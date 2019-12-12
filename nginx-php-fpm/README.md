# nginx & php-fpm docker
###### tags: `readme` `tools` `docker` `nginx` `php-fpm`
## tree
```
├── docker-compose.yml
├── site-conf
│   └── site.conf
└── web-root
    └── info.php
```
## files
### docker-compose.yml
```=
version: '3'
services:
    nginx: # machine name in the nginx-php-fpm network
        image: nginx:latest
        ports:
            - "8001:80" # host port:containter port
        volumes:
            - ./web-root:/web-root
            - ./site-conf:/etc/nginx/conf.d # need to cover while folder
        networks:
            - nginx-php-fpm
    php-fpm:
        image: php:7-fpm
        expose:
            - "9000" # expose port on 
        volumes:
            - ./web-root:/web-root # php-fpm need access to php file directly
        networks:
            - nginx-php-fpm # networks to join. reference to the name defined below
networks:
    nginx-php-fpm: # network name
```
### site.conf
```=
server {
    listen 80;
    server_name localhost;
    root /web-root;

    error_log  /var/log/nginx/error.log;
    access_log /var/log/nginx/access.log;

    location / {
        index index.php index.html;
    }

    location ~* \.php$ {
        fastcgi_pass    php-fpm:9000; # the machine name defined in docker-compose
        fastcgi_index   index.php;
        include         fastcgi_params;
        fastcgi_param   SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param   PATH_INFO $fastcgi_path_info;
    }
}
```