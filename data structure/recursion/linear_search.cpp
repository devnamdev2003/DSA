#include <iostream>
#include <vector>
using namespace std;
int helper(int arr[], int index, int n, int target)
{
      if (index == n)
      {
            return -1;
      }
      if (target == arr[index])
      {
            return index;
      }
      return helper(arr, index + 1, n, target);
}
int fun(int arr[], int n, int target)
{
      int index = 0;
      return helper(arr, index, n, target);
}
vector<int> temp;

vector<int> fun2(vector<int> v2, int target, int n, int index)
{
      if (index == n - 1)
      {
            return temp;
      }
      if (v2[index] == target)
      {
            temp.push_back(index);
            return fun2(v2, target, n, index + 1);
      }
      return fun2(v2, target, n, index + 1);
}

void show(vector<int> v)
{
      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      if (v.size() == 0)
      {
            cout << -1;
      }
}
int main()
{
      // int arr[] = {1, 2, 13, 13, 13, 4, 5};
      // int target = 13;
      // int n = int(sizeof(arr) / sizeof(arr[0]));
      // cout << fun(arr, n, target);
      show(fun2({1, 2, 32, 13, 23, 4, 5, 6}, 3, 8, 0));
      return 0;
}