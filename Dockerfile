FROM buildpack-deps:bionic

RUN apt-get update
RUN apt-get install -y cmake
RUN apt-get install  ninja-build

COPY ./ project/

RUN (cd project/ && mkdir build && cd build &&  cmake -G Ninja ..)
RUN (cd project/build/ && ninja)
RUN (project/build/bin/run)