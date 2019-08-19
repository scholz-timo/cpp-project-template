FROM buildpack-deps:bionic

RUN apt-get update
RUN apt-get install -y cmake
RUN apt-get install -y ninja-build
RUN apt-get install -y python

COPY ./ project/

ARG run_tests=0
ARG run_only_tests=0

RUN (chmod 777 project/build.sh)
RUN (cd project && sh build.sh run_tests=${run_tests} run_only_tests=${run_only_tests})

CMD [ "project/build/bin/run" ]