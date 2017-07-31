//
// Created by fernando on 7/29/17.
//

#ifndef MBPLATLIST_SONGLIST_H
#define MBPLATLIST_SONGLIST_H


#include <vector>
#include "song.h"

class SongList
{
    std::string directory;
    std::vector<Song> songList;

public:
    Song getIndexSong(int index) { return songList[index]; };
    std::vector<Song> getSongList() { return songList; };
    void setSongList(std::vector<Song> songList) { this->songList = songList; };
    void setIndexSong(int index, Song song) { songList[index] = song; };
    void pushSong(Song song) { songList.push_back(song); };
    std::string getDirectory() { return directory; };
    void setDirectory(std::string directory) { this->directory = directory; };
    int size() { return songList.size(); };
};


#endif //MBPLATLIST_SONGLIST_H
