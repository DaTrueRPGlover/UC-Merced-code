#include "Object.h"

int Object::count = 0;

Object::Object(){
    count++;
    x = 0;
}

Object::Object(int value){
    count++;
    x = value;
}

Object::~Object(){
    count--;
}