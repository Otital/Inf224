#include "Video.h"

void Video::show(ostream & s){
  Multimedia::show(s);
  s<<"Video duration: "<< getDuration() <<" " ;
}

void Video::playMultimedia() const {
    string command = "mplayer ";       //mpv si != ubuntu
    command = command + getDir() ;
    command = command + " &";
    system(command.c_str());
}

void Video::write(ostream &s)const{
  s<<"VIDEO\n";
  Multimedia::write(s);
  s<<getDuration()<<'\n';
}
void Video::read(istream &is){
  Multimedia::read(is);
  string temp;
  getline(is, temp);
  duration = atoi(temp.c_str());
}
