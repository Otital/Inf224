#include "Video.h"

void Video::show(ostream & s){
  Multimedia::show(s);
  s<<"Video duration: "<< getDuration() <<"\n" ;
}

void Video::playMultimedia() const {
    string command = "mplayer ";       //mpv si != ubuntu
    command = command + getDir() ;
    command = command + " &";
    system(command.c_str());
}
