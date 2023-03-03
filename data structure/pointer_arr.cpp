#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int fun(int *arr)
{
      for (int i = 0; i < 5; i++)
      {
            cout << *(arr + i) << " ";
      }
      return 0;
}

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
int main()
{
      // int arr[5] = {1, 2, 3, 4, 5};
      // cout << arr << endl;
      // fun(arr + 1);
      vector<int> v = {1, 5, 3, 24};
      sort(v.begin(), v.end());
      show_1d(v);
      int a = 90;
      int b = 78;
      cout << endl
           << &a;
      int *p;
      p = new int(12);
      cout << endl
           << p;
      // int *p = &a;
      // cout << endl
      //      << p << " " << *p;
      // cout << endl
      //      << fun1(&p, &b);
      // cout << endl
      //      << p << " " << *p;

      return 0;
}