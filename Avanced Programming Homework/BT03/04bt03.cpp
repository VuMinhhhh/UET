#include <iostream>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int m, n;
    cin >> m >> n;
    char a[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    int b[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '.') {
                b[i][j] = 0;
                for(int k = 0; k < 8; k++) {
                    int inew = i + dx[k];
                    int jnew = j + dy[k];
                    if(inew >= 0 && inew < m && jnew >= 0 && jnew < n && a[inew][jnew] == '*')
                        b[i][j]++;
                }
            } else
                b[i][j] = -1e9;
        }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            if(a[i][j] == '*')
                cout << a[i][j] << " ";
            else
                cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}
