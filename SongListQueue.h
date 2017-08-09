//
// Created by Fernando on 06/08/2017.
//
#pragma once

#include <iostream>
#include <list>

#include "song.h"

class SongListQueue
{
    std::string directory;
    std::list<Song> songList;

    Song song;

public:
    SongListQueue() { };
    virtual ~SongListQueue() { };

    const std::string getDirectory() const { return directory; };
    void setDirectory(std::string d) { directory = d; };

    void save(const std::string fullPath);
    void insert(std::string songStr) { this->song.setSong(songStr); songList.push_front(song); };
};
