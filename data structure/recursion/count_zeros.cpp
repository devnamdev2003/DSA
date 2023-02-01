#include <iostream>
using namespace std;

int countZ(int n, int Z)
{
      if (n == 0)
      {
            return Z;
      }
      if (n % 10 == 0)
      {
            return countZ(n / 10, Z + 1);
      }
      return countZ(n / 10, Z);
}
int count(int n)
{
      int zeroes = 0;
      return countZ(n, zeroes);
}
int main()
{

      cout << count(10000);

      return 0;
}