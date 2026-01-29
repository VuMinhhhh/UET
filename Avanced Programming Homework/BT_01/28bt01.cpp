#include <bits/stdc++.h>

using namespace std;

int main() {
    for(int i = 0; i < 24; i++) {
        if(i == 0)
            cout << i + 12 << " midnight\n";
        else if(i == 12)
            cout << i << " noon\n";
        else if(i < 12)
            cout << i << "am\n";
        else
            cout << i - 12 << "pm\n";
    }
    return 0;
}


