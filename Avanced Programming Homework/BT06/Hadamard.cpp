#include <iostream>
#include <cmath>

using namespace std;

char a[1000][1000];

char getFlag(bool flag) {
    if(flag == 0) return '.';
    return 'o';
}

void solve(int xpos, int ypos, int n, bool flag) {
    if(n == 1) {
        a[xpos][ypos] = getFlag(flag);
        return;
    }
    solve(xpos, ypos, n / 4, flag);
    solve(xpos + sqrt(n) / 2, ypos, n / 4, flag);
    solve(xpos, ypos + sqrt(n) / 2, n / 4, flag);
    solve(xpos + sqrt(n) / 2, ypos + sqrt(n) / 2, n / 4, !flag);
}

int main() {
    int n;
    cin >> n;
    int z = pow(2, n);
    solve(0, 0, z * z, 0);
    for(int i = 0; i < z; i++) {
        for(int j = 0; j < z; j++)
            cout << a[i][j];
        cout << endl;
    }
}
