//
// Created by cubero2112 on 6/10/20.
//
#include <string>
#include <map>
#include "nlohmann/json.hpp"
#include <iostream>
#include "VSPtr.h"


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
}

extern "C" json salida(){
    VSPtr<int> ptr = VSPtr<int>::New();

    *ptr = 30;


    VSPtr<double> ptr2 = VSPtr<double >::New();


    *ptr2 = 67;

    VSPtr<double > ptr3 = VSPtr<double>::New();
    VSPtr<double > ptr4 = VSPtr<double>::New();

    ptr3 = ptr2;

    ptr4 = ptr3;

    VSPtr<double > ptr5 = VSPtr<double>::New();
    *ptr5 = 99;

    ptr3 = ptr5;

    return streamOutput;
}

