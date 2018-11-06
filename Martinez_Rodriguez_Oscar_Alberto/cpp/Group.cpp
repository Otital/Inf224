#include "Group.h"

void Group::show(ostream &s){
  s << "Groupe Name:";
  s << getGroupName() << " ";
  for (iterator it = begin(); it != end(); ++it){
      (*it)->show(s);
    }
  s << endl;
}
