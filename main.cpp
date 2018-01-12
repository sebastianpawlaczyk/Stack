#include <iostream>
#include "Stack.h"

int main() {

    Stack<int> stack;

    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(8);
    std::cout<<"Top: "<<stack.getTop()<<std::endl;
    stack.displayStack();

    Stack<int> stack1;
    stack1.push(8);
    stack1 = stack;
    stack1.displayStack();




    return 0;
}