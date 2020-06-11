//
// Created by cubero2112 on 6/9/20.
//
#include <map>
#include <iostream>
using namespace std;

#ifndef CPP_GARBAGECOLLECTOR_H
#define CPP_GARBAGECOLLECTOR_H

class GarbageCollector {
private:
    static GarbageCollector* garbageCollector;

    GarbageCollector();

public:
    //Atributos
    map<int,struct Info> referencias;
    static int asignador;


    static GarbageCollector* Instancia();


    int addPointer(struct Info &infoPtr);

    void changePointer(int newID);

    int deletePointer(int oldID);


};
#endif //CPP_GARBAGECOLLECTOR_H
