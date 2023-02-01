#include <iostream>
#include <string>
using namespace std;

bool helper(string str, int s, int e)
{
      if (s > e)
      {
            return 1;
      }
      if (str[s] == str[e])
      {
            return helper(str, s + 1, e - 1);
      }

      return 0;
}
bool pal(int n)
{
      string str = to_string(n);
      return helper(str, 0, str.length() - 1);
}

int main()
{
      cout << pal(1721);

      return 0;
}