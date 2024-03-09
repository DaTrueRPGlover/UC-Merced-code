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
}

Object::Object( Object& ){
    count++;
}

//Object& Object::operator=(const Object& other){
    // Performing deep copy
//    this->x = other.x;
    // Return reference to this object
//    return *this;
//}