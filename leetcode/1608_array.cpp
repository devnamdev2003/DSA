#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> nums)
{
      int i = 1, j = nums.size();
      while (i <= j)
      {
            int mid = i + (j - i) / 2, cnt = 0;
            for (int k = 0; k < nums.size(); k++)
            {
                  if (nums[k] >= mid)
                  {
                        cnt++;
                  }
            }
            if (cnt == mid)
            {
                  return mid;
            }
            else if (cnt < mid)
            {
                  j = mid - 1;
            }
            else
            {
                  i = mid + 1;
            }
      }
      return -1;
}

int main()
{
      vector<int> v1 = {3, 5};
      cout << function(v1);

      return 0;
}
