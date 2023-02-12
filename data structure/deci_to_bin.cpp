#include <iostream>
using namespace std;
void conversion(int n)
{
      if (n == 0)
      {
            return;
      }
      conversion(n / 2);
      cout << n % 2;
}
int main()
{
      // int n = 4;
      // int q = n;
      // while (q != 0)
      // {
      //       cout << q % 2;
      //       q = q / 2;
      // }
      conversion(120);
      return 0;
}