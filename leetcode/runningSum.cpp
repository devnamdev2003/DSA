#include <iostream>
#include <vector>
using namespace std;

vector<int> function(vector<int> nums)
{
      int sum=0;
      for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            nums[i]=sum;
      }
      return nums;
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
      vector<int> v1 = {1,2,3,4};
      show(v1);
      vector<int> v2 = function(v1);
      show(v2);
      return 0;
}