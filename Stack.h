//
// Created by mi on 19.02.2020.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H


class Stack
{
public:
    Stack(){};
    ~Stack(){};
    virtual void push_back(int d) = 0;
    virtual int pop_back() = 0;
};

#endif //STACK_STACK_H
