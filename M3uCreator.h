//
// Created by Fernando on 01/04/2018.
//

#pragma once


#include "SongList.h"

class M3uCreator
{
public:
  static bool read(const std::string path, SongList & slist);
  static bool save(std::string path, const SongList & slist);
};