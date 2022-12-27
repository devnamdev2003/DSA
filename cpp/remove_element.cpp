#include <iostream>
#include <vector>
using namespace std;
// vector<int> v1 = {0, 1, 2, 2, 3, 0, 4, 2};
int function(vector<int> nums, int val)
{
      int ans = 0;
      vector<int> v(nums);
      for (int i = 0; i < v.size(); i++)
      {
            if (nums[i] == val)
            {
                  auto it = nums.begin();
                  nums.erase(it + i);
            }
      }
      return nums.size() - ans;
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
      vector<int> v1 = {0, 1, 2, 2, 3, 0, 4, 2};
      int key = 2;
      cout << function(v1, key);
      return 0;
}