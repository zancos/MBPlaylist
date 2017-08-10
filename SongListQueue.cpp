//
// Created by Fernando on 06/08/2017.
//

#include <fstream>
#include <cstdint>

#include "SongListQueue.h"


void SongListQueue::save(const std::string fullPath)
{
    std::ofstream f;
    f.open(fullPath, std::ios::binary);


    // header
    /*
    int32_t n = 0x00000004;
    char data[4];
    data[0] = static_cast<char>(n & 0xFF);
    data[1] = static_cast<char>((n >> 8) & 0xFF);
    data[2] = static_cast<char>((n >> 16) & 0xFF);
    data[3] = static_cast<char>((n >> 24) & 0xFF);
    f.write(data, 4);
    */

    bindValue(f, 0x00000004);

    
    // lengh of path + sizeof(version??)
    size_t pathLenght = directory.size() + sizeof(PLAYLIST_VERSION);
    size_t test = sizeof(PLAYLIST_VERSION);
    char bata[1];
    bata[0] = static_cast<char>(pathLenght & 0xFF);
    f.write(bata, 1);
    
    // 4 ceros
    int32_t n = 0x0000;
    char data[4];
    data[0] = static_cast<char>(n & 0xFF);
    data[1] = static_cast<char>((n >> 8) & 0xFF);
    f.write(data, 2);

    // song string
    f << directory;

    size_t version = PLAYLIST_VERSION;
    data[4];
    data[0] = static_cast<char>(version & 0xFF);
    data[1] = static_cast<char>((version >> 8) & 0xFF);
    f.write(data, 2);

    // end char 0xFFFFFFFF
    n = 0xFFFFFFFF;
    data[4];
    data[0] = static_cast<char>(n & 0xFF);
    data[1] = static_cast<char>((n >> 8) & 0xFF);
    data[2] = static_cast<char>((n >> 16) & 0xFF);
    data[3] = static_cast<char>((n >> 24) & 0xFF);
    f.write(data, 4);

    // reserved 0x00000000 ??
    n = 0x00000000;
    data[4];
    data[0] = static_cast<char>(n & 0xFF);
    data[1] = static_cast<char>((n >> 8) & 0xFF);
    data[2] = static_cast<char>((n >> 16) & 0xFF);
    data[3] = static_cast<char>((n >> 24) & 0xFF);
    f.write(data, 4);

    // end char 0xFFFFFFFF
    n = 0xFFFFFFFF;
    data[4];
    data[0] = static_cast<char>(n & 0xFF);
    data[1] = static_cast<char>((n >> 8) & 0xFF);
    data[2] = static_cast<char>((n >> 16) & 0xFF);
    data[3] = static_cast<char>((n >> 24) & 0xFF);
    f.write(data, 4);

    // number of songs in the list
    size_t size = songList.size();
    data[4];
    data[0] = static_cast<char>(size & 0xFF);
    data[1] = static_cast<char>((size >> 8) & 0xFF);
    data[2] = static_cast<char>((size >> 16) & 0xFF);
    data[3] = static_cast<char>((size >> 24) & 0xFF);
    f.write(data, 4);

    // Song list
    for (Song s : songList)
    {
        // song char size
        size_t length = s.length();
        char bata[1];
        bata[0] = static_cast<char>(length & 0xFF);
        f.write(bata, 1);

        // song string
        f << s.getSong();

        bindValue(f, 0xFFFFFFFF);
    }

    f.close();
}

template<class TYPE> void SongListQueue::bindValue(std::ofstream & file, TYPE value)
{
  size_t size = sizeof(value);
  char data[4]; //TODO solo es para 4bytes. Hay que ver como usar punteros
  for (int i = 0; i < size; i++)
  {
    data[i] = static_cast<char>((value >> (i * 8)) & 0xFF);
  }
  file.write(data, size);
}