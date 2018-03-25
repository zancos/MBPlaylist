//
// Created by Fernando on 06/08/2017.
//
#pragma once

#include <iostream>
#include <list>
#include <cstdint>
#include <memory>

#include "globals.h"
#include "song.h"


class SongList
{
  int version;

  std::string directory;
  std::list<Song> songList;

  int songCount;

public:
  SongList() { };
  virtual ~SongList() { };

  const std::string getDirectory() const { return directory; };
  void setDirectory(std::string d) { directory = d; };

  void load(std::string fullPath);
  void save(const std::string fullPath);
  void insert(Song song) { songList.push_front(song); }
  void insert(std::string songPath) { songList.push_back(Song(songPath)); }

private:
  template<class TYPE>
  void bindValue(std::ofstream & file, TYPE value);
  char * readValue(std::ifstream & file,/* int begin,*/ int size);
  std::string readTextValue(std::ifstream & file, size_t size);

  uint8_t char2uint8_t(char * value);
  uint16_t char2uint16_t(char * value);
  uint32_t char2uint32_t(char * value);
};
