FROM ubuntu:18.04
ENV MyUserName wildfootw
ENV GDB_Server_Port 56147

RUN useradd -m ${MyUserName} && usermod -a -G sudo ${MyUserName} && echo /bin/bash | chsh ${MyUserName}
#RUN echo '${MyUserName}:MyPa55w0rd' | chpasswd

RUN sed -i 's/\(archive.ubuntu\|security.ubuntu\)/tw.archive.ubuntu/' /etc/apt/sources.list && \
    apt-get update && \
    apt-get -y upgrade && \
#    apt-get install -y binutils && \
    apt-get install -y gdb gcc && \
    apt-get install -y vim && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

EXPOSE ${GDB_Server_Port}
#ENTRYPOINT ["/bin/sh"]
ENTRYPOINT ["/usr/bin/gdbserver"]
CMD [":56147", "/home/wildfootw/a.out"]

