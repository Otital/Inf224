#ifndef RAW_M
#define RAW_M

#include <list>
#include <memory>

#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include "Container.h"

using namespace std;
using ContPtr = std::shared_ptr<Container>;
void test(){
//    Multimedia ** multi = new Multimedia * [4];
//    unsigned int count = 0;
//    multi[count++]= new Photo(10,10,"Photo1","/home/oscar/Pictures/uno.png");
//    multi[count++]= new Photo(20,20,"Photo2","/home/oscar/Pictures/dos.png");
//    multi[count++]= new Video(30,"Video1","/home/oscar/Videos/jelly.mp4");
//    multi[count++]= new Video(40,"Video2","/home/oscar/Videos/star.mp4");

//    for(unsigned int k = 0; k < count; ++k){
//        multi[k]->playMultimedia();
//    }

    // int duration[3]={0};
    // int *c = &duration[0];
    // duration[0] = 6;
    // duration[1] = 6;
    // duration[2] = 6;
    /*
    int *c = new int[11];
    c[0]=1;
    c[1]=2;
    c[2]=5;
    c[3]=5;
    c[4]=5;
    c[5]=5;
    c[6]=5;
    c[7]=5;
    c[8]=5;
    c[9]=4;
    c[10]=4;


    Film *a = new Film(20,"film","/dir/dir", c , 11);

    Film *b = new Film(20,"film","/dir/dir", c , 11);
    *b = *a;
    delete a;
    b->show(cout);*/
/*
    using MultimerdiaPtr = std::shared_ptr<Multimedia>;

    int *chap2 = new int[3]{1, 2, 3};
    int *chap = new int[12]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  //  Group *list = new Group("name");
    Group group("Group");

    MultimerdiaPtr p1(new Photo(10,10,"Photo1","/home/oscar/Pictures/uno.png"));
    MultimerdiaPtr p2(new Photo(10,10,"Photo2","/home/oscar/Pictures/uno.png"));
    MultimerdiaPtr p3(new Photo(10,10,"Photo3","/home/oscar/Pictures/uno.png"));
    MultimerdiaPtr v1(new Video(01,"video1", "video/test.png"));
    MultimerdiaPtr v2(new Video(02,"Video2", "video/test.png"));
    MultimerdiaPtr f(new Film( 20,"film", "path", chap, 12));
    MultimerdiaPtr f2(new Film( 20,"film2", "pa2th", chap2, 3));

    group.push_back(p1);
    group.push_back(p2);
    group.push_back(p3);
    group.push_back(v1);
    group.push_back(v2);
    group.push_back(f);
    group.push_back(f2);

    group.show(cout);
*/

    ContPtr container(new Container());

    MultimerdiaPtr p = container->makePhoto(20,10, "$$$", "___/____");

    container->play("$$$",cout);
}
#endif
