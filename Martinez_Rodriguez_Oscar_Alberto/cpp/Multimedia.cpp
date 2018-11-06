#include "Multimedia.h"

void Multimedia::show(ostream & s){
    s<<"Name: "<< getName() << " ;Path:"<<getDir()<<";" ;
}

void Multimedia::playMultimedia() const{
}

void Multimedia::write(ostream &s)const{
  s<<getName()<<'\n'<<getDir()<<'\n';
}

void Multimedia::read(istream &is){
  getline(is, dir);
}
