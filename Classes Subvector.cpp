#include <iostream>
#include <fstream>

using namespace std;

class Subvector
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
Subvector::Subvector()
{
    mass = NULL;
    top = 0;
    capacity = 0;
}
Subvector::~Subvector()
{
    delete[] mass;
    top = 0;
    capacity = 0;
    mass = NULL;
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
    if (top == 0) {cout << "Sigmentation" << endl; return 0;}
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
    if(!file)
        cout << "There are no file\n" << endl;

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
int main()
{
    Subvector s;
    char name[] = "test";

    //check pop&push
    for(int i = 1; i < 7; i++)
        s.push_back(i);
    for(int i = 1; i < 7; i++)
            cout << s.pop_back() << ' ';
    s.clear();
////////////////////////////////////////////////////////////////////////
    //check resize
    for(int i = 1; i < 7; i++)
        s.push_back(i);
        cout << s.get_capacity() << ' ' << s.get_top() << endl;
    s.resize(3);
        cout << s.get_capacity() << ' ' << s.get_top() << endl;
    for(int i = 1; i < 4; i++)
            cout << s.pop_back() << ' ';
    s.clear();
////////////////////////////////////////////////////////////////////////
    //check shrink_to_fit&clear;
    for(int i = 1; i < 7; i++)
    s.push_back(i);
    s.pop_back();
    s.pop_back();
    cout << s.get_top() << ' ' << s.get_capacity() << endl;
    s.shrink_to_fit();
    cout << s.get_top() << ' ' << s.get_capacity() << endl;
    s.clear();
    cout << s.get_top() << ' ' << s.get_capacity() << endl;
    s.clear();
////////////////////////////////////////////////////////////////////////
    //check reading from file
    s.init_from_file(name, &s);
    cout << s.get_capacity() << ' ' << s.get_top() << endl;

    for(int i = 0; i < 6; i++)
        cout << s.pop_back() << ' ';
    s.clear();

    return 0;
}
