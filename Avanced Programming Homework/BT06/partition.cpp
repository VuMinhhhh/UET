#include <bits/stdc++.h>

using namespace std;
vector <int> kq;

void display() {
    for(auto it = kq.begin(); it != kq.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void partition(int sum, int limit) {
    if(sum == 0) {
        display();
        return;
    }
    if(limit > sum)
        limit = sum;
    for(int i = limit; i > 0; i--) {
        int temp = sum;
        kq.push_back(i);
        temp -= i;
        partition(temp, i);
        kq.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    partition(n, n);
}
