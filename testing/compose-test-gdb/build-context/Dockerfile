FROM ubuntu:latest
ENV user_name WildfootW
MAINTAINER ${user_name}

#ADD . /home/${user_name}
#WORKDIR /home/${user_name}
RUN useradd -m ${user_name} && usermod -a -G sudo ${user_name} && echo /bin/bash | chsh ${user_name}
RUN echo '${user_name}:screencast' | chpasswd

RUN sed -i 's/\(archive.ubuntu\|security.ubuntu\)/tw.archive.ubuntu/' /etc/apt/sources.list && apt-get update
RUN apt-get install -y openssh-server && mkdir /var/run/sshd
RUN apt-get install -y sudo && sed -i 's/%sudo.*/%sudo   ALL=(ALL:ALL) NOPASSWD:ALL/' /etc/sudoers
RUN apt-get install -y locales && (echo 149; echo 3) | dpkg-reconfigure locales
RUN apt-get install -y tmux binutils gdb strace ltrace nmap netcat

EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]

