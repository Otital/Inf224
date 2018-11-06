#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <memory>
#include "Multimedia.h"

using MultimerdiaPtr = std::shared_ptr<Multimedia>;

class Group : public list<MultimerdiaPtr>{
private:
  string groupName = " "; //GroupName

public:

  Group(const string& name):groupName(name){}

  ~Group(){};

  void setName(const string& name) {
    groupName = name;
  }
  string getGroupName() const {return groupName;}
  void show(ostream &s);
};
#endif
