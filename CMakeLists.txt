cmake_minimum_required(VERSION 3.6)
project(MBPlatlist)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp globals.h song.cpp song.h SongList.h SongList.cpp SongList.cpp SongList.h M3uCreator.cpp M3uCreator.h MbpCreator.cpp MbpCreator.h clara.hpp clara_textflow.hpp md5.cpp md5.h)
add_executable(MBPlatlist ${SOURCE_FILES})