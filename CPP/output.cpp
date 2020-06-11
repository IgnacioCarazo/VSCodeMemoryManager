//
// Created by cubero2112 on 6/10/20.
//
#include <string>
#include <map>
#include "nlohmann/json.hpp"
#include <iostream>
#include "VSPtr.h"
#include <fstream>


using nlohmann::json;
using namespace  std;
// Create a map iterator and point to beginning of map
json static streamOutput;

void formatoJson(map<int,struct Info> &referencias){
    json stream;
// Iterate over the map using Iterator till end.
    map<int,struct Info>::iterator it = referencias.begin();
    while (it != referencias.end())
    {
        int keyWord = it->first; // Accessing KEY from element pointed by it.
        json j;

        j["id"] = keyWord;
        j["size"] = (it->second).size;
        j["address"] = (it->second).address;
        j["type"] = (it->second).type;
        j["ref"] = (it->second).ref;

        stream.push_back(j);


        it++; // Increment the Iterator to point to next entry

        cout << endl << stream.dump(3) << endl;

    }
    streamOutput = stream;
    //ofstream FOUT("JACKSONN.json");
    //string s = streamOutput.dump();
    //FOUT << s << endl;
}

extern "C" int salida(){
    string s;

    VSPtr<int> ptr = VSPtr<int>::New();


    *ptr = 30;


    VSPtr<double> ptr2 = VSPtr<double >::New();


    *ptr2 = 67;

    ofstream FOUT0("JACKSON0.json");
    formatoJson(GarbageCollector::Instancia()->referencias);
    s = streamOutput.dump();
    FOUT0 << s << endl;


    VSPtr<double > ptr3 = VSPtr<double>::New();
    VSPtr<double > ptr4 = VSPtr<double>::New();

    ptr3 = ptr2;


    ptr4 = ptr3;

    ofstream FOUT1("JACKSON1.json");
    formatoJson(GarbageCollector::Instancia()->referencias);
    s = streamOutput.dump();
    FOUT1 << s << endl;

    VSPtr<double > ptr5 = VSPtr<double>::New();
    *ptr5 = 99;

    ptr3 = ptr5;

    ofstream FOUT2("JACKSON2.json");
    formatoJson(GarbageCollector::Instancia()->referencias);
    s = streamOutput.dump();
    FOUT2 << s << endl;


    return 0;
}

