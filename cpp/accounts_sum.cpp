#include <iostream>
#include <vector>
using namespace std;

int function(vector<vector<int>> accounts)
{
      int s = 0;
      for (vector<int> value : accounts)
      {
            int ans = 0;

            for (int value2 : value)
            {
                  ans = ans + value2;
            }
            if (ans >= s)
            {
                  s = ans;
            }
      }

      return s;
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
      vector<vector<int>> v1 = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
      int res = function(v1);
      cout << res;
      return 0;
}