#include "arraylist.h"
#include <iostream>
using namespace std;

int main() {

    ArrayList<int> list;
    list.insert(0, 23);
    cout << list.find(23) << endl;

    return (0); 
}
