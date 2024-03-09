#include <iostream>
#include <vector>
#include "Rect.h"
#include "Vec.h"

int main() {
    std::vector<Rect> rectangles;
    
    while (true) {
        std::cout << "Type 4 floats to define a rectangle: ";
        float a, b, c, d;
        std::cin >> a >> b >> c >> d;
        
        if (a < 0 && b < 0 && c < 0 && d < 0)
            break;

        rectangles.push_back(Rect (a, b, c, d));
    }

    while (true) {
        std::cout << "Type 2 floats to define a point: ";
        float x, y;
        std::cin >> x >> y;
        
        if (x == -99.0f && y == -99.0f)
            break;
        
        Vec point(x, y);
        
        for (int i = 0; i < rectangles.size(); ++i) {
            if (rectangles[i].contains(point)) {
                std::cout << "The point is INSIDE of rectangle " << i << std::endl;
            } else {
                std::cout << "The point is OUTSIDE of rectangle " << i << std::endl;
            }
        }
    }
    
    std::cout << "Finished!" << std::endl;
    
    return 0;
}
