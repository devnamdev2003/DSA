#include <iostream>
#include <vector>
#include <string>
using namespace std;

string function(vector<int> indices, string s)
{
      string ans = "";
      for (int i = 0; i < indices.size(); i++)
      {
            for (int j = 0; j < indices.size(); j++)
            {
                  if (i == indices[j])
                  {
                        ans = ans + s[j];
                  }
            }
      }

      return ans;
}

int main()
{
      vector<int> v1 = {4, 5, 6, 7, 0, 2, 1, 3};
      string name = "codeleet";
      cout << function(v1, name);

      return 0;
}