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
    MultimerdiaPtr p = container->makePhoto(20,10, "Hello", "./Media/hello.jpg");
    MultimerdiaPtr p2 = container->makePhoto(30,10, "Hello2", "./Media/helloworld.jpeg");
    MultimerdiaPtr  v = container->makeVideo(30, "Jelly", "./Media/jelly.mp4");

    int *c = new int[5];
    c[0]=1;
    c[1]=2;
    c[2]=3;
    c[3]=4;
    c[4]=5;
    MultimerdiaPtr  f = container->makeFilm(22,"Star", "./Media/star.mp4", c, 5);

    container->writeFile("dataBase.txt");

    container->readFile("dataBase.txt");

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
