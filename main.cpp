#include <iostream>
#include "SongList.h"
#include "M3uCreator.h"
#include "MbpCreator.h"
#include "dirent.h"

#include "clara.hpp"

using namespace std;
using namespace clara;

#define CANCION1 "\\\\TORTUGASNINJA02\\music\\El Canto del Loco\\2005 Zapatillas\\05 Besos.mp3"
#define CANCION2 "\\\\TORTUGASNINJA02\\music\\fun_\\2012 Some Nights\\03 fun. feat. Janelle Monáe - We Are Young.mp3"
#define CANCION3 "\\\\TORTUGASNINJA02\\music\\Los Piratas\\1993 Quiero hacerte gritar\\06 El sabor de las cosas.mp3"
//#define CANCION4 "\\\\TORTUGASNINJA02\\music\\Alicia Keys\\2012 Girl On Fire (Remixes)\\01 Alicia Keys - Girl On Fire.mp3"


#define DIRECTORY "D:\\Workspace\\projects\\MBPlaylist"



int main(int argc, char **argv)
{
  auto sourcePath = string{};
  auto targetPath = string{};
  bool overwrite = false;
  bool readSubfolders = false;
  bool cloneSubFolders = false;
  bool showHelp;

  auto cli
    = Help(showHelp)
    | Opt(sourcePath, "source path")["-s"]["--source"]("Source path").required()
    | Opt(targetPath, "target path")["-t"]["--target"]("Target path").required()
    | Opt(overwrite, "overwrite")["-o"]["--overwrite"]("Overwrite if file exists")
    | Opt(readSubfolders, "read subfolders")["-r"]["--recursively"]("Read subfolders recursively")
    | Opt(cloneSubFolders, "clone subfolders")["-c"]["--clone"]("Clone subfolder structure");

  auto result = cli.parse(Args(argc, argv));
  if(!result)
  {
    std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
    exit(1);
  }

  std::cout << sourcePath << std::endl;

  // Insert location of file

  SongList songList;
  SongList songListRead;

  songList.setDirectory("D:\\Users\\Fernando\\Music\\MusicBee\\");

  songList.insert(CANCION1);
  songList.insert(CANCION2);
  songList.insert(CANCION3);
  //songList.insert(CANCION4);

  MbpCreator mbpCreator;
  mbpCreator.save("D:\\test.mbp", songList);

  mbpCreator.read("D:\\test.mbp", songListRead);

  mbpCreator.save("D:\\test2.mbp", songListRead);

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

  SongList songListM3u;
  M3uCreator m3uCreator;

  bool result2 = m3uCreator.read("D:\\Vertigo.m3u", songListM3u);

  m3uCreator.save("D:\\test.m3u", songList);

  return 0;
}