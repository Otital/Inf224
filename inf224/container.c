#include "Container.h"

MultimerdiaPtr Container::makePhoto(double latitud, double longitud, const
  string& name, const string& dir){
    MediaCont[name] = MultimerdiaPtr(new Photo(latitud, longitud, name, dir ));
    return MediaCont[name];
}

MultimerdiaPtr Container::makeVideo(double duration, const string& name,
  const string& dir ){
    MediaCont[name] = MultimerdiaPtr(new Video(duration, name, dir ));
    return MediaCont[name];
}

MultimerdiaPtr Container::makeFilm(int duration, const string& name,
  const string& dir, int * chapters_ , int chaptersnumber){
    MediaCont[name] = MultimerdiaPtr(new Film(duration, name, dir, chapters_, chaptersnumber ));
    return MediaCont[name];
}

GroupPtr Container::makeGroup(const string& name){
    GroupsCont[name] = GroupPtr(new Group(name));
    return GroupsCont[name];
}

void Container::Search_Show(const string& name, ostream &s)const{
  auto element = MediaCont.find(name);
   if (element != MediaCont.end()){
     s<<"A multimedia element "<<name<< " has been found: \n";
     element->second->show(s);
   }else
      s << "No multimedia found" << endl;
  auto group = groupFolder.find(name);
     if (group != groupFolder.end()){
       s<<"A group "<< name<< " has been found: \n";
       element->second->show(s);
     }
     else
      s << "No group found" << endl;
}

void Container::play(const string& name) const{
  auto element = MediaCont.find(name);
   if (element != MediaCont.end()){
      element->second->play(s);
   }else
      s << "No multimedia found" << '\n';
}
