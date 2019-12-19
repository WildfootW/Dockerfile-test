FROM ubuntu:bionic

RUN sed -i "s/\(archive.ubuntu.com\|security.ubuntu.com\)/free.nchc.org.tw/" "/etc/apt/sources.list" && \
    apt-get update && \
    apt-get -y upgrade

ENV MyUserName wildfootw

RUN apt-get install -y gdb gcc && \
    apt-get install -y zsh vim tmux && \
    apt-get install -y python3-dev python3-pip libglib2.0-dev libc6-dbg && \
    apt-get install -y locales && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set the locale
RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

COPY ./app /opt/app
WORKDIR /opt/app
RUN python3 -m pip install -r requirements.txt

RUN sed -i "s/\/root/\/home\/${MyUserName}/" "/etc/passwd"

