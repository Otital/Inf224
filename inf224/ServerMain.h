#ifndef SERVER_M
#define SERVER_M

#include <iostream>
#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include "Container.h"

using namespace std;
const int PORT = 3331;
using ContPtr = std::shared_ptr<Container>;

int server(){

    ContPtr container(new Container());
/*    MultimerdiaPtr p = container->makePhoto(20,10, "Hello", "/home/oscar/Pictures/hello.jpg");
    MultimerdiaPtr p2 = container->makePhoto(30,10, "1", "/home/oscar/Pictures/1.jpeg");
    MultimerdiaPtr  p3 = container->makePhoto(40,10, "2", "/home/oscar/Pictures/2.jpeg");
    MultimerdiaPtr  p4 = container->makePhoto(50,10, "3", "/home/oscar/Pictures/3.jpeg");
    MultimerdiaPtr  p6 = container->makePhoto(70,10, "4", "/home/oscar/Pictures/4.jpeg");
*/
  container->readFile("dataBase.txt");

  container->search_Show("Hello",cout);
  container->search_Show("4",cout);

  container->writeFile("dataBase2.txt");

    // create a TCP server
  shared_ptr<TCPServer> server(new TCPServer());
  server->setCallback(*container, &Container::processRequest);
  cout << "Starting Server on port " << PORT << endl;
  //possible server error:
   int status = server->run(PORT);
   if (status < 0) { cerr << "Could not start Server on port " << PORT << endl; return 1;}
   return 0;
}
#endif
