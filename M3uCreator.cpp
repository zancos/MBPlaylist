//
// Created by Fernando on 01/04/2018.
//

#include "M3uCreator.h"

#include <fstream>
#include <sstream>

using namespace std;

bool M3uCreator::read(const std::string path, SongList &slist)
{
  std::ifstream f(path, ios::out);

  std::stringstream buffer;

  string line;
  while (std::getline(buffer, line))
  {
    slist.insert(Song(line));
  }

  f.close();
  return true;
}

bool M3uCreator::save(const std::string path, const SongList &slist)
{
  std::ofstream f;
  f.open(path, ios::out);

  for (Song s : slist)
  {
    f << s.getSongPath() << endl;
  }

  f.close();
}