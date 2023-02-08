#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
      int removeElement(vector<int> nums, int val)
      {
            int i = 0;

            for (const int num : nums)
                  if (num != val)
                        nums[i++] = num;

            return i;
      }
};

int main()
{
      Solution obj;
      cout << obj.removeElement({3, 2, 2, 3}, 3);

      return 0;
}