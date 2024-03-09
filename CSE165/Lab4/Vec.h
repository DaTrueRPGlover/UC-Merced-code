#pragma once
#include <iostream>

class Vec{

    public:

        float x, y;
        Vec(){
            x = 0;
            y = 0;
        }

        Vec(float a, float b){
            x = a;
            y = b;
        }

        void set(float a, float b){
            x = a;
            y = b;
        }

        void add(Vec a){
            x = x + a.x;
            y = y + a.y;
        }

        void print(){
            std::cout << '(' << x << ", " << y << ')' << std::endl; 
        }
};