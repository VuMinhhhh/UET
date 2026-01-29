#include <iostream>

using namespace std;

bool check_reverse(string a, string b) {
    for(int i = 0; i < a.size() / 2; i++)
        swap(a[i], a[a.size() - 1 - i]);
    return a == b;
}

int main() {
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++) {
        string x = a[i];
        string y = a[j];
        if(check_reverse(x, y)) {
            int z = x.size();
            cout << z << " " << x[z / 2] << endl;
            return 0;
        }
    }


}
