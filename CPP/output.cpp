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

json static outputStream;


void jsonFile(){
    int static count{0};
    string s;
    s = outputStream.dump();
    string cadena = "JACKSON" + to_string(count++) + ".json";
    ofstream FOUT0(cadena);
    FOUT0 << s << endl;
}


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
    outputStream = stream;
    jsonFile();


}

extern "C" int salida(){
    string s;

    VSPtr<int> ptr = VSPtr<int>::New();


    *ptr = 30;

    VSPtr<double> ptr2 = VSPtr<double >::New();
    VSPtr<string> ptr60 = VSPtr<string>::New(); //ID: 3

    *ptr2 = 67.5;

    VSPtr<double > ptr3 = VSPtr<double>::New();
    VSPtr<double > ptr4 = VSPtr<double>::New();

    ptr3 = ptr2;

    ptr4 = ptr3;

    VSPtr<double > ptr5 = VSPtr<double>::New();
    *ptr5 = 99.7;

    ptr3 = ptr5;

    return 0;
}
/*


int main() {
    string s;

    VSPtr<int> ptr1 = VSPtr<int>::New(); //ID: 1
    *ptr1 = 30;

*/
/*
    VSPtr<int> ptr56 = VSPtr<int>::New();
    VSPtr<int> ptr54 = VSPtr<int>::New();
    VSPtr<int> ptr43 = VSPtr<int>::New();
*//*





    VSPtr<double> ptr2 = VSPtr<double >::New(); //ID: 2


    *ptr2 = 67.5;

*/
/*    ofstream FOUT0("JACKSON0.json");
    formatoJson(GarbageCollector::Instancia()->referencias);
    s = outputStream.dump();
    FOUT0 << s << endl;
    FOUT0.clear();*//*


    VSPtr<string> ptr60 = VSPtr<string>::New(); //ID: 3


    VSPtr<double > ptr3 = VSPtr<double>::New(); //ID: 3
    VSPtr<double > ptr4 = VSPtr<double>::New(); //ID: 4

    ptr3 = ptr2; //ID: 3 y //ID2 Sobrecarga de '='

    ptr4 = ptr3;


*/
/*    ofstream FOUT1("JACKSON1.json");
    formatoJson(GarbageCollector::Instancia()->referencias);
    s = outputStream.dump();
    FOUT1 << s << endl;*//*



    VSPtr<double > ptr5 = VSPtr<double>::New();
    *ptr5 = 99.6;

    ptr3 = ptr5;

*/
/*    ofstream FOUT2("JACKSON2.json");
    formatoJson(GarbageCollector::Instancia()->referencias);
    s = outputStream.dump();
    FOUT2 << s << endl;*//*


    return 0;
}
*/

