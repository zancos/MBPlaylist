#include <iostream>
#include "SongList.h"
#include "dirent.h"

using namespace std;

#define CANCION1 "\\\\TORTUGASNINJA02\\music\\El Canto del Loco\\2005 Zapatillas\\05 Besos.mp3"
#define CANCION2 "\\\\TORTUGASNINJA02\\music\\fun_\\2012 Some Nights\\03 fun. feat. Janelle Monáe - We Are Young.mp3"
#define CANCION3 "\\\\TORTUGASNINJA02\\music\\Los Piratas\\1993 Quiero hacerte gritar\\06 El sabor de las cosas.mp3"
#define CANCION4 "\\\\TORTUGASNINJA02\\music\\Alicia Keys\\2012 Girl On Fire (Remixes)\\01 Alicia Keys - Girl On Fire.mp3"


#define DIRECTORY "D:\\Workspace\\projects\\MBPlaylist"

int main()
{
  // Insert location of file

  SongList songList;
  SongList songListRead;

  songList.setDirectory("D:\\Users\\Fernando\\Music\\MusicBee\\");

  songList.insert(CANCION1);
  songList.insert(CANCION2);
  songList.insert(CANCION3);
  songList.insert(CANCION4);

  songList.save("D:\\test.mbp");

  songListRead.load("D:\\test.mbp");


  DIR *dpdf;
  struct dirent *epdf;

  dpdf = opendir(DIRECTORY);
  if (dpdf != NULL)
  {
    while (epdf == readdir(dpdf))
    {
      //print("Filename: %s", epdf->d_name);
      std::cout << epdf->d_name << std::endl;
    }
  }

  return 0;
}