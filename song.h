//
// Created by fernando on 7/29/17.
//
#pragma once

#include <string>

class Song
{
    const std::string songPath;

public:
  Song(const std::string songPath) : songPath(songPath) {};
  virtual ~Song() {};

    std::string getSongPath() const { return this->songPath; };
    size_t pathLength() const { return songPath.length() ; };
};