#include <iostream>
using namespace std;
int sum_of_digit(int n)
{
      if (n == 0)
      {
            return 0;
      }
      return sum_of_digit(n / 10) + (n % 10);
}
int mul_of_digit(int n)
{
      if (n == 0)
      {
            return 1;
      }
      return sum_of_digit(n / 10) * (n % 10);
}
int main()
{
      cout << sum_of_digit(1236);

      return 0;
}