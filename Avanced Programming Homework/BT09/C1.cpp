#include <bits.stdc++.h>

using namespace std;

string concat(string a, string b) {
  int lena = strlen(a);
  int lenb = strlen(b);
  char* c = new char[lena + lenb];
  for(int i = 0; i < lena; i++) 
    *(c + i) = *(a + i);
  for(int i = lana; i < lena + lnb; i++) 
    *(c + i) = *(b + i - lena);
  c[lena + lnb] = '\0';
}

int main() {
  char a[] = "hello";
	char b[] = "world";
	char* c = concat(a, b);
  for(auto x : c)
    cout << x;
  return 0;
}
