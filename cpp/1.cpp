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

void show_1d(vector<int> v)
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
void show_2d(vector<vector<int>> v)
{

      for (int i = 0; i < v.size(); i++)
      {
            for (int j = 0; j < v[1].size(); j++)
            {
                  cout << v[i][j] << " ";
            }
            cout << endl;
      }
}
int main()
{
      Solution obj;

      return 0;
}