
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    cout << a << " ";
    int b = 1e9;
    while(b >= 0) {
        cin >> b;
        if(b != a && b >= 0)
            cout << b << " ";
        a = b;
    }
    return 0;
}
