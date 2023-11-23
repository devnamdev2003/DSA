#include <iostream>
#include <vector>
using namespace std;

bool function(int n, vector<vector<int>> nums, int s, int d)
{
      bool ans = 0;
      vector<vector<int>> v;
      for (int i = 0; i < nums.size(); i++)
      {
            if (s == nums[i][0] || s == nums[i][1])
            {
                  v[0].push_back(nums[i][0]);
                  v[0].push_back(nums[i][1]);
            }
            cout << nums[i][0] << " ";
            cout << nums[i][1] << " ";
            cout << endl;
      }
      return ans;
}
void show(vector<vector<int>> v)
{

      for (int i = 0; i < v.size(); i++)
      {
            for (int j = 0; j < v[i].size(); j++)
            {
                  cout << v[i][j] << " ";
            }
            cout << endl;
      }
}
int main()
{
      vector<vector<int>> v1 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
      int n = 5;
      int source = 0;
      int des = 5;
      // show(v1);
      bool res = function(n, v1, source, des);
      cout << res;
      return 0;
}