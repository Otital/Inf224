#ifndef FILM_H
#define FILM_H

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

#include "Video.h"

using namespace std;

class Film : public Video{
private:
    int * chapters = NULL;
    int chaptersnumber_;

public:
    Film(int duration, const string& name, const string& dir, int * chapters_ , int chaptersnumber):
        Video::Video(duration , name , dir) , chapters(new int[chaptersnumber]){
          for(int k=0 ; k < chaptersnumber; k++){
              chapters[k] = chapters_[k];
          }
    }
    Film(const Film&);
    Film& operator= (const Film&);
    ~Film(){
      delete [] chapters;
    }
    void setFilm(int *chapters_, int chaptersnumber_ ){
      for(int k=0 ; k < chaptersnumber_ ; k++){
          chapters[k] = chapters_[k];
        }
      }
    const int * getFilm() const {return chapters ; }
    void show(ostream & s);
};

#endif // FILM_H
