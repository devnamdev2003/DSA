#include <iostream>
#include <cmath>
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
bool fun(int n)
{
      // if (n <= 0)
      // {
      //       return 0;
      // }
      // double ans = log2(n);
      // return (int(ans) == ans);
      if (n <= 0)
      {
            return 0;
      }
      else
      {
            int i = 0;
            while (pow(2, i) <= n)
            {
                  if (pow(2, i) == n)
                  {
                        return 1;
                  }
                  i++;
            }
            return 0;
      }
}

int main()
{
      cout << fun(16);
      // int n = 4;
      // int q = n;
      // while (q != 0)
      // {
      //       cout << q % 2;
      //       q = q / 2;
      // }
      // conversion(120);
      // for (int i = 0; i <= 30; i++)
      // {
      //       int p = pow(2, i);
      //       cout << p << endl;
      // }
      return 0;
}