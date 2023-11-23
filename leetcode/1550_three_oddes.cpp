#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      bool function(vector<int> arr)
      {
            int count = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                  if (arr[i] % 2 != 0)
                  {
                        count++;
                        if (count == 3)
                        {
                              return true;
                        }
                  }
                  else
                  {
                        count = 0;
                  }
            }

            return false;
      }
};

int main()
{
      Solution obj;
      cout << obj.function({1, 2, 1, 1});

      return 0;
}