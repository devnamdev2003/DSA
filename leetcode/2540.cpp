#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      int getCommon(vector<int> nums1, vector<int> nums2)
      {
            int ans;
            for (int i = 0; i < nums1.size(); i++)
            {
                  int index = bin_recursive(nums2, nums1[i], 0, nums2.size());
                  if (index == -1)
                  {
                        continue;
                  }
                  return nums2[index];
            }
            return -1;
      }
      int bin_recursive(vector<int> arr, int target, int low, int high)
      {

            if (low > high)
            {
                  return -1;
            }
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
            {
                  return mid;
            }
            if (arr[mid] > target)
            {
                  return bin_recursive(arr, target, low, mid - 1);
            }
            return bin_recursive(arr, target, mid + 1, high);
      }
};

int main()
{
      Solution obj;
      cout << obj.getCommon({1, 2, 3}, {2, 4});
      return 0;
}