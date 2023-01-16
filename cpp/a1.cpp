#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      int function(vector<int> arr)
      {
            int ans;

            return ans;
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
      Solution obj;

      return 0;
}