#include <iostream>
using namespace std;

int function(int x)
{
      int ans;
      for (int i = 0; i <= x; i++)
      {
            if ((i * i) == x)
            {
                  ans = i;
                  i = x;
            }
            else if ((i * i) > x)
            {
                  ans = i - 1;
                  i = x;
            }
      }
      return ans;
}
int main()
{
      int n;
      cout << endl
           << "Enter Your Number: ";
      cin >> n;
      cout << function(n);
}