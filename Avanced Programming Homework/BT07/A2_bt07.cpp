#include <iostream>

using namespace std;

void f(int a[50]) {
    cout << sizeof(a);
}

int main (){
    int a[50];
    cout << sizeof(a) << endl;
    f(a);
    return 0;
}

