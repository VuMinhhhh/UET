#include <iostream>
using namespace std;
int main ()
{
	int* p = new int;
 	int* p2 = p;
 	*p = 10;
 	delete p; 
	*p2 = 100; 
 	cout << *p2;
 	delete p2; //p2 khong phai la con tro kieu cap phat dong; LTV khong duoc tu xoa 
	return 0;
}
