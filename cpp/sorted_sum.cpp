#include <iostream>
#include <vector>
using namespace std;
vector<int> function(vector<int> numbers, int target)
{

      vector<int> ans;
      for (int i = 0; i < numbers.size(); i++)
      {
            for (int j = i; j < numbers.size(); j++)
            {
                  if (numbers[i] + numbers[j] == target)
                  {
                        ans.push_back(i + 1);
                        ans.push_back(j + 1);
                        return ans;
                  }
            }
      }
      return ans;
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
      vector<int> v1 = {2, 3, 4};
      int target = 6;
      vector<int> v2 = function(v1, target);
      show(v2);
      return 0;
}