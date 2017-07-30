#include <iostream>
#include "songList.h"


using namespace std;

int main()
{
    SongList songList;
    Song song;

    song.setSong(std::string("C:\\directorio\\cancion1.mp3"));
    songList.pushSong(song);

    std::cout << songList.getIndexSong(0).getSong() << std::endl;

    return 0;
}