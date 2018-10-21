#ifndef CONTEINER_H
#define CONTEINER_H

#include <map>
#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"

using GroupPtr = std::shared_ptr<Group>;
using Multimedias = std::map<string, MultimerdiaPtr>;
using Groups = std::map<string, GroupPtr>;


class Conteiner {

private:
  Multimedias MediaCont;
  Groups      GroupsCont;

public:
  Container();
  ~Container();

  MultimerdiaPtr MakePhoto(double latitud, double longitud, const string& name,
    const string& dir);
  MultimerdiaPtr makeVideo(double duration, const string& name, const string& dir );
  MultimerdiaPtr makeFilm(int duration, const string& name, const string& dir,
     int * chapters_ , int chaptersnumber);

  GroupPtr makeGroup(const string& name);

  void search_Show(const string& name, ostream &s) const;
  void play(const string& name) const;
}
#endif
