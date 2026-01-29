#include <iostream>

using namespace std;

struct Point {
    int xpos;
    int ypos;
};

void print(Point A) {
    cout << "(" << A.xpos << "," << A.ypos << ")\n";
}

int main() {
    Point A;
    cin >> A.xpos >> A.ypos;
    print(A);
}
