//
// Created by cubero2112 on 6/9/20.
//

#include <iostream>
#include <sstream>
#include "GarbageCollector.h"
using namespace std;

#ifndef CPP_VSPTR_H
#define CPP_VSPTR_H

struct Info{

    int ID;
    string type;
    string address;
    int size;
    int ref;

};

template <class T>
class VSPtr{
    T *ptr;
    int ID;

public:


    VSPtr()
    :ID{0}, ptr{new T}
    {
        struct Info ptrData;
        ptrData.size = sizeof(T);

        std::ostringstream address;
        address << (void const *)ptr;
        ptrData.address = address.str();; //Use a ptr y fallo
        ptrData.ref = 1;

        if(sizeof(T)==1){
            ptrData.type = "char";
        }else if(sizeof(T)==4){
            ptrData.type = "int";
        }else if(sizeof(T)==8){
            ptrData.type = "double";
        }else{
            ptrData.type = "N.D";
        }

        ID = GarbageCollector::Instancia()->addPointer(ptrData);
        cout << "---------------------¡'------------------------------" << endl;
        cout << "------Ejecucion del constructor---------" << endl;
        cout << "ID del objeto: " << ID << endl;
        cout << "Espacio de la memoria reservado: " << ptr <<  endl;
        cout << "---------------------------------------------------" << endl;
    }


    static VSPtr New(){
        return VSPtr();
    }

    T& operator*(){
        cout << "---------------------------------------------------" << endl;
        cout << "----------------Sobrecarga de '*'---------------" << endl;
        cout << "Operador de des-referencia ejecutado" << endl;
        cout << "---------------------------------------------------" << endl;

        return *ptr;
    }

/*
    void operator=(T val) {
        cout << "---------------------------------------------------" << endl;
        cout << "----------------Sobrecarga de '='---------------" << endl;
        cout << "Operador de asignacion(numerica) ejecutado" << endl;
        cout << "---------------------------------------------------" << endl;
        *ptr = val;
    }*/


    VSPtr& operator=(const VSPtr& objectToCopy){
        cout << "---------------------------------------------------" << endl;
        cout << "----------------Sobrecarga de '='---------------" << endl;
        int actualID {this->ID};
        int numVariablesApuntando
        {GarbageCollector::Instancia()->deletePointer(actualID)};
        cout << "Operador de asignacion(de un objeto) ejecutada" << endl;
        if(numVariablesApuntando == 1){
            cout << "Liberando espacio en la direccion de memoria: " << this->ptr << endl;
            delete this->ptr;
        }
        GarbageCollector::Instancia()->changePointer(objectToCopy.ID);
        this->ptr = objectToCopy.ptr;
        this->ID = objectToCopy.ID;
        cout << "Asignando la nueva direccion de memoria: " << this->ptr << endl;
        cout << "---------------------------------------------------" << endl;



    }

    T& operator&(){
        cout << "---------------------------------------------------" << endl;
        cout << "----------------Sobrecarga de '&'---------------" << endl;
        cout << "Operador amspersan ejecutado" << endl;
        cout << "---------------------------------------------------" << endl;
        return *ptr;
    }


    virtual ~VSPtr() {
        int numVarApuntando{GarbageCollector::Instancia()->deletePointer(ID)};
        if(numVarApuntando==1){
            cout << "---------------------------------------------------" << endl;

            cout << "-----Ejecucion del Destructor-----" << endl;
            cout << "Liberando espacio...." << endl;
            cout << "Direccion de memoria---> " << ptr << endl;
            cout << "ID-----> " << ID << endl;
            cout << "---------------------------------------------------" << endl;
            delete ptr;
        }
    }

};


#endif //CPP_VSPTR_H
