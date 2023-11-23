#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> nums)
{
      int pos=0;
      int neg=0;
      for (int i = 0; i < nums.size(); i++)
      {
            if (nums[i] > 0)
            {
                  pos++;
            }
            if (nums[i] < 0)
            {
                  neg++;
            }
      }
      if (pos > neg)
      {
            return pos;
      }
      else
      {
            return neg;
      }
}
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
      vector<int> v = {-3, -2, -1, 0, 0, 1, 2};
      cout << function(v);

      return 0;
}