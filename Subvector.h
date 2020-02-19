//
// Created by mi on 19.02.2020.
//

#ifndef STACK_SUBVECTOR_H
#define STACK_SUBVECTOR_H
#include "Stack.h"
#include <iostream>
using namespace std;


class Subvector: public Stack
{
public:
    Subvector();
    ~Subvector();
    void push_back(int a);
    int pop_back();
    void resize(unsigned int a);
    void shrink_to_fit();
    void clear();
    void init_from_file(char* filename, Subvector* p);
    int get_top();
    int get_capacity();
private:
    int* mass;
    unsigned int top;
    unsigned int capacity;
};


#endif //STACK_SUBVECTOR_H
