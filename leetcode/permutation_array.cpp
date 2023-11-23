#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> function(vector<int> nums)
{
      vector<int> ans;
      for(int i=0;i<nums.size();i++){
            ans.push_back(nums[nums[i]]);
      }
      return ans;
}
void show(vector<int> v)
{

      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      cout<<endl;
}
int main()
{
      vector<int> v1 = {0,2,1,5,3,4};
      show(v1);
      vector<int> v2 = function(v1);
      show(v2);
      return 0;
}