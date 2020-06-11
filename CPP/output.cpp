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

void formatoJson(map<int,int> &referencias){
    json stream;
// Iterate over the map using Iterator till end.
    map<int, int>::iterator it = referencias.begin();
    while (it != referencias.end())
    {
        int keyWord = it->first; // Accessing KEY from element pointed by it.
        int suscrip = it->second; // Accessing VALUE from element pointed by it.
        json j;
        j["id"] = keyWord;
        j["ref"] = suscrip;
        stream.push_back(j);

        cout << endl << stream.dump(3) << endl;

        it++; // Increment the Iterator to point to next entry
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

