#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <queue>
#include "songList.h"
#include "SongListQueue.h"


using namespace std;

#define CANCION1 "\\\\TORTUGASNINJA\\OpenShare\\Music\\El Canto del Loco\\2005 Zapatillas\\05 Besos.mp3"
#define CANCION2 "\\\\TORTUGASNINJA\\OpenShare\\Music\\fun_\\2012 Some Nights\\03 fun. feat. Janelle Monáe - We Are Young.mp3"
#define CANCION3 "\\\\TORTUGASNINJA\\OpenShare\\Music\\Los Piratas\\1993 Quiero hacerte gritar\\06 El sabor de las cosas.mp3"

int main()
{
    SongList songList;

    songList.pushSong(CANCION1);
    songList.pushSong(CANCION2);
    songList.pushSong(CANCION3);


    ofstream fv;
    fv.open("pruebas.mbp", ios::binary);
    ofstream fq;


    SongListQueue canciones;
    song.setSong(std::string(CANCION1));
    canciones.insert(song);
    song.setSong(std::string(CANCION2));
    canciones.insert(song);
    song.setSong(std::string(CANCION3));
    canciones.insert(song);
    canciones.setDirectory("C:\\Users\\Fernando\\Music\\MusicBee\\");

    canciones.save();

    //std::reverse(numeros.begin(), numeros.end());

    std::vector<Song> songListVector = songList.getSongList();
    std::reverse(songListVector.begin(), songListVector.end());
    for (Song s : songListVector)
    {
        fv << s.getSong();
        fv << s.length();
        int32_t n = 0xFFFFFFFF;
        char data[4];
        data[0] = static_cast<char>(n & 0xFF);
        data[1] = static_cast<char>((n >> 8) & 0xFF);
        data[2] = static_cast<char>((n >> 16) & 0xFF);
        data[3] = static_cast<char>((n >> 24) & 0xFF);
        fv.write(data, 4);


    }

    /*
    std:array<char, 4> array1 = {0,0,0,99};
    f << cancion1.length();
    //f << array1;
    std::cout << cancion1.length();
    f << cancion1.toStdString();
    */

    fv.close();

    //std::cout << songList.getIndexSong(0).getSong() << std::endl;

    return 0;
}