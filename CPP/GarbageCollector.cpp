//
// Created by cubero2112 on 6/9/20.
//

#include <map>
#include <iostream>
#include "GarbageCollector.h"
#include "output.cpp"

using namespace std;

int GarbageCollector::asignador{0};
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
    int idTemp = ++asignador;
    referencias.insert(pair<int,int>(idTemp,1));
    formatoJson(referencias);
    return idTemp;
}

void GarbageCollector::cambiarReferencia(int nuevoID){
    ++referencias.at(nuevoID);
    formatoJson(referencias);
}

int GarbageCollector::eliminarReferencia(int antiguoID){
    int numVarApuntando = referencias.at(antiguoID);
    if(numVarApuntando == 1){
        referencias.erase(antiguoID);
        formatoJson(referencias);
        return numVarApuntando;
    }else{
        int num = referencias.at(antiguoID)--;
        formatoJson(referencias);
        return num;
    }

}