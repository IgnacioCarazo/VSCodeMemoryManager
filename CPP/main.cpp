//
// Created by cubero2112 on 6/9/20.
//

#include "VSPtr.h"
#include "nlohmann/json.hpp"
using namespace std;



int main() {

    VSPtr<int> ptr1 = VSPtr<int>::New(); //ID: 1

    *ptr1 = 30;


    VSPtr<double> ptr2 = VSPtr<double >::New(); //ID: 2


    *ptr2 = 67;


    VSPtr<double > ptr3 = VSPtr<double>::New(); //ID: 3
    VSPtr<double > ptr4 = VSPtr<double>::New(); //ID: 4

    ptr3 = ptr2; //ID: 3 y //ID2 Sobrecarga de '='

    ptr4 = ptr3;

    VSPtr<double > ptr5 = VSPtr<double>::New();
    *ptr5 = 99;

    ptr3 = ptr5;

    return 0;
}
