FROM buildpack-deps:bionic

RUN apt-get update
RUN apt-get install -y cmake
RUN apt-get install -y ninja-build
RUN apt-get install -y python

COPY ./ project/

RUN (cd project/ && mkdir build && cd build &&  cmake -G Ninja .. -DTESTING_ONLY=ON)
RUN (cd project/build/ && ninja)
RUN (project/build/bin/run)
