#include <iostream>
#include <vector>
using namespace std;
vector<int> function(vector<int> numbers, int target)
{

      vector<int> ans;
      int i = 0;
      int j = numbers.size() - 1;
      while (i < j)
      {
            int sum = numbers[i] + numbers[j];

            if (target == sum)
            {
                  ans.push_back(i + 1);
                  ans.push_back(j + 1);
                  break;
            }
            if (sum > target)
            {
                  j--;
            }
            if (sum < target)
            {
                  i++;
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