#include <iostream>
#include "SongListQueue.h"


using namespace std;

#define CANCION1 "\\\\TORTUGASNINJA02\\music\\El Canto del Loco\\2005 Zapatillas\\05 Besos.mp3"
#define CANCION2 "\\\\TORTUGASNINJA02\\music\\fun_\\2012 Some Nights\\03 fun. feat. Janelle Monáe - We Are Young.mp3"
#define CANCION3 "\\\\TORTUGASNINJA02\\music\\Los Piratas\\1993 Quiero hacerte gritar\\06 El sabor de las cosas.mp3"

int main()
{

    // Insert location of file

    SongListQueue songList;

    songList.setDirectory("D:\\Users\\Fernando\\Music\\MusicBee\\");

    songList.insert(CANCION1);
    songList.insert(CANCION2);
    songList.insert(CANCION3);

    songList.save("D:\\test.mbp");


    return 0;
}