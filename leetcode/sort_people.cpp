#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> function(vector<string> names, vector<int> heights)

{
      vector<string> ans;
      int max = 0;
      int index = 0;
      for (int j = 0; j < heights.size(); j++)
      {
            max = 0;
            for (int i = 0; i < heights.size(); i++)
            {
                  if (heights[i] > max)
                  {
                        max = heights[i];
                        index = i;
                  }
            }
            auto it = heights.begin();
            ans.push_back(names[index]);
            heights.erase(heights.begin() + index);
            heights.insert(it + index, 0);
      }
      return ans;
}

void show(vector<string> v)
{

      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      cout << endl;
}
int main()
{
      vector<string> names = {"Mary", "John", "Emma"};
      vector<int> heights = {180, 165, 170};
      vector<string> v2 = function(names, heights);
      show(v2);
      return 0;
}