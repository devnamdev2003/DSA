#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
      vector<int> sortedSquares(vector<int> nums)
      {
            int i;
            int j;
            for (j = 0; j < nums.size(); j++)
            {
                  nums[j] = nums[j] * nums[j];
            }
            sort(nums.begin(), nums.end());
            return nums;
      }
};
void show(vector<int> v)
{
      cout << "[";
      for (int i = 0; i < v.size(); i++)
      {
            if (i < v.size() - 1)
            {
                  cout << v[i] << ",";
            }
            else
            {
                  cout << v[i];
            }
      }
      cout << "]";
      cout << endl;
}
int main()
{
      vector<int> v = {-4, -3, 0, 3, 5, 8};
      Solution obj;
      show(obj.sortedSquares(v));
}