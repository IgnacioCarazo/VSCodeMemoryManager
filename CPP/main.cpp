//
// Created by cubero2112 on 6/9/20.
//

#include "VSPtr.h"
#include <fstream>
#include "nlohmann/json.hpp"
#include "output.cpp"

using namespace std;



int main() {
    string s;


    VSPtr<int> ptr1 = VSPtr<int>::New(); //ID: 1

    *ptr1 = 30;


    VSPtr<double> ptr2 = VSPtr<double >::New(); //ID: 2


    *ptr2 = 67;

    ofstream FOUT0("JACKSON0.json");
    formatoJson(GarbageCollector::Instancia()->referencias);
    s = streamOutput.dump();
    FOUT0 << s << endl;


    VSPtr<double > ptr3 = VSPtr<double>::New(); //ID: 3
    VSPtr<double > ptr4 = VSPtr<double>::New(); //ID: 4

    ptr3 = ptr2; //ID: 3 y //ID2 Sobrecarga de '='

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
