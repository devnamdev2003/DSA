#include <iostream>
#include <vector>
#include <string>
using namespace std;

int function(string jewels, string stones)
{
      int ans = 0;
      for (auto value : jewels)
      {
            for (auto value2 : stones)
            {
                  if (value2 == value)
                  {
                        ans++;
                  }
            }
      }

      return ans;
}

int main()
{
      string jewels = "aA", stones = "aAAbbbb";
      cout << function(jewels, stones);
      return 0;
}