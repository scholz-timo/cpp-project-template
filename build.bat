IF EXIST build rm -r -f build

mkdir build
cd build
cmake -G Ninja -D CMAKE_RC_COMPILER="llvm-rc" .. 
ninja

@echo off
set "command=cd .. ^&^& build"
echo %command% >> build.bat
@echo on