FROM python:3.8.13

WORKDIR /usr/src/app
COPY . .

RUN cat info.xml
RUN python -m unittest test.py
