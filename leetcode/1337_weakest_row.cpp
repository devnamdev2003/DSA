#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> function(vector<vector<int>> &mat, int k)
{
      vector<int> ans;
      vector<int> index;
      int r = 0;
      int c = 0;
      for (int i = 0; i < (mat.size() * mat[0].size()); i++)
      {
            if (mat[r][mat[r].size() - 1] == 1 && c == mat[r].size() - 1)
            {
                  ans.push_back(mat[r].size() - 0);
                  index.push_back(r);
            }
            if (mat[r][c] == 0)
            {
                  if (c < mat[r].size())
                  {
                        ans.push_back(mat[r].size() - (mat[r].size() - c));
                        index.push_back(r);
                        i = i + ((mat[r].size() - c) - 1);
                        c = mat[r].size() - 1;
                  }
            }
            if (c <= mat[r].size())
            {
                  c++;
            }
            if (c == mat[r].size())
            {
                  c = 0;
                  r++;
            }
      }
      for (int i = 0; i < ans.size() - 1; i++)
      {
            for (int j = 0; j < (ans.size() - i) - 1; j++)
            {
                  if (ans[j] > ans[j + 1])
                  {
                        int temp = ans[j];
                        ans[j] = ans[j + 1];
                        ans[j + 1] = temp;
                        temp = index[j];
                        index[j] = index[j + 1];
                        index[j + 1] = temp;
                  }
            }
      }
      index.erase(index.begin() + k, index.end());
      return index;
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
      vector<vector<int>> v = {
          {1, 1, 0, 0, 0},
          {1, 1, 1, 1, 0},
          {1, 0, 0, 0, 0},
          {1, 1, 0, 0, 0},
          {1, 1, 1, 1, 1},
      };
      int k = 3;
      show(function(v, k));

      return 0;
}