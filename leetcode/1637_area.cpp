#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
class Solution
{
public:
      int maxWidthOfVerticalArea(vector<vector<int>> points)
      {
            vector<int> ans;
            int area = 0;
            for (int i = 0; i < points.size(); i++)
            {
                  ans.push_back(points[i][0]);
            }
            sort(ans.begin(), ans.end());
            for (int j = 0; j < ans.size() - 1; j++)
            {
                  if (ans[j + 1] - ans[j] >= area)
                  {
                        area = ans[j + 1] - ans[j];
                  }
            }

            return area;
      }
};
int main()
{
      Solution obj;
      cout << obj.maxWidthOfVerticalArea({{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}});
      return 0;
}