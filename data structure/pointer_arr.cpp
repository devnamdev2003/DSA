#include <iostream>
using namespace std;
int fun(int *arr)
{
      for (int i = 0; i < 5; i++)
      {
            cout << *(arr + i) << " ";
      }
      return 0;
}
int main()
{

      int arr[5] = {1, 2, 3, 4, 5};
      cout << arr << endl;
      fun(arr + 1);
      return 0;
}