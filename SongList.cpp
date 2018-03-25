//
// Created by Fernando on 06/08/2017.
//

#include <fstream>
#include <bits/unique_ptr.h>

#include "SongList.h"

using namespace std;

uint8_t  UINT8_NULL = static_cast<uint8_t>(0x00);
uint8_t  UINT8_FULL = static_cast<uint8_t>(0xFF);
uint16_t UINT16_NULL = static_cast<uint16_t>(0x0000);
uint16_t UINT16_FULL = static_cast<uint16_t>(0xFFFF);
uint32_t UINT32_NULL = static_cast<uint32_t>(0x00000000);
uint32_t UINT32_FULL = static_cast<uint32_t>(0xFFFFFFFF);
uint64_t UINT64_NULL = static_cast<uint64_t>(0x0000000000000000);
uint64_t UINT64_FULL = static_cast<uint64_t>(0xFFFFFFFFFFFFFFFF);

/* Header info

 4 bytes  - Header file
 1 byte   - Directory length
 2 bytes  - Null value
 ? bytes  - String containing the file folder where MusicBee list is saved
 4 bytes  - File version (in old version files, song list is reversed)
 4 bytes  - Full value with all bits set
 4 bytes  - Void value with all bits unset (any reserved field?)
 4 bytes  - Full value with all bits set
 4 bytes  - Song list counter

 --- songs

 1 byte   - Number of characters that composes the full path song
 ? bytes  - String containing the full path of any song
 4 bytes  - FUll value with all bits set

 *** */

void SongList::save(const std::string fullPath)
{
  std::ofstream f;
  f.open(fullPath, std::ios::binary);

  bindValue(f, 0x00000004);                                                                   // header
  uint8_t pathLenght = static_cast<uint8_t>(directory.size() + sizeof(PLAYLIST_VERSION));     // length of path + sizeof(version??)
  bindValue(f, pathLenght);
  bindValue(f, UINT16_NULL);                                                                  // 4 ceros, 2 bytes
  f << directory;                                                                             // song string
  bindValue(f, PLAYLIST_VERSION);                                                             // Version?
  bindValue(f, UINT32_FULL);                                                                  // end char 0xFFFFFFFF
  bindValue(f, UINT32_NULL);                                                                  // reserved 0x00000000 ??
  bindValue(f, UINT32_FULL);                                                                  // end char 0xFFFFFFFF
  bindValue(f, static_cast<uint32_t>(songList.size()));                                       // songs count in the list

  songList.reverse();
  for (Song s : songList)                                                                     // Song list
  {
    bindValue(f, static_cast<uint8_t>(s.length()));                                           // song char size
    f << s.getSongPath();                                                                         // song string
    bindValue(f, UINT32_FULL);                                                                 // end char 0xFFFFFFFF
  }

  f.close();
}

template<class TYPE>
void SongList::bindValue(std::ofstream & file, TYPE value)
{
  size_t size = sizeof(value);
  char * lata = new char[sizeof(value)];

  for (int i = 0; i < size; i++)
  {
    lata[i] = static_cast<char>((value >> (i * 8)) & 0xFF);
  }
  file.write(lata, size);
}

void SongList::load(std::string fullPath)
{
  std::ifstream f(fullPath, ios::binary | ios::app);

  readValue(f, 4);
  uint16_t dirVerLen = char2uint8_t(readValue(f, 1));
  size_t dirLen = (dirVerLen - sizeof(PLAYLIST_VERSION));
  readValue(f, 2);
  this->directory = readTextValue(f, (dirLen));
  this->version = char2uint16_t(readValue(f, 4));
  readValue(f, 4);
  readValue(f, 4);
  readValue(f, 4);
  this->songCount = char2uint32_t(readValue(f, 4));

  for (int i = 0; i < songCount; i++)
  {
    uint8_t len = char2uint8_t(readValue(f, 1));
    string songPath = readTextValue(f, len);
    this->songList.push_back(Song(songPath));
    readValue(f, 4);
  }
}

uint8_t SongList::char2uint8_t(char * value)
{
  return static_cast<uint8_t>((value[0] << 0) & 0x00FF);
}

uint16_t SongList::char2uint16_t(char * value)
{
  uint16_t number;
  number = (uint16_t) (((value[1] << 8) & 0xFF00)
                       | ((value[0] << 0) & 0x00FF));

  return number;
}

uint32_t SongList::char2uint32_t(char * value)
{
  return ((value[3] << 24) & 0xFF000000)
         | ((value[2] << 16) & 0x00FF0000)
         | ((value[1] << 8 ) & 0x0000FF00)
         | ((value[0] << 0 ) & 0x000000FF);
}

char * SongList::readValue(std::ifstream & file,/* int begin,*/ int size)
{
  char * buffer = new char[size];
  file.read(buffer, size);
  buffer[size] = '\0';

  return buffer;
}

string SongList::readTextValue(std::ifstream & file, size_t size)
{
  char * buffer = new char[size];
  file.read(buffer, size);
  buffer[size] = '\0';

  return buffer;
}