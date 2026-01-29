#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool check_SNT (int n) {\
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return n > 1;
}

int main() {
    int n;
    cin >> n;
    if(check_SNT(n))
        cout << "YES";
    else
        cout << "NO";
}

