@echo off
cd build

SET SRC_FILES=..\src\mkboards.cpp
REM SET SRC_FILES=%SRC_FILES% ..\src\mkboards.cpp

cl.exe /Zi %SRC_FILES% User32.lib
mkboards.exe

cd ..
