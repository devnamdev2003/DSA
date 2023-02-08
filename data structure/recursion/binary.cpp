#include <iostream>
#include <vector>
using namespace std;

int bin(vector<int> arr, int target)
{
      int ans;
      int low = 0;
      int mid = arr.size() / 2;
      int high = arr.size() - 1;

      for (int i = 0; i < arr.size(); i++)
      {
            if (arr[mid] == target)
            {
                  return mid;
            }
            else if (arr[mid] < target)
            {
                  low = mid + 1;
                  mid = low + (high - low) / 2;
            }
            else
            {
                  high = mid - 1;
                  mid = low + (high - low) / 2;
            }
      }

      return -1;
}

int bin_recursive(vector<int> arr, int target, int low, int high)
{

      if (low > high)
      {
            return -1;
      }
      int mid = low + (high - low) / 2;
      if (arr[mid] == target)
      {
            return mid;
      }
      if (arr[mid] > target)
      {
            return bin_recursive(arr, target, low, mid - 1);
      }
      return bin_recursive(arr, target, mid + 1, high);
}
int main()
{
      cout << bin_recursive({1, 3, 4, 5, 6, 7, 8, 9}, 18, 0, 7) << endl;
}
