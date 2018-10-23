#ifndef CONTAINER_H
#define CONTAINER_H

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "tcpserver.h"
#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"

using GroupPtr = std::shared_ptr<Group>;
using Multimedias = std::map<string, MultimerdiaPtr>;
using Groups = std::map<string, GroupPtr>;


using namespace cppu;

class Container{

private:
  Multimedias MediaCont;
  Groups      GroupsCont;

public:
  Container(){};
  ~Container(){};

  MultimerdiaPtr makePhoto(double latitud, double longitud, const string& name,
    const string& dir);
  MultimerdiaPtr makeVideo(double duration, const string& name, const string& dir );
  MultimerdiaPtr makeFilm(int duration, const string& name, const string& dir,
     int * chapters_ , int chaptersnumber);

  GroupPtr makeGroup(const string& name);

  void search_Show(const string& name, ostream &s) const;
  void play(const string &name) const;
  bool processRequest(TCPConnection& cnx, const string& request, string& response);
  MultimerdiaPtr make(ifstream &is, string &theClass);
  bool readFile(const string &inFile);
  bool writeFile(const string &outFile);
};
#endif
