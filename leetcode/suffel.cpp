#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> function(vector<int> nums, int n)
{
      for (int i = n; i > 0; i--)
      {
            auto point = nums.begin();
            nums.insert(point + i, nums[(n * 2) - 1]);
            nums.pop_back();
      }
      return nums;
}
void show(vector<int> v)
{
      auto it = v.begin();

      // for (it = v.begin(); it < v.end(); it++)
      // {
      //       cout << *it << " ";
      // }
      for (int value : v)
      {
            cout << value << " ";
      }
      cout << endl;
}
int main()
{
      vector<int> v1 = {1, 2, 3, 4};
      int n = 2;
      show(v1);
      vector<int> v2 = function(v1, n);
      show(v2);
      return 0;
}