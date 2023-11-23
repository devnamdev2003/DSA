#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      vector<int> maxScoreIndices(vector<int> nums)
      {
            vector<int> ans = {};
            int l_zeros = 0, r_ones = 0;
            int i = 0;
            for (i = 0; i < nums.size(); i++)
            {
                  if (nums[i] == 1)
                  {
                        r_ones++;
                  }
            }
            ans.push_back(r_ones);
            i = 0;
            for (i = 0; i < nums.size(); i++)
            {
                  if (nums[i] == 0)
                  {
                        l_zeros++;
                        ans.push_back(l_zeros + r_ones);
                  }
                  else
                  {
                        r_ones--;
                        ans.push_back(l_zeros + r_ones);
                  }
            }
            i = 0;
            int max = 0;
            for (i = 0; i < ans.size(); i++)
            {
                  if (ans[i] > max)
                  {
                        max = ans[i];
                  }
            }
            i = 0;
            vector<int> ans2;
            for (i = 0; i < ans.size(); i++)
            {
                  if (ans[i] == max)
                  {
                        ans2.push_back(i);
                  }
            }

            // cout << max << endl;
            return ans2;
      }
};

void show_1d(vector<int> v)
{

      cout << "[";
      for (int i = 0; i < v.size(); i++)
      {
            if (i < v.size() - 1)
            {
                  cout << v[i] << ",";
            }
            else
            {
                  cout << v[i];
            }
      }
      cout << "]";
      cout << endl;
}
int main()
{
      Solution obj;
      show_1d(obj.maxScoreIndices({0, 0, 1, 0}));

      return 0;
}