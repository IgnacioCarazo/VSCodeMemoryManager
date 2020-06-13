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

int GarbageCollector::addPointer(struct Info &infoPtr){ //Ejecutado al construir
    infoPtr.ID = ++asignador;
    referencias.insert(pair<int,struct Info>(infoPtr.ID,infoPtr));
    updateJSON();
    return infoPtr.ID;
}

void GarbageCollector::changePointer(int newID){
    ++(referencias.at(newID)).ref;
    updateJSON();
}

int GarbageCollector::deletePointer(int oldID){
    int numVarPointing = (referencias.at(oldID)).ref;
    if(numVarPointing == 1){
        referencias.erase(oldID);
        updateJSON();
        return numVarPointing;
    }else{
        int num = (referencias.at(oldID)).ref--;
        updateJSON();
        return num;
    }


}

void GarbageCollector::updateJSON() {
    formatoJson(referencias);

}
