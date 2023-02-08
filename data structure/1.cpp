#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
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
      vector<int> vowelStrings(vector<string> words, vector<vector<int>> queries)
      {
            vector<int> ans;
            for (int i = 0; i < queries.size(); i++)
            {
                  int count = 0;
                  for (int j = queries[i][0]; j <= queries[i][1]; j++)
                  {
                        if ((words[j][0] == 'a' || words[j][0] == 'e' || words[j][0] == 'i' || words[j][0] == 'o' || words[j][0] == 'u') && (words[j][words[j].length() - 1] == 'a' || words[j][words[j].length() - 1] == 'e' || words[j][words[j].length() - 1] == 'i' || words[j][words[j].length() - 1] == 'o' || words[j][words[j].length() - 1] == 'u'))
                        {
                              count++;
                        }
                  }
                  ans.push_back(count);
            }
            return ans;
      }
};

int main()
{
      Solution obj;
      show_1d(obj.vowelStrings({"aba", "bcb", "ece", "aa", "e"}, {{0, 2}, {1, 4}, {1, 1}}));

      return 0;
}