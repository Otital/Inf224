#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Multimedia
{
private:
    string name = " " ; //Name
    string dir = " " ;   //Path
public:
    //
    Multimedia():name("") , dir(""){}
    Multimedia(const string& name , const string& dir):name(name), dir(dir){}

    virtual ~Multimedia(){};

    void setName(const string &name_){ name = name_ ; }
    void setDir(const string &dir_) {dir = dir_ ; }

    string getName() const {return name ; }
    string getDir() const {return dir ; }

    virtual void show(ostream & s);

    virtual void playMultimedia()const;

    virtual void write(ostream &s)const;
    virtual void read(istream &is);
    };



#endif // MULTIMEDIA_H
