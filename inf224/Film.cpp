#include "Film.h"

Film::Film(const Film& from) : Video(from){
  if(from.chapters) {
    chapters = new int[from.chaptersnumber_];
    for(int k=0 ; k < from.chaptersnumber_ ; k++){
        chapters[k] = from.chapters[k];
    }
  } else chapters = nullptr;
}
Film& Film::operator= (const Film& from){
  Video::operator=(from);
  if(chapters && from.chapters){
    for(int k = 0 ; k < from.chaptersnumber_ ; k++){
        chapters[k] = from.chapters[k];
    }
  }else{
    delete chapters;
    if(from.chapters) {
      chapters = new int[from.chaptersnumber_];
      for(int k = 0 ; k < from.chaptersnumber_ ; k++){
          chapters[k] = from.chapters[k];
      }
    }else chapters = nullptr;
  }
  return *this;
}

void Film::show(ostream & s){
    Video::show(s);
    s<<"Chapiters duration\n";
    int i = chaptersnumber_ ;
    cout << "showFilm_\n";
    const int *pnt = getFilm();
    while (*pnt){
        s<<chaptersnumber_-i<<" "<<*pnt<<"\n";
        i--;
        pnt++;
    }
}
