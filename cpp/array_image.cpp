#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> flipAndInvertImage(vector<vector<int>> image)
{

      vector<vector<int>> ans;
      for (int i = 0; i < image.size(); i++)
      {
            vector<int> v1;
            for (int j = image[i].size() - 1; j >= 0; j--)
            {
                  v1.push_back(image[i][j]);
            }
            ans.push_back(v1);
      }
      for (int i = 0; i < image.size(); i++)
      {
            for (int j = 0; j < image[i].size(); j++)
            {
                  if (ans[i][j] == 0)
                  {
                        ans[i][j] = 1;
                  }
                  else
                  {
                        ans[i][j] = 0;
                  }
            }
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
      vector<vector<int>> v1 = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
      show(v1);
      vector<vector<int>> v2 = flipAndInvertImage(v1);
      show(v2);
      return 0;
}