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
    map<int,int> referencias;
    static int asignador;


    static GarbageCollector* Instancia();


    int addReferencia();

    void cambiarReferencia(int nuevoID);

    int eliminarReferencia(int antiguoID);


};
#endif //CPP_GARBAGECOLLECTOR_H
