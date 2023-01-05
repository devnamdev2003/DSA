#include <iostream>
#include <vector>
using namespace std;
int function(vector<vector<int>> grid)
{
      int ans = 0;
      int size = grid.size() * grid[0].size();
      int r = 0;
      int c = 0;
      for (int i = 0; i < size; i++)
      {
            if (grid[r][c] < 0)
            {
                  // ans++;
                  if (c < grid[r].size())
                  {
                        ans = ans + (grid[r].size() - c);
                        i = i + ((grid[r].size() - c) - 1);
                        c = grid[r].size() - 1;
                  }
            }
            if (c <= grid[r].size())
            {
                  c++;
            }
            if (c == grid[r].size())
            {
                  c = 0;
                  r++;
            }
      }

      return ans;
}
int main()
{
      vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
      cout << function(grid);
      return 0;
}