#include <iostream>

using namespace std;

int main()  {
   char *s;
   char foo[] = "Hello World";
   s = foo;
   cout << s << endl;
   s[0] = foo[0];
   cout << s[0] << endl;
   return(0);
}
