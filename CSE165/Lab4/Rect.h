#pragma once
#include "Vec.h"
#include <iostream>

class Rect{

    public:
        float x, y, width, height;

        Rect(){
            x = y = width = height = 0;
        }

        Rect(float a, float b, float c, float d){
            x = a;
            y = b;
            width = c;
            height = d;
        }

        bool contains(Vec a){
            if(a.x >= x && a.x <= x + width && a.y >= y - height && a.y <= y){
                return true;
            }
            return false;
        }


};