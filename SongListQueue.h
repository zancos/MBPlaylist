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

public:
    SongListQueue() { };
    virtual ~SongListQueue() { };

    const std::string getDirectory() const { return directory; };
    std::string setDirectory(std::string dir) { directory = dir; };

    void save();
    void insert(Song song) {songList.push_front(song); };
};
