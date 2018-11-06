
// #define RAW_VERSION
#define SERVER_VERSION

#include "Raw.h"
#include "ServerMain.h"


#ifdef RAW_VERSION
int main(){
  test();
  return 0;
}
#endif //TEST_VERSION

#ifdef SERVER_VERSION
int main(){
  server();
  return 0 ;
}
#endif
