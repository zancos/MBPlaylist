cmake_minimum_required(VERSION 3.6)
project(MBPlatlist)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp song.cpp song.h songList.cpp songList.h SongListQueue.h SongListQueue.cpp SongListQueue.cpp SongListQueue.h)
add_executable(MBPlatlist ${SOURCE_FILES})