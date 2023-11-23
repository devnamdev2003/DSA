#include <iostream>
#include <vector>
#include <string>
using namespace std;
int function(vector<vector<string>> items, string ruleKey, string ruleValue)
{
      int ans = 0;
      int i;
      if (ruleKey == "type")
      {
            for (i = 0; i < items.size(); i++)
            {
                  if (items[i][0] == ruleValue)
                  {
                        ans++;
                  }
            }
      }
      else if (ruleKey == "color")
      {
            for (i = 0; i < items.size(); i++)
            {
                  if (items[i][1] == ruleValue)
                  {
                        ans++;
                  }
            }
      }
      else
      {
            for (i = 0; i < items.size(); i++)
            {
                  if (items[i][2] == ruleValue)
                  {
                        ans++;
                  }
            }
      }

      return ans;
}

int main()
{
      vector<vector<string>> v1 = {{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}};
      string ruleKey = "color";
      string ruleValue = "silver";

      cout << function(v1, ruleKey, ruleValue);
      return 0;
}