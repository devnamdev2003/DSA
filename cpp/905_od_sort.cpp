#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
      vector<int> sortArrayByParity(vector<int> nums)
      {
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                  if (nums[i] % 2 == 0)
                  {
                        ans.insert(ans.begin(), nums[i]);
                  }
                  else
                  {
                        ans.insert(ans.end(), nums[i]);
                  }
            }
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
};

int main()
{
      vector<int> v = {2, 3, 1, 4};
      Solution s;
      s.show(s.sortArrayByParity(v));
}
