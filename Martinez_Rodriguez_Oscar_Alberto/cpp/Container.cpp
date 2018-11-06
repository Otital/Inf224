#include "Container.h"
#include "ExceptionDef.h"

MultimerdiaPtr Container::makePhoto(double latitud, double longitud, const
  string &name, const string &dir){
    MediaCont[name] = MultimerdiaPtr(new Photo(latitud, longitud, name, dir ));
    return MediaCont[name];
}

MultimerdiaPtr Container::makeVideo(double duration, const string &name,
  const string &dir ){
    MediaCont[name] = MultimerdiaPtr(new Video(duration, name, dir ));
    return MediaCont[name];
}

MultimerdiaPtr Container::makeFilm(int duration, const string &name,
  const string &dir, int * chapters_ , int chaptersnumber){
    MediaCont[name] = MultimerdiaPtr(new Film(duration, name, dir, chapters_, chaptersnumber ));
    return MediaCont[name];
}

GroupPtr Container::makeGroup(const string &name){
    GroupsCont[name] = GroupPtr(new Group(name));
    return GroupsCont[name];
}

void Container::search_Show(const string &name, ostream &s)const{
  auto element = MediaCont.find(name);
   if (element != MediaCont.end()){
     s<<"A multimedia element "<<name<< " has been found: ";
     element->second->show(s);
   }else
      s << "No multimedia found ";
  auto group = GroupsCont.find(name);
     if (group != GroupsCont.end()){
       s<<"A group "<< name<< " has been found: ";
       group->second->show(s);
     }
     else
      s << ";No group found ";
}

void Container::play(const string &name, ostream &s) const{
  auto element = MediaCont.find(name);
   if (element != MediaCont.end()){
      s << "Playing;";
      element->second->playMultimedia();
   }else
      s << "No multimedia to play";
}

bool Container::processRequest(TCPConnection& cnx, const string& request, string& response){
  cerr << "\nRequest: '" << request << "'" << endl;
  istringstream req(request);
  ostringstream answer;
  response = "";
  string method, element = " ";
/*
    INSTRUCTION>element
*/
  getline(req, method, '>');
  getline(req, element, '>');

  TCPLock lock(cnx);

  if (method == "SEARCH") {
      search_Show(element, answer);
  }else if (method == "PLAY"){
      play(element, answer);
  }else if(method == "QUIT"){
      response = "Bye";
      return false;
  }else{
    response = "Sorry command/file not defined";
    return true;
  }
  response = answer.str();
  cerr<<"OK: "<<response<<'\n';
  return true;
}

MultimerdiaPtr Container::make(ifstream &is, string &theClass){
  string name;
  if(theClass.compare("PHOTO")==0){
    getline(is,name);
    return makePhoto(0,0,name,"");
  }if(theClass.compare("VIDEO")==0){
    getline(is,name);
    return makeVideo(0,name,"");
  }if(theClass.compare("FILM")==0){
    getline(is,name);
    return makeFilm(0,name,"",NULL,0);
  }else return NULL;
}


bool Container::readFile(const string &inFile){
  ifstream in(inFile);
    if (!in){
     cerr <<"The file"<< inFile<<"Can't be found;";
     return false;
    }else{
       while(in){
         string theClass;
         getline(in,theClass);
         MultimerdiaPtr multimedia = make(in,theClass);
         if(multimedia){
           multimedia->read(in);
         }
       }
       in.close();
       return true;
    }
}
bool Container::writeFile(const string &outFile){
  ofstream out(outFile);
  if(out){
    for(auto it = MediaCont.begin(); it!= MediaCont.end();it++){
      it->second->write(out);
    }
    out.close();
    return true;
  }else{
    cerr<<"File"<< outFile<<"can't be open;";
    return false;
  }
}
