#include <iostream>
#include <vector>
using namespace std;

int guess(int num)
{
      int pick = 1;
      if (num == pick)
      {
            return 0;
      }
      else if (num > pick)
      {
            return -1;
      }
      else
      {
            return 1;
      }
}
int function(int n)
{
      int ans;
      int mid = n / 2;
      int low = 1;
      int high = n;
      for (ans = 1; ans <= n; ans++)
      {
            if (guess(mid) == 0)
            {
                  return mid;
            }
            else if (guess(mid) == -1)
            {
                  low = low;
                  high = mid - 1;
                  mid = ((high - low) / 2) + low;
            }
            else if (guess(mid) == 1)
            {
                  low = mid + 1;
                  high = high;
                  mid = ((high - low) / 2) + low;
            }
      }
      return 1;
}

int main()
{
      int n = 1;
      cout << function(n);
      return 0;
}