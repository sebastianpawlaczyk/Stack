#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>
#include "Node.h"

template<typename T>
class Stack {

private:
    Node<T> *top; // first element of the stack

public:

    Stack(){
        top = nullptr;
    }
    ~Stack(){

        auto pom = top;

        while(top != nullptr){

            pom = top;
            top = top->prev;
            delete pom;
        }

    }

    Stack(const Stack &temp){

        Node<T> *pom = temp.top;
        top = nullptr;

        while(pom != nullptr){

            reversePush(pom->data);
            pom = pom->prev;
        }
    }

    bool reversePush(T element){

        Node<T> *node = new Node<T>(element, nullptr);

        if(top == nullptr){
            top = node;
        }

        else{
            auto pom = top;

            while(pom->prev != nullptr){ pom = pom->prev;}

            pom->prev = node;
        }

    }

    bool push(T element){

        Node<T> *node = new Node<T>(element, nullptr); // create new element on the stack

        if(top == nullptr){
            top = node;
        }
        else{
            node->prev = top;
            top = node;
        }

        return true;
    }

    bool pop(){

        if(top == nullptr) return false;
        else{

            Node<T> *pom = top;
            top = top->prev;
            delete pom;

            return true;
        }
    }

    int size() const{

        Node<T> *pom = top;
        int sum = 0;

        while(pom != nullptr){
            pom = pom->prev;
            sum++;
        }
        return sum;
    }

    T getTop(){

        return top->data;
    }

    void displayStack(){

        auto pom = top;

        std::cout<<"STACK:"<<std::endl;

        while(pom != nullptr){

            std::cout<<pom->data<<std::endl;
            pom = pom->prev;
        }
    }

    Stack & operator=(const Stack &temp){  // without this operator overload we have bad assign

        if(this == &temp){
            return *this;
        }
        else{

            auto pom = top;

            while(top != nullptr){

                pom = top;
                top = top->prev;
                delete pom;
            }

            pom = temp.top;
            while(pom != nullptr){

                reversePush(pom->data);
                pom = pom->prev;
            }

        }
    }
};


#endif //STACK_STACK_H
