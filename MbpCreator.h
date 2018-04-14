//
// Created by Fernando on 12/04/2018.
//

#pragma once


#include "SongList.h"

class MbpCreator
{
public:
  static bool read(const std::string path, SongList &slist);
  static bool save(std::string path, const SongList &slist);

private:
  template<class TYPE>
  static void bindValue(std::ofstream & file, TYPE value);
  static char * readValue(std::ifstream & file,/* int begin,*/ int size);
  static std::string readTextValue(std::ifstream & file, size_t size);

  static uint8_t char2uint8_t(char * value);
  static uint16_t char2uint16_t(char * value);
  static uint32_t char2uint32_t(char * value);
};
