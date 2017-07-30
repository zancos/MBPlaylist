//
// Created by fernando on 7/29/17.
//

#ifndef MBPLATLIST_SONGLIST_H
#define MBPLATLIST_SONGLIST_H


#include <vector>
#include "song.h"

class SongList
{
    std::vector<Song> songList;

public:
    Song getIndexSong(int index) { return songList[index]; };
    SongList getSongList() { return { }; };
    void setSongList(SongList songList) { };
    void setIndexSong(Song song) { };
    void pushSong(Song song) { songList.push_back(song); };
};


#endif //MBPLATLIST_SONGLIST_H
