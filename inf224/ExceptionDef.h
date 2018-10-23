#ifndef EXCEPTIONDEF_H
#define EXCEPTIONDEF_H

#include <regex>

struct ExistenceException : public exception{
  string exc;
  ExistenceException(string e) : exc(e) {};
};

bool multExistance(Multimedias multi , const string &name){
  if (multi.find(name) != multi.end())
    throw ExistenceException(name);
  else
    return false;
}

bool groupExistance(Groups group , const string &name){

  if (group.find(name) != group.end())
    throw ExistenceException(name);
  else
    return false;
}

struct FormatException : public exception{
  string exc;
  FormatException(string e) : exc(e){};
};

bool StringFormat(const string& str){
  regex rgx("[[:alnum:]]+");
  if (!regex_match(str,rgx))
    throw FormatException(str);
  else
    return true;
}

#endif
