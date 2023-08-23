#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
      int largestAltitude(vector<int> gain)
      {
            int max = 0;
            int sum = 0;
            for (auto val : gain)
            {
                  sum = sum + val;
                  if (sum >= max)
                  {
                        max = sum;
                  }
            }
            return max;
      }
};
int main()
{
      Solution obj;
      cout << obj.largestAltitude({-4, -3, -2, -1, 4, 3, 2});
}