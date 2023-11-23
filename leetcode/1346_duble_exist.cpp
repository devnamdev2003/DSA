#include <iostream>
#include <vector>
using namespace std;

bool function(vector<int> arr)
{
      for (int l = 0; l < arr.size(); l++)
      {
            if (arr[l] % 2 == 0)
            {
                  for (int m = 0; m < arr.size(); m++)
                  {
                        if ((arr[l] / 2) == arr[m] && l != m)
                        {
                              return true;
                        }
                  }
            }
      }

      return false;
}
int main()
{
      vector<int> v = {-2, 10, -19, 4, 6, -8};
      cout << function(v);

      return 0;
}