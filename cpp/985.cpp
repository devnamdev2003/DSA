#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      vector<int> sumEvenAfterQueries(vector<int> nums, vector<vector<int>> queries)
      {
            vector<int> ans;
            int sum = 0;
            int i = 0;
            for (i = 0; i < nums.size(); i++)
            {
                  if (nums[i] % 2 == 0)
                  {
                        sum += nums[i];
                  }
            }
            i = 0;
            for (i = 0; i < queries.size(); i++)
            {
                  int temp = nums[queries[i][1]];
                  nums[queries[i][1]] += queries[i][0];
                  if (nums[queries[i][1]] % 2 == 0)
                  {
                        if (temp % 2 == 0)
                        {
                              sum -= temp;
                        }
                        sum += nums[queries[i][1]];
                  }
                  else
                  {
                        if (temp % 2 == 0)
                        {
                              sum -= temp;
                        }
                  }

                  ans.push_back(sum);
            }
            return ans;
      }
};

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
void show_2d(vector<vector<int>> v)
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
      Solution obj;
      show_1d(obj.sumEvenAfterQueries({1, 2, 3, 4}, {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}}));

      return 0;
}