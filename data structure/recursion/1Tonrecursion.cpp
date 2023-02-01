#include <iostream>
#include <vector>
using namespace std;

void nTo1(int n)
{
      if (n == 0)
      {
            return;
      }
      cout << n << " ";
      nTo1(n - 1);
      return;
}
void oneToN(int n)
{
      if (n == 0)
      {
            return;
      }
      oneToN(n - 1);
      cout << n << " ";
      return;
}

int main()

{
      oneToN(5);
      return 0;
}