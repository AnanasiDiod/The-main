//
// Created by mi on 19.02.2020.
//

#include "Subvector.h"
#include <iostream>
#include <fstream>

Subvector::Subvector()
{
    mass = nullptr;
    top = 0;
    capacity = 0;
}
Subvector::~Subvector()
{
    delete[] mass;
    top = 0;
    capacity = 0;
    mass = nullptr;
}
void Subvector::push_back(int a)
{
    top++;
    if(capacity < top) capacity = top;
    int* mymass = new int[capacity];

    for(int i = 0; i < top - 1; i++)
        mymass[i] = mass[i];
    mymass[top - 1] = a;

    delete[] mass;
    mass = mymass;
}
int Subvector::pop_back()
{
//    if (top == 0) {cout << "Sigmentation" << endl; return 0;}
    int a;
    int* mymass = new int[capacity];

    for(int i = 0; i < top - 1; i++)
        mymass[i] = mass[i];
    a = mass[top - 1];

    delete[] mass;
    mass = mymass;
    top--;
    return a;
}
void Subvector::resize(unsigned int a)
{
    int edge = min(a, top);
    int* mymass = new int[a];
    for(int i = 0; i < edge; i++)
        mymass[i] = mass[i];
    delete[] mass;
    mass = mymass;
    capacity = a;
    top = edge;
}
void Subvector::shrink_to_fit()
{
    int* mymass = new int[top];
    for(int i = 0; i < top; i++)
        mymass[i] = mass[i];
    capacity = top;
    delete[] mass;
    mass = mymass;
}
void Subvector::clear()
{
    top = 0;
}
void Subvector::init_from_file(char* filename, Subvector* p)
{
    ifstream file(filename);
    if(!file){}
//        cout << "There are no file\n" << endl;

    int d = 0;
    file >> d;

    while(!(file.eof()))
    {
        p->push_back(d);
        file >> d;
    }
    p->push_back(d);
}
int Subvector::get_capacity()
{
    return capacity;
}
int Subvector::get_top()
{
    return top;
}