#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int Max = -1e9, Min = 1e9;
    double Mean = 0;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x > Max)
            Max = x;
        if(x < Min)
            Min = x;
        Mean += x;
    }
    Mean /= n;
    cout << "Mean: " << fixed << setprecision(2) << Mean << endl;
    cout << "Max: " << Max << endl;
    cout << "Min: " << Min << endl;
    return 0;
}


