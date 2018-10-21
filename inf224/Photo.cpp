#include "Photo.h"
#include "Multimedia.h"

void Photo::show(ostream & s){
  Multimedia::show(s);
  s<<"Photo latitud: "<< getLatitud() <<"\n" ;
  s<<"Photo longitud: "<< getLongitud() <<"\n" ;
}

void Photo::playMultimedia() const{
    string command = "eog ";    //Image viewer (imagej si != ubuntu)
    command = command + getDir() ;
    command = command + " &";
    system(command.c_str());
}
