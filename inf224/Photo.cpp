#include "Photo.h"
#include "Multimedia.h"

void Photo::show(ostream & s){
  Multimedia::show(s);
  s<<"Photo latitud: "<< getLatitud() <<" " ;
  s<<"Photo longitud: "<< getLongitud() <<" " ;
}

void Photo::playMultimedia() const{
    string command = "eog ";    //Image viewer (imagej si != ubuntu)
    command = command + getDir() ;
    command = command + " &";
    system(command.c_str());
}

void Photo::write(ostream &s)const{
  s<<"PHOTO\n";
  Multimedia::write(s);
  s<<getLatitud()<<'\n'<<getLongitud()<<'\n';
}

void Photo::read(istream &is){
  cout<<getName()<<"\n";
  Multimedia::read(is);
  string temp;
  getline(is, temp);
  latitud = atof(temp.c_str());
  getline(is, temp);
  longitud = atof(temp.c_str());
  cout<<getName()<<"\n";
}
