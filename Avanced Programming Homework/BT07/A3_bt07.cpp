#include <iostream>

using namespace std;

int count_even(int *ptr, int n) {
    int count = 0;
    for(int i = 0; i < n; i++)
        if(*(ptr + i) % 2 == 0) count++;
    return count;

}

int main (){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << count_even(a, n);
    return 0;
}

