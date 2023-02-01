#include <iostream>
using namespace std;

void print_revers(int n)
{
      cout << n % 10;
      if (n / 10 == 0)
      {
            return;
      }
      print_revers(n / 10);

      return;
}
int main()
{
      print_revers(1234515);

      return 0;
}