#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> function(vector<int> nums)
{
      vector<int> ans;
      int count;
      for (int i = 0; i < nums.size(); i++)
      {
            count=0;
            for (int j = 0; j < nums.size(); j++)
            {
                  if (nums[i] > nums[j])
                  {
                        count=count+1;
                  }
            }
            ans.push_back(count);
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
      vector<int> v1 = {8, 1, 2, 2, 3};
      vector<int> v2 = function(v1);
      show(v2);
      return 0;
}