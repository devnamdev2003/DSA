#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> getConcatenation(vector<int> nums)
{
      vector<int> ans(nums);
      for (int i = 0; i < nums.size(); i++)
      {
            ans.push_back(nums[i]);
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
      vector<int> v1 = {0,2,1,5,3,4};
      show(v1);

      vector<int> v2 = getConcatenation(v1);
      show(v2);
      return 0;
}