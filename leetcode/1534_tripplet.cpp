#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      int countGoodTriplets(vector<int> &arr, int a, int b, int c)
      {
            int ans = 0;
            for (int i = 0; i < arr.size(); i++)
            {

                  for (int j = i + 1; j < arr.size(); j++)
                  {
                        for (int k = j + 1; k < arr.size(); k++)
                        {
                              int l = arr[i] - arr[j];
                              int m = arr[j] - arr[k];
                              int n = arr[k] - arr[i];
                              if (l <= a && m <= b && n <= c)
                              {
                                    ans++;
                              }
                        }
                  }
            }
            return ans;
      }
};

int main()
{
      vector<int> arr = {3, 0, 1, 1, 9, 7};
      int a = 7, b = 2, c = 3;
      Solution obj;
      cout << obj.countGoodTriplets(arr, a, b, c);

      return 0;
}