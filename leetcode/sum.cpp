#include <iostream>
#include <string>
using namespace std;

int function(int n)
{
      string s = to_string(n);
      int pro = 1;
      int sum = 0;

      for (int i = 0; i < s.length(); i++)
      {
            int num = s[i] - 48;
            pro = pro * num;
            sum = sum + num;
      }

      return pro - sum;
}
int main()
{
      int n = 4421;

      cout << function(n);

      return 0;
}