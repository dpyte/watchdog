FROM ubuntu:latest

RUN apt update -y && apt upgrade -y
RUN apt install build-essential ccache cmake ninja-build -y
RUN apt install xauth xorg xserver-xorg dbus libcanberra-gtk-module libx11-6 firefox -y
RUN dbus-uuidgen > /etc/machine-id

CMD /usr/bin/firefox
