#include <iostream>
#include <vector>
using namespace std;
int function(vector<vector<int>> grid)
{
      int ans = 0;
      int index;
      int size = grid[0].size();
      for (int k = 0; k < size; k++)
      {
            vector<int> maxx;
            for (int i = 0; i < grid.size(); i++)
            {
                  int max = 0;
                  for (int j = 0; j < grid[i].size(); j++)
                  {
                        if (grid[i][j] >= max)
                        {
                              index = j;
                              max = grid[i][j];
                        }
                  }
                  grid[i].erase(grid[i].begin() + index);
                  maxx.push_back(max);
            }
            int large = 0;
            for (int i = 0; i < maxx.size(); i++)
            {
                  if (maxx[i] > large)
                  {
                        large = maxx[i];
                  }
            }
            ans = ans + large;
      }
      return ans;
}

int main()
{
      vector<vector<int>> grid = {{1, 2, 4}, {3, 3, 1}};
      cout << function(grid);
      return 0;
}