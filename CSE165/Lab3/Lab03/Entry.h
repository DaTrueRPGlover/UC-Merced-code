#pragma once
#include <iostream>

class Entry{
    private:
        std::string n, l, e;
        
    public:

        // Default constructor
        Entry(){
            n = "";
            l = "";
            e = "";
        }
        
        // Funtions
        void setName(std::string name){
            n = name;
        }
        void setLastName(std::string lastname){
            l = lastname;
        }
        void setEmail(std::string email){
            e = email;
        }

        void print() const{
            std::cout << "First Name: " << n << std::endl << "Last Name: " << l << std::endl << "Email: " << e << std::endl;
        }
};