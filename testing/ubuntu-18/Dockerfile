FROM ubuntu:bionic

RUN sed -i "s/\(archive.ubuntu.com\|security.ubuntu.com\)/free.nchc.org.tw/" "/etc/apt/sources.list" && \
    apt-get update && \
    apt-get -y upgrade

ENV GDBPORT 7070
ENV EXEPORT 7071
EXPOSE ${GDBPORT} ${EXEPORT}

RUN apt-get install -y gdbserver socat && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

CMD ["socat", "TCP-LISTEN:7071,fork,reuseaddr", "EXEC:gdbserver \\:7070 /opt/app/a.out"]
#CMD ["sh", "-c", "socat TCP-LISTEN:${EXEPORT},fork,reuseaddr EXEC:'gdbserver \\:${GDBPORT} /opt/app/a.out'"]
# ${GDBPORT} does not expand
