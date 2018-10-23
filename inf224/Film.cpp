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
    s<<"Chapiters duration ";
    cout << "showFilm_ ";
    const int *pnt = getChapters();
    while (*pnt){
        s<<*pnt<<" ";
        pnt++;
    }
}


void Film::write(ostream &s)const{
  s<<"FILM\n";
  Video::write(s);
  s << getChaptersNum() << '\n';

 for(int i = 0; i < getChaptersNum(); i++)
   s << chapters[i] << '\n';
}
void Film::read(istream &is){
  Video::read(is);
  string temp;
  getline(is,temp);
  chaptersnumber_ = atoi(temp.c_str());
  chapters = new int[chaptersnumber_];
  for(int i=0;i<getChaptersNum();i++){
    getline(is,temp);
    chapters[i] = atoi(temp.c_str());
  }
}
