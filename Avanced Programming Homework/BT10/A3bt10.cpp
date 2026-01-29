#include <iostream>

using namespace std;

struct Point {
    double xpos;
    double ypos;
};

void print(Point A) {
    cout << "(" << A.xpos << "," << A.ypos << ")\n";
}

Point mid_point(const Point A, const Point B) {
    Point mid;
    mid.xpos = (A.xpos + B.xpos) / 2;
    mid.ypos = (A.ypos + B.ypos) / 2;
    return mid;
}

int main() {
    Point A, B;
    cin >> A.xpos >> A.ypos >> B.xpos >> B.ypos;
    Point mid = mid_point(A, B);
    print(mid);
}
