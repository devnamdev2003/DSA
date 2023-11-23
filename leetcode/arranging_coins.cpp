#include <iostream>
using namespace std;

int function(int n)
{

      int m = n;
      int count = 0;
      if (n == 1)
      {
            return 1;
      }
      for (int i = 1; i <= m; i++)
      {
            n = n - i;
            count++;
            if (n < 0)
            {
                  return count - 1;
            }
      }

      return count - 1;
}
int main()
{
      int n = 1;
      cout << function(n);
}