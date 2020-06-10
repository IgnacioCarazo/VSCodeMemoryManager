//
// Created by cubero2112 on 6/9/20.
//

#include <map>
#include <iostream>
#include "GarbageCollector.h"

using namespace std;

int GarbageCollector::asisgnadorID{0};
GarbageCollector* GarbageCollector::garbageCollector{nullptr};

GarbageCollector::GarbageCollector(){
    cout << "Garbage Collector creado" << endl;
}

GarbageCollector* GarbageCollector::Instancia(){
    if(garbageCollector== nullptr){
        garbageCollector = new GarbageCollector;
    }
    return garbageCollector;
}

int GarbageCollector::addReferencia(){
    int idTemp = ++asisgnadorID;
    referencias.insert(pair<int,int>(idTemp,1));
    return idTemp;
}

void GarbageCollector::cambiarReferencia(int nuevoID){
    ++referencias.at(nuevoID);
}

int GarbageCollector::eliminarReferencia(int antiguoID){
    int numVarApuntando = referencias.at(antiguoID);
    if(numVarApuntando == 1){
        referencias.erase(antiguoID);
        return numVarApuntando;
    }else{
        return referencias.at(antiguoID)--;
    }
}