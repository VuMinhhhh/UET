#include <iostream>

using namespace std;

int Binary_search(int *a, int l, int r, int x) {
    while(l <= r) {
        int m = (l + r) / 2;
        if(a[m] == x)
            return m;
        else if(a[m] > x)
            return Binary_search(a, l, m - 1, x);
        else
            return Binary_search(a, m + 1, r, x);
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << Binary_search(a, 0, n - 1, x);
    return 0;
}
