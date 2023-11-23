#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> function(vector<int> nums, vector<int> index)
{
      vector<int> ans;
      auto it = nums.begin();
      for (int i = 0; i < nums.size(); i++)
      {
            it = ans.begin() + index[i];
            ans.insert(it, nums[i]);
      }

      return ans;
}
void show(vector<int> v)
{

      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      cout << endl;
}
int main()
{
      vector<int> v1 = {0, 1, 2, 3, 4};
      auto index = {0, 1, 2, 2, 1};
      vector<int> v2 = function(v1, index);
      show(v2);
      return 0;
}