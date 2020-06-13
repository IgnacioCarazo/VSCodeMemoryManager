//
// Created by parallels on 6/12/20.
//
#include <iostream>
#include "md5.h"
#include "md5.cpp"


const char* encriptarMD5(std::string string){
    const char* s = string.c_str();
    return s;
}

std::string encriptar(const char* password){
    std::string s = md5(password);
    return s;
}

