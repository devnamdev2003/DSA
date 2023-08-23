#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      vector<string> function(int n)
      {
            vector<string> ans;
            for (int i = 1; i <= n; i++)
            {
                  if (i % 3 == 0 && i % 5 == 0)
                  {
                        ans.push_back("FizzBuzz");
                  }
                  else if (i % 3 == 0)
                  {
                        ans.push_back("Fizz");
                  }
                  else if (i % 5 == 0)
                  {
                        ans.push_back("Buzz");
                  }
                  else
                  {

                        ans.push_back(to_string(i));
                  }
            }

            return ans;
      }
};

void show(vector<string> v)
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
      Solution obj;
      show(obj.function(3));

      return 0;
}