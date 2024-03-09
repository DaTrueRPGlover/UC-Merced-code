#pragma once
#include <iostream>
#include "Entry.h"
#include <vector>

class AddressBook{
    private:
        std::vector<Entry*> members;

    public:
        AddressBook(){
            members = {};
        }
        
        ~AddressBook(){
            for (Entry* Entry : members){
                delete Entry;
            }
        }

        void add(Entry* Entry){
            members.push_back(Entry);
        }

        void print() const{
            for (const Entry* Entry: members){
                Entry->print();
            }
        }

};