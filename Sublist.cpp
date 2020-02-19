//
// Created by mi on 19.02.2020.
//

#include "Sublist.h"
using namespace std;

Sublist::Sublist() {
    length = 0;
    head = nullptr;
}
Sublist::~Sublist() {
    Element* the_next = head;
    Element* previous = the_next;
    while(the_next != nullptr)
    {
        the_next = the_next->next;
        delete (previous);
        previous = the_next;
    }
    head = nullptr;
}
void Sublist::push_back(int d) {
    length++;
    Element* new_element = new Element;
    Element* s = head;
    new_element->next = nullptr;
    new_element->data = d;
    new_element->prev = nullptr;
    if(head != nullptr) {
        while (s->next != nullptr){
            s = s->next;
        }
        s->next = new_element;
        new_element->prev = s;
    }
    else {
        new_element->prev = nullptr;
        head = new_element;
    }
}
void Sublist::push_forward(int d) {
    length++;
    Element* new_element = new Element;
    new_element->next = head;
    new_element->data = d;
    new_element->prev = nullptr;
    head->prev = new_element;
    head = new_element;
}
int Sublist::pop_back() {
    length--;
    int d;
    Element *the_next = head;
    Element *previous = nullptr;
    while (the_next->next != nullptr){
        previous = the_next;
        the_next = the_next->next;
    }
    d = the_next->data;
    if (previous == nullptr) head = nullptr;
    else previous->next = nullptr;
    delete the_next;
    return d;
}
int Sublist::pop_forward() {
    length--;
    if(head->next != nullptr) {
        Element *new_element = head->next;
        Element *HEAD = head;
        int d = HEAD->data;
        new_element->prev = nullptr;
        head = new_element;
        delete HEAD;
        return d;
    }
    else{
        int d = head->data;
        delete head;
        head = nullptr;
        return d;
    }
}
void Sublist::push_where(int d, int where) {
    length++;
    Element* new_element = new Element;
    Element* t = head;
    Element* p = nullptr;
    new_element->next = nullptr;
    new_element->data = d;
    new_element->prev = nullptr;
    for(int i = 0; i < where - 1; i++)
        t = t->next;
    p = t->prev;
    p->next = new_element;
    t->prev = new_element;
    new_element->next = t;
    new_element->prev = p;
}
void Sublist::erise_where(int where) {
    length--;
    Element* t = head;
    Element* p = nullptr;
    Element* n = nullptr;
    for(int i = 0; i < where - 1; i++)
        t = t->next;
    p = t->prev;
    n = t->next;
    p->next = n;
    n->prev = p;
    delete t;
}
unsigned int Sublist::size() {
    return length;
}
void Sublist::clear() {
    Element* the_next = head;
    Element* previous = the_next;
    while(the_next != nullptr)
    {
        the_next = the_next->next;
        delete (previous);
        previous = the_next;
        length--;
    }
    head = nullptr;
}