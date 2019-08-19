#!/bin/bash

helpFunction()
{
   echo ""
   echo "Usage: $0 -run_tests=1 -run_only_tests=1"
   echo -e "\t-run_tests Creates a executable that runs the unit tests at the start."
   echo -e "\t-run_only_tests Creates a executable that only runs the unit tests."
   exit 1 # Exit script after printing help
}

while getopts "a:b:c:" opt
do
   case "$opt" in
      run_tests ) run_tests="$OPTARG" ;;
      run_only_tests ) run_only_tests="$OPTARG" ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done

if [ -d "build" ]; then
    cd build
else
    mkdir build
    cd build

    args=''

    if [ "x$run_tests" = 'x1' ]; then
        args="${args} -DTESTING=ON"
    fi
    if [ "x$run_only_tests" = 'x1' ]; then
        args="${args} -DONLY_TESTING=ON"
    fi

    cmake -G Ninja ${args} ..

    command="cd .. && build"
    echo "${command}" >> build.sh
fi

ninja