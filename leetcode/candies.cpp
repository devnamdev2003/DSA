#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> function(vector<int> candies, int extraCandies)
{
      vector<bool> ans;
      int first = candies[0];
      for (auto value : candies)
      {
            if (first <= value)
            {
                  first = value;
            }
      }
      for (auto value : candies)
      {
            if ((value + extraCandies) >= first)
            {
                  ans.push_back(true);
            }
            else
            {
                  ans.push_back(false);
            }
      }

      return ans;
}
void show(auto v)
{

      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      cout << endl;
}
int main()
{
      vector<int> v1 = {12, 1, 12};
      show(v1);
      int extraCandies = 10;
      vector<bool> v2 = function(v1, extraCandies);
      show(v2);
      return 0;
}