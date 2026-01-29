#include <iostream>

using namespace std;

struct Point {
    int xpos;
    int ypos;
};

void print1(Point A) {
    cout << &A << endl;;
}

void print2(Point &A) {
    cout << &A << endl;
}

int main() {
    Point A;
    cin >> A.xpos >> A.ypos;
    cout << &A << endl;
    print1(A);
    print2(A);
}

