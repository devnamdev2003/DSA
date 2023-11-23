#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> &arr1, vector<int> &arr2, int d)
{
      int ans = 0;
      for (int i = 0; i < arr1.size(); i++)
      {
      //       vector<int> arr1 = {1, 4, 2, 3};
      // vector<int> arr2 = {-4, -3, 6, 10, 20, 30};
            for (int j = 0; j < arr2.size(); j++)
            {
                  int dis = arr1[i] - arr2[j];
                  if (dis < 0)
                  {
                        dis = dis * (-1);
                  }
                  if (dis < d)
                  {
                        ans = ans + 1;
                        j = arr2.size();
                  }
            }
      }

      return arr1.size() - ans;
}

int main()
{
      vector<int> arr1 = {1, 4, 2, 3};
      vector<int> arr2 = {-4, -3, 6, 10, 20, 30};
      int d = 3;
      cout << function(arr1, arr2, d);
      return 0;
}