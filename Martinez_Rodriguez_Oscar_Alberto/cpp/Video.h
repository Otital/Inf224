#ifndef VIDEO_H
#define VIDEO_H

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

#include "Multimedia.h"
using namespace std;

class Video : public Multimedia {
private:
    int duration = 0;

public:
    Video(int duration, const string& name, const string& dir):
      Multimedia(name, dir) , duration(duration){}
    virtual ~Video(){}

    void setDuration(int duration){duration = duration ; }
    int getDuration() const {return duration ; }
    virtual void show(ostream & s);
    void playMultimedia() const;
    void write(ostream &s)const;
    void read(istream &is);

};
#endif // VIDEO_H
