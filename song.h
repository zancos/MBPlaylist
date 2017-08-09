//
// Created by fernando on 7/29/17.
//
#pragma once

#include <string>

class Song
{
public:
    std::string songTittle;

public:
    void setSong(std::string song) { this->songTittle = song; };
    std::string getSong() { return this->songTittle; };
    size_t length() { return songTittle.length() ; };

};