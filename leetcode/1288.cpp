#include <iostream>
#include <vector>
using namespace std;
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
class Solution
{
public:
      int removeCoveredIntervals(vector<vector<int>> intervals)
      {
            for (int i = 0; i < intervals.size(); i++)
            {
                  for (int j = 0; j < intervals.size(); j++)
                  {
                        if (intervals[i][0] <= intervals[j][0] && i != j)
                        {
                              if (intervals[i][1] >= intervals[j][1])
                              {
                                    intervals.erase(intervals.begin() + j);
                                    i=0,j=0;
                              }
                        }
                  }
            }
            return intervals.size();
      }
};

int main()
{
      Solution obj;
      cout << obj.removeCoveredIntervals({{1, 4}, {3, 6}, {2, 8}})<<endl;
      cout << obj.removeCoveredIntervals({{1, 2}, {1, 4}, {3, 4}}) << endl;
      cout << obj.removeCoveredIntervals({{34335, 39239}, {15875, 91969}, {29673, 66453}, {53548, 69161}, {40618, 93111}});

      return 0;
}