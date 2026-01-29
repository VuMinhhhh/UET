#include <bits/stdc++.h>

using namespace std;

void f(int xval)
{
   int x;
   x = xval;
   // in địa chỉ của x tại đây
}
void g(int yval)
{
   int y;
   // in địa chỉ của y tại đây
}
/*
vị trí của stack frame cho hàm f khi nó chạy trùng với vị trí của hàm g khi nó được gọi, cả hai hàm f và g cùng có 1 tham số kiểu int, cùng kiểu trả về,
x và y cùng là biến địa phương đầu tiên của hàm, do đó khả năng lớn là trình biên dịch xếp x và y ở cùng một địa chỉ.
*/

int main()
{
   f(7);
   g(11);
   return 0;
} 
