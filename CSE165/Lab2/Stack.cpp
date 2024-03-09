#include <iostream>
#include "Stack.h"

using namespace std;

void Stack::Link::initialize(void* dat, Link* nxt){
    data = dat;
    next = nxt;
}

void Stack::initialize(){
    head = 0;
}

void Stack::push(void* dat){
    Link* newLink = new Link;
    newLink->initialize(dat, head);
    head = newLink;
}

void* Stack::peek(){
    if (head == 0){
        cout << "Stack is empty";
    }
    return head->data;
}

void* Stack::pop(){
    if (head == nullptr){
        return nullptr;
    }
    void* result = head->data;
    Stack::Link* prevHead = head;
    deletecb(head->data);
    head = head->next;
    delete prevHead;
    return result;
}

void Stack::cleanup(){

    while (head != nullptr)
    {
       pop();
       //head = head->next;
    }
}

Stack::Stack() {
    initialize();
}

Stack::Stack(int N) {
    initialize();
    double value = 1.0;
    for (int i = 0; i < N; ++i) {
        push(new double(value));
        value += 0.1;
    }
}

Stack::~Stack() {
    cleanup();
}