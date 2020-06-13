//
// Created by parallels on 6/12/20.
//
#include <iostream>
#include "md5.h"
#include "md5.cpp"



const char* encriptarMD5(const char* password){
    std::string passwordString = password;

    return md5(passwordString).c_str();
}


