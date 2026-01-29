#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        } int b[n];
        b[0] = a[0];
        bool check = 1;
        for(int i = 1; i < n; i++)
            b[i] = b[i - 1] + a[i];
        for(int i = 0; i < n; i++)
            if(b[i] - a[i] == 1.0 * (sum - a[i]) / 2) {
                check = 0;
                break;
            }
        if(check)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
