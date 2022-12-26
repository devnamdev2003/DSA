#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int function(vector<int> nums, int k)
{
      int ans = 0;
      for (int i = 0; i < nums.size(); i++)
      {
            for (int j = 0; j < nums.size(); j++)
            {
                  if (nums[i] == nums[j] && i != j)
                  {
                        cout << nums[i] << ":" << i << " " << nums[j] << ":" << j << endl;
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
      vector<int> v1 = {3, 1, 2, 2, 2, 1, 3};
      int k = 2;
      cout << function(v1, k);
      return 0;
}