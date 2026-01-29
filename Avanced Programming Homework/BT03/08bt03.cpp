#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long sum = 0;
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        sum += a[i] * (n - 1 - i);
    cout << sum;
    return 0;
}
