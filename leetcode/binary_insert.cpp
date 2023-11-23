#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> nums, int target)
{
      int ans = -1;
      int len = nums.size();
      int mid = len / 2;
      int low = 0;
      int high = len;
      for (int i = 0; i < len; i++)
      {

            if (nums[mid] == target)
            {
                  return mid;
            }
            else if (nums[mid] > target)
            {
                  low = low;
                  high = mid;
                  mid = ((high - low) / 2) + low;
            }
            else if (nums[mid] < target)
            {
                  low = mid + 1;
                  if (low == len)
                  {
                        return low;
                  }
                  high = len;
                  mid = ((high - low) / 2) + low;
            }
      }

      return mid;
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
      vector<int> v1 = {3, 4, 9, 12};
      // for (int i = 0; i < v1.size(); i++)
      // {
      //       cout << function(v1, v1[i]) << v1[i] << endl;
      // }
      cout << function(v1, 5);

      return 0;
}