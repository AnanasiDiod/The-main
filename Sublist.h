//
// Created by mi on 19.02.2020.
//

#ifndef PROJ2_SUBLIST_H
#define PROJ2_SUBLIST_H

class Element
{
public:
    int data;
    Element* next;
    Element* prev;
};

class Sublist
{
public:
    Sublist();
    ~Sublist();
    void push_back(int d);
    void push_forward(int d);
    int pop_back();
    int pop_forward();
    void push_where(int d, int where);
    void erise_where(int where);
    unsigned int size();
    void clear();
//    void init_from_file();
    Element* geth(){return head;}
    int getl(){return length;}
private:
    unsigned int length;
    Element* head;
};

#endif //PROJ2_SUBLIST_H
