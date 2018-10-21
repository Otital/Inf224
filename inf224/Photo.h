#ifndef PHOTO_H
#define PHOTO_H

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

#include "Multimedia.h"
using namespace std;

class Photo : public Multimedia {
private:
    double latitud = 0;
    double longitud = 0;

public:
    Photo(double latitud, double longitud, const string& name, const string& dir):
     Multimedia(name , dir), latitud(latitud) ,  longitud (longitud) {}
    ~Photo(){}
    void setLatitud(double latitud){latitud = latitud; }
    void setLongitud(double longitud){longitud = longitud; }
    double getLatitud() const {return latitud ; }
    double getLongitud() const {return longitud ; }
    void show(ostream & s);
    void playMultimedia() const;
};

#endif // PHOTO_H
