#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> nums, int target)
{
      int mid = nums.size() / 2;
      int low = 0;
      int high = nums.size() - 1;
      for (int i = 0; i < nums.size(); i++)
      {
            if (nums[mid] == target)
            {
                  return mid;
            }
            else if (nums[mid] > target)
            {
                  high = mid - 1;
                  mid = ((high - low) / 2) + low;
            }
            else if (nums[mid] < target)
            {
                  low = mid + 1;
                  mid = ((high - low) / 2) + low;
            }
      }

      return -1;
}
int main()
{
      vector<int> v1 = {-1, 0, 3, 5, 9, 12};
      // for (int i = 0; i < v1.size(); i++)
      // {
      //       cout << function(v1, v1[i]) << v1[i] << endl;
      // }
      function(v1, 54);

      return 0;
}