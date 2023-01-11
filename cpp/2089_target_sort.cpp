#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// vector<int> v = {1,5,4, 3};

vector<int> function(vector<int> nums, int target)
{
      vector<int> ans = {};
      for (int i = 0; i < nums.size() - 1; i++)
      {
            int k = (nums.size() - i) - 1;
            for (int j = 0; j < k; j++)
            {
                  if (nums[j] > nums[j + 1])
                  {
                        int temp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = temp;
                  }
            }
            if (nums[k] == target)
            {
                  ans.push_back(k);
            }

            if (nums[k] < target)
            {
                  break;
            }
      }
      if (nums[0] == target)
      {
            ans.push_back(0);
      }

      reverse(ans.begin(), ans.end());
      return ans;
}
void show(vector<int> v)
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
      vector<int> v = {2, 1};
      int tar = 1;
      show(function(v, tar));

      return 0;
}