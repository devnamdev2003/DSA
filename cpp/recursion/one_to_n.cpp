#include <iostream>
using namespace std;

int print(int n)
{
      if (n == 0)
      {
            return n;
      }
      print(n - 1);
      cout<< n << " ";
      return 0;
}
int main()
{
      int n;
      print(10);

      return 0;
}
