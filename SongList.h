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
  using songList_t = std::list<Song>;
  using iterator = songList_t::iterator;
  using const_iterator = songList_t::const_iterator;

  int version;

  std::string directory;
  songList_t songList;

  int songCount;

public:
  SongList() : songCount(0) { };
  virtual ~SongList() { };

  iterator begin() { return songList.begin(); }
  iterator end() { return songList.end(); }
  const_iterator begin() const { return songList.begin(); }
  const_iterator end() const { return songList.end(); }
  const_iterator cbegin() const { return songList.cbegin(); }
  const_iterator cend() const { return songList.cend(); }


  std::string getDirectory() const { return directory; };
  void setDirectory(std::string d) { directory = d; };
  int getVersion() const { return version; }
  void setVersion(const int v) { version = v; }
  int getSongCount() const { return songCount; }
  void setSongCount(int sCount) { songCount = sCount; }

  // TODO: to be deleted
  std::list<Song> getSongListVector() const { return songList; }

  void insert(Song song) { songList.push_front(song); songCount++; }
  void insert(std::string songPath) { songList.push_back(Song(songPath)); songCount++; }
};
