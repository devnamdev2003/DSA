#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int function(vector<int> nums)
{
      int ans = 0;
      for (int i = 0; i < nums.size(); i++)
      {
            for (int j = i + 1; j < nums.size(); j++)
            {
                  if (nums[i] == nums[j])
                  {
                        ans++;
                  }
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
      vector<int> v1 = {1,1,1,1};
      show(v1);
      cout << function(v1);
      return 0;
}