cmake_minimum_required(VERSION 3.6)
project(MBPlatlist)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp globals.h song.cpp song.h SongList.h SongList.cpp SongList.cpp SongList.h)
add_executable(MBPlatlist ${SOURCE_FILES})