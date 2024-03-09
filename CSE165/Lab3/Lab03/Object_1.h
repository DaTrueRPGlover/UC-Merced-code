#pragma once

class Object{
    private:


    public:
        int x;
        // Constructors
        Object(); // Default
        Object(int value); // Parameterized constructor

        // Destructor
        ~Object();

        // Public member functions
        void setX(int value);
        int getX() const;

        static int count;
};