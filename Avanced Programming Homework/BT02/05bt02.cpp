#include <iostream>


using namespace std;
string one[] = { "", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten ", "eleven ", "twelve ",
                 "thirteen ", "fourteen ", "fifteen ",
                 "sixteen ", "seventeen ", "eighteen ",
                 "nineteen " };
string ten[] = { "", "", "twenty", "thirty", "forty",
                 "fifty", "sixty", "seventy", "eighty",
                 "ninety" };

string numToWords(int n, string s) {
    string str = "";
    if(n <= 19)
        str += one[n];
    else if (20 <= n && n <= 99)
        str += ten[n / 10] + "-" + one[n % 10];
    else if (100 <= n && n <= 999) {
        str += one[n / 100] + "hundred ";
        n %= 100;
        str += numToWords(n, "");
    }
    if(n)
        str += s;
    return str;
}

int main(){
    int n;
    cin >> n;
    string s;
    if(n == 0) {
        cout << "zero";
        return 0;
    } else if(n < 0) {
        n = - n;
        s += "negative ";
    }
    s += numToWords(n / 1000000, "million ");
    s += numToWords((n / 1000) % 1000, "thousand ");
    s += numToWords(n % 1000, "");
    cout << s;
    return 0;
}

