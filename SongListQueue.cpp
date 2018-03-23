//
// Created by Fernando on 06/08/2017.
//

#include <fstream>

#include "SongListQueue.h"


void SongListQueue::save(const std::string fullPath)
{
  std::ofstream f;
  f.open(fullPath, std::ios::binary);

  bindValue(f, 0x00000004);                                                                   // header
  uint8_t pathLenght = static_cast<uint8_t>(directory.size() + sizeof(PLAYLIST_VERSION));     // lengh of path + sizeof(version??)
  bindValue(f, pathLenght);
  bindValue(f, static_cast<uint16_t>(0x0000));                                                // 4 ceros, 2 bytes
  f << directory;                                                                             // song string
  bindValue(f, PLAYLIST_VERSION);                                                             // Version?
  bindValue(f, static_cast<uint32_t>(0xFFFFFFFF));                                            // end char 0xFFFFFFFF
  bindValue(f, static_cast<uint32_t>(0x00000000));                                            // reserved 0x00000000 ??
  bindValue(f, static_cast<uint32_t>(0xFFFFFFFF));                                            // end char 0xFFFFFFFF
  bindValue(f, static_cast<uint32_t>(songList.size()));                                       // number of songs in the list

  songList.reverse();
  for (Song s : songList)                                                                     // Song list
  {
    bindValue(f, static_cast<uint8_t>(s.length()));                                           // song char size
    f << s.getSong();                                                                         // song string
    bindValue(f, 0xFFFFFFFF);                                                                 // end char 0xFFFFFFFF
  }

  f.close();
}

template<class TYPE> void SongListQueue::bindValue(std::ofstream & file, TYPE value)
{
  size_t size = sizeof(value);
  char * lata = new char[sizeof(value)];

  for (int i = 0; i < size; i++)
  {
    lata[i] = static_cast<char>((value >> (i * 8)) & 0xFF);
  }
  file.write(lata, size);
}