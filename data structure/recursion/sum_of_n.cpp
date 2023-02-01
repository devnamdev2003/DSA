#include <iostream>
using namespace std;

int sum(int n)
{
      int sum = 0;
      for (int i = 0; i < n + 1; i++)
      {
            sum = sum + i;
      }
      // return (n * (n + 1)) / 2;
      return sum;
}

int re_sum(int n)
{
      if (n == 1)
      {
            return n;
      }
      // cout<<n<<" "<<endl;
      return re_sum(n - 1) + n;
}
int main()
{
      // cout << sum(57) << endl;
      cout << re_sum(5);

      return 0;
}