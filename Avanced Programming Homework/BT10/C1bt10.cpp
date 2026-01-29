#include <iostream>
#include <cstring>

using namespace std;

struct String {
    int n;
    const char* str;
    String (char* s) {
        n = strlen(s);
        str = new char [n];
        str = s;
    }
    ~String () {
        delete [] str;
        str = NULL;
    }
    void print() {
        cout << s.str << endl;
    }
    void append(const char* t) {

    }
};

int main() {
    String s("Hello");
    cout << s.str;
    return 0;
}
