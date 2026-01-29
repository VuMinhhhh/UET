#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[101][101] = {0};
    int count = 1;
    int i = 0;
    int j = n / 2;
    a[i][j] = count++;
    while(count <= n * n) {
        int inew = (i - 1) % n;
        if(inew < 0)
            inew += n;
        int jnew = (j + 1) % n;
        if(a[inew][jnew] != 0)
            i = (i + 1) % n;
        else {
            i = inew;
            j = jnew;
        }
        a[i][j] = count++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
