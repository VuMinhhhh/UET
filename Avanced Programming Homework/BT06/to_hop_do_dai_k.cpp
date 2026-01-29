#include <bits/stdc++.h>

using namespace std;

vector <char> v;
char mang[26];
int n, k;
bool FalseCheck = 1;
int solution = 1;

void display () {
    cout << "Case " << solution++ << ": ";
    cout << "{";
    for(auto it = v.begin(); it != v.end(); it++) {
        if(it + 1 == v.end())
            cout << *it;
        else
            cout << *it << ", ";
    }
    cout << "}\n";
}

void solve(int left, int right) {
    if(v.size() == k) {
        FalseCheck = 0;
        display();
    }
    if(right - left + 1 < k - v.size())
        return;
    for(int i = left; i <= right; i++) {
        v.push_back(mang[i]);
        solve(i + 1, right);
        v.pop_back();
    }
}

int main() {
    for(int i = 0; i < 26; i++)
        mang[i] = char(i + 97);
    cin >> n >> k;
    solve(0, n - 1);
    if(FalseCheck)
        cout << "No array";
}
