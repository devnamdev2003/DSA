#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> arr)
{
      int ans = -1;
      int len = arr.size();
      int mid = len / 2;
      int low = 1;
      int high = len - 1;
      for (int i = 0; i < len; i++)
      {
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                  return mid;
            }
            else if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                  low = mid + 1;
                  high = high;
                  mid = ((high - low) / 2) + low;
            }
            else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
            {
                  low = low;
                  high = mid;
                  mid = ((high - low) / 2) + low;
            }
      }

      return ans;
}

int main()
{
      vector<int> v1 = {0, 2, 1, 0};
      cout << function(v1);

      return 0;
}