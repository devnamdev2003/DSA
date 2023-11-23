#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
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
class Solution
{
public:
      vector<int> findKDistantIndices(vector<int> nums, int key, int k)
      {
            vector<int> v1;
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                  if (nums[i] == key)
                  {
                        v1.push_back(i);
                        for(int m=0;m<nums.size();m++){
                              
                        }
                  }
            }
            for (int j = 0; j < nums.size(); j++)
            {
                  for (int l = 0; l < v1.size(); l++)
                  {
                        if (std::abs(j - v1[l]) <= k)
                        {
                              ans.push_back(j);
                              break;
                        }
                  }
            }

            return ans;
      }
};

int main()
{
      vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
      int key = 9;
      int k = 1;
      Solution obj;
      show_1d(obj.findKDistantIndices(nums, key, k));
      return 0;
}