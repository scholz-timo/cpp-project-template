FROM buildpack-deps:jessie

RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|sudo apt-key add

RUN apt-get update
RUN apt-get install -y cmake
RUN apt-get install -y clang-7 lldb-7 lld-7