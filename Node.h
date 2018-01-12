#ifndef STACK_NODE_H
#define STACK_NODE_H

#include <iostream>

template<typename T>
class Node {

public:

    T data; // value of element
    Node *prev; // previous element in stack

    Node(T v, Node *p):data(v),prev(p){}
    ~Node(){
        std::cout<<"Node destructor of value "<<data<<std::endl;
    }
};


#endif //STACK_NODE_H
