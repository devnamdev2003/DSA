#include <iostream>
using namespace std;
int function(int n)
{
      if (n % 2 == 0)
      {
            return n;
      }
      else
      {
            return n * 2;
      }
}
int main()
{

      int n = 6;
      cout << function(n);

      return 0;
}