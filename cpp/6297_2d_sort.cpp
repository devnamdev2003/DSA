#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
      vector<vector<int>> sortTheStudents(vector<vector<int>> score, int k)
      {
            vector<int> max;
            vector<vector<int>> ans;

            for (int i = 0; i < score.size(); i++)
            {
                  max.push_back(score[i][k]);
            }
            sort(max.begin(), max.end(),greater<int>());
            for (int j = 0; j < max.size(); j++)
            {
                  for (int m = 0; m < score.size(); m++)
                  {
                        if (max[j] == score[m][k])
                        {
                              ans.push_back(score[m]);
                        }
                  }
            }
            return ans;
      }
      void show2(vector<int> v)
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
};
void show(vector<vector<int>> v)
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
      vector<vector<int>> score = {{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}};
      int k = 2;
      Solution obj;
      show(obj.sortTheStudents(score, k));

      return 0;
}