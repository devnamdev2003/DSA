#include <iostream>
#include <vector>
using namespace std;
vector<int> function(vector<int> nums, int target)
{
      int mini = -1;
      int maxi = -1;
      // start pos of target
      int low = 0;
      int high = nums.size() - 1;
      while (low <= high)
      {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                  high = mid - 1;
                  if (nums[mid] == target)
                        mini = mid;
            }
            else
            {
                  low = mid + 1;
            }
      }
      // search for last pos of target
      low = 0;
      high = nums.size() - 1;
      while (low <= high)
      {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
            {
                  low = mid + 1;
                  if (nums[mid] == target)
                        maxi = mid;
            }
            else
            {
                  high = mid - 1;
            }
      }
      return {mini, maxi};
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
      vector<int> v1 = {5, 5, 5, 7, 7, 8, 8, 10};
      int target = 5;
      vector<int> v2 = function(v1, target);
      show(v2);
      return 0;
}