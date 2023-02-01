#include <iostream>
using namespace std;

int fibbo(int n)
{
      if (n < 2)
      {
            return n;
      }

      return (fibbo(n - 1) + fibbo(n - 2));
}

int main()
{
      cout << fibbo(6);
}
