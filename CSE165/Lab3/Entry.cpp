#include <iostream>
#include "Entry.h"

Entry::Entry(){
    n = "";
    l = "";
    e = "";
}

void Entry::setName(std::string name){
    n = name;
}

void Entry::setLastName(std::string lastname){
    l = lastname;
}

void Entry::setEmail(std::string email){
    e = email;
}

void Entry::print(){
    std::cout << "First Name: " << n << std::endl << "Last Name: " << l << std::endl << "Email: " << e << std::endl;
}