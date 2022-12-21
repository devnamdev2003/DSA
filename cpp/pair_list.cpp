#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> function(vector<int> nums)
{
      vector<int> ans;
      for (int i = 0; i < nums.size(); i = i + 2)
      {
            for (int j = 0; j < nums[i]; j++)
            {
                  ans.push_back(nums[i + 1]);
            }
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
      vector<int> v1 = {1, 2, 3, 4};
      show(v1);
      vector<int> v2 = function(v1);
      show(v2);
      return 0;
}