#include <iostream>
#include <vector>
using namespace std;
bool function(vector<vector<int>> matrix, int target)
{
      bool ans = 0;
      int size = matrix.size() * matrix[0].size();
      int r = 0;
      int c = 0;
      for (int i = 0; i < size; i++)
      {
            if (matrix[r][c] == target)
            {
                  ans = true;
                  return ans;
            }
            if (c <= matrix[r].size())
            {
                  c++;
            }
            if (c == matrix[r].size())
            {
                  c = 0;
                  r++;
            }
      }

      return ans;
}
int main()
{
      vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
      int target = 0;

      cout << function(matrix, target);
      return 0;
}