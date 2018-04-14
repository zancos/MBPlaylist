//
// Created by Fernando on 06/08/2017.
//

#include <fstream>
#include <bits/unique_ptr.h>

#include "SongList.h"

using namespace std;

/* Header info

 4 bytes  - Header file
 1 byte   - Directory length
 2 bytes  - Null value
 ? bytes  - String containing the file folder where MusicBee list is saved
 4 bytes  - File version (in old version files, song list is reversed)
 4 bytes  - Full value with all bits set
 4 bytes  - Void value with all bits unset (any reserved field?)
 4 bytes  - Full value with all bits set
 4 bytes  - Song list counter

 --- songs

 1 byte   - Number of characters that composes the full path song
 ? bytes  - String containing the full path of any song
 4 bytes  - FUll value with all bits set

 *** */