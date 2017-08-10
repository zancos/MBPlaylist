#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <queue>
#include "SongListQueue.h"


using namespace std;

#define CANCION1 "\\\\TORTUGASNINJA\\OpenShare\\Music\\El Canto del Loco\\2005 Zapatillas\\05 Besos.mp3"
#define CANCION2 "\\\\TORTUGASNINJA\\OpenShare\\Music\\fun_\\2012 Some Nights\\03 fun. feat. Janelle Monáe - We Are Young.mp3"
#define CANCION3 "\\\\TORTUGASNINJA\\OpenShare\\Music\\Los Piratas\\1993 Quiero hacerte gritar\\06 El sabor de las cosas.mp3"

int main()
{

    // Insert location of file

    SongListQueue songList;

    songList.setDirectory("C:\\Users\\Fernando\\Music\\MusicBee\\");

    songList.insert(CANCION1);
    songList.insert(CANCION2);
    songList.insert(CANCION3);

    songList.save("test.mbp");


    return 0;
}