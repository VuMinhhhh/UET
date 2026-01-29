#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    double p = 1.0 * (a + b + c) / 2;
    int S = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << fixed << setprecision(2) << S;
    return 0;
}

