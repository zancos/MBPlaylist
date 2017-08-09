//
// Created by Fernando on 06/08/2017.
//

#include <fstream>

#include "SongListQueue.h"


void SongListQueue::save()
{
    std::ofstream f;
    f.open("pruebaQueue.mbp", std::ios::binary);



    int32_t n = 0x00000000;
    char data[4];
    data[0] = static_cast<char>(n & 0xFF);
    data[1] = static_cast<char>((n >> 8) & 0xFF);
    data[2] = static_cast<char>((n >> 16) & 0xFF);
    data[3] = static_cast<char>((n >> 24) & 0xFF);
    f.write(data, 4);

    n = 0xFFFFFFFF;
    data[4];
    data[0] = static_cast<char>(n & 0xFF);
    data[1] = static_cast<char>((n >> 8) & 0xFF);
    data[2] = static_cast<char>((n >> 16) & 0xFF);
    data[3] = static_cast<char>((n >> 24) & 0xFF);
    f.write(data, 4);

    n = songList.size();
    data[4];
    data[0] = static_cast<char>(n & 0xFF);
    data[1] = static_cast<char>((n >> 8) & 0xFF);
    data[2] = static_cast<char>((n >> 16) & 0xFF);
    data[3] = static_cast<char>((n >> 24) & 0xFF);
    f.write(data, 4);

    for (Song s : songList)
    {
        int8_t m = s.length();
        char bata[1];
        bata[0] = static_cast<char>(m & 0xFF);
        f.write(bata, 1);

        f << s.getSong();

        n = 0xFFFFFFFF;
        data[4];
        data[0] = static_cast<char>(n & 0xFF);
        data[1] = static_cast<char>((n >> 8) & 0xFF);
        data[2] = static_cast<char>((n >> 16) & 0xFF);
        data[3] = static_cast<char>((n >> 24) & 0xFF);
        f.write(data, 4);
    }

    f.close();
}
