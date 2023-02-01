#include <iostream>
using namespace std;

void fun(int n)
{
      if (n == 0)
      {
            return;
      }
      for (int i = 1; i <= n; i++)
      {
            cout << "*";
      }
      cout << endl;
      fun(n - 1);
      return;
}
void fun2(int n)
{
      if (n == 0)
      {
            return;
      }
      fun2(n - 1);
      for (int i = 1; i <= n; i++)
      {
            cout << "*";
      }
      cout << endl;
      return;
}

int main()
{
      int n;
      fun2(5);

      return 0;
}