#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int a[m][n];
    int r1 = 0, c1 = 0;
    int r2 = n - 1;
    int c2 = m - 1;
    int count = 0;
    while(c1 <= c2 && r1 <= r2) {
        for(int i = r1; i <= r2; i++) {
            count++;
            a[c1][i] = count;
        }
        c1++;
        for(int i = c1; i <= c2; i++) {
            count++;
            a[i][r2] = count;
        }
        r2--;
        for(int i = r2; i >= r1; i--) {
            count++;
            a[c2][i] = count;
        }
        c2--;
        for(int i = c2; i >= c1; i--) {
            count++;
            a[i][r1] = count;
        }
        r1++;
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
