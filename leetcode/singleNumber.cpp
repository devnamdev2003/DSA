#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int function(vector<int> nums)
{
      int j, i;
      for (i = 0; i < nums.size(); i++)
      {
            for (j = 0; j < nums.size(); j++)
            {
                  if (nums[i] == nums[j] && i != j)
                  {
                        break;
                  }
            }
            if (j == nums.size() - 1)
            {
                  break;
            }
      }

      return nums[i];
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
      vector<int> v1 = {4, 1, 2, 1, 2};
      show(v1);
      cout << function(v1);
      return 0;
}