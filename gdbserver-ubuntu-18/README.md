# GDBserver in docker container
Ubuntu GLIBC 2.27-3ubuntu1

## usage
1. copy elf to ./opt/docker-share/a.out
2. run `docker-compose up`
3. nc localhost:7071 to connect to the program
4. `(gdb) target remote :7070`
5. debug
