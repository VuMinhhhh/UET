#include <bits/stdc++.h>

using namespace std;

int main( )
{ 
   char a[4] = "abc"; 
   for (char *cp = a; (*cp) != '\0'; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   } 
   return 0;
}
