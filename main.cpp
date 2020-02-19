#include <iostream>
#include "Sublist.h"
#include <fstream>
using namespace std;

int main()
{
    Sublist l;
    l.push_back(5);
    l.push_back(4);
    l.push_back(3);
    l.push_where(1, 2);
    cout << l.pop_forward() << ' ';
    cout << l.pop_forward() << ' ';
    cout << l.pop_forward() << ' ';
    cout << l.pop_forward() << endl;
    cout << "Actual length: " << l.size() << "; and actual pointer to the head: " << hex << l.geth() << endl;
    for(int i = 5; i >= 0; i--)
        l.push_back(i);
    l.erise_where(5);
    for(int i = 0; i < 5; i++)
        cout << l.pop_forward() << ' ';
    cout << endl;
    cout << "Actual length: " << l.size() << "; and actual pointer to the head: " << hex << l.geth() << endl;
    for(int i = 5; i >= 0; i--)
        l.push_back(i);
    l.clear();
    cout << "Actual length: " << l.size() << "; and actual pointer to the head: " << hex << l.geth() << endl;
    return 0;
}