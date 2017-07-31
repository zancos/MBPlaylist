#include <iostream>
#include <fstream>
#include <array>
#include "songList.h"


using namespace std;

int main()
{
    SongList songList;
    Song song;

    song.setSong(std::string("\\\\TORTUGASNINJA\\OpenShare\\Music\\El Canto del Loco\\2005 Zapatillas\\05 Besos.mp3"));
    songList.pushSong(song);

    song.setSong(std::string("\\\\TORTUGASNINJA\\OpenShare\\Music\\fun_\\2012 Some Nights\\03 fun. feat. Janelle Monáe - We Are Young.mp3"));
    songList.pushSong(song);

    song.setSong(std::string("\\\\TORTUGASNINJA\\OpenShare\\Music\\Los Piratas\\1993 Quiero hacerte gritar\\06 El sabor de las cosas.mp3"));
    songList.pushSong(song);

    ofstream f;
    f.open("pruebastd.mbp", ios::binary);


    for (int i = 0; i < songList.size(); i++)
    {
        f << songList.getIndexSong(i).getSizeOf();
        f << songList.getIndexSong(i).getSong();
    }

    /*
    std:array<char, 4> array1 = {0,0,0,99};
    f << cancion1.length();
    //f << array1;
    std::cout << cancion1.length();
    f << cancion1.toStdString();
    */

    f.close();

    //std::cout << songList.getIndexSong(0).getSong() << std::endl;

    return 0;
}