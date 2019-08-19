@setlocal EnableDelayedExpansion

:loop
IF NOT "%1"=="" (
    IF "%1"=="-run_tests" (
        SET run_tests=%2
        SHIFT
    )
    IF "%1"=="-run_only_tests" (
        SET run_only_tests=%2
        SHIFT
    )
    SHIFT
    GOTO :loop
)

IF EXIST build (
	cd build
	goto _build
) ELSE (
	mkdir build
	cd build
)

set "args="

if DEFINED run_tests (
	set "args=%args% -DTESTING=ON"
)

if DEFINED run_only_tests (
	set "args=%args% -DTESTING_ONLY=ON"
)

cmake -G Ninja %args% -DCMAKE_RC_COMPILER="llvm-rc" .. 

@echo off
set "command=cd .. ^&^& build"
echo %command% >> build.bat
@echo on


:_build

ninja