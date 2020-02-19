#include <iostream>
#include "Sublist.h"
#include "Subvector.h"
#include "Stack.h"

using namespace std;

int main(){
    Sublist sl;
    Subvector sv;
    for(int i = 0; i < 5; i++){
        sl.push_back(i);
        sv.push_back(i);
    }
    for(int i = 0; i < 5; i++)
        cout << sl.pop_forward() << ' ';
    cout << endl;
    for(int i = 0; i < 5; i++)
        cout << sv.pop_back() << ' ';
    cout << endl;
}
