#include <bits/stdc++.h>

using namespace std;

int zeller_congruence (int day, int month, int year) {
    if(month == 1 || month == 2)
        month += 12;
    int k = year % 100;
    int j = year / 100;
    return (day + (13 * (month + 1) / 5) + k + (k / 4) + 5 - j) % 7;
}

int main() {
    int day, month, year;
    cin >> day >> month >> year;
    int check = zeller_congruence(day, month, year);
    switch (check) {
    case 0:
        cout << "sunday" << endl;
        break;
    case 1:
        cout << "monday" << endl;
        break;
    case 2:
        cout << "tuesday" << endl;
        break;
    case 3:
        cout << "wednesday" << endl;
        break;
    case 4:
        cout << "thursday" << endl;
        break;
    case 5:
        cout << "friday" << endl;
        break;
    case 6:
        cout << "saturday" << endl;
        break;
    }
    return 0;
}


