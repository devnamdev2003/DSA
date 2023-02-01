#include <iostream>
using namespace std;
bool helper(int arr[], int index, int n)
{
      if (index == n - 1)
      {
            return 1;
      }
      if (arr[index] < arr[index + 1])
      {
            return helper(arr, index + 1, n);
      }
      return 0;
}
bool fun(int arr[], int n)
{
      int index = 0;
      return helper(arr, index, n);
}

int main()
{
      int arr[] = {1, 2, 13, 4, 5};
      int n = int(sizeof(arr) / sizeof(arr[0]));
      // cout << sizeof(arr) / sizeof(arr[0]);
      cout << fun(arr, n);

      return 0;
}