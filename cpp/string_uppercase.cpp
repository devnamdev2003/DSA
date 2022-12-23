#include <iostream>
#include <vector>
#include <string>
using namespace std;

string function(string s)
{
      for (int i = 0; i < s.length(); i++)
      {
            if (s[i] + 0 < 91 && s[i] + 0 > 64)
            {
                  char c;
                  c = s[i] + 32;
                  s[i] = c;
            }
      }
      return s;
}

int main()
{
      string s = "aAzZ%";
      cout << function(s);
      cout << s[0] + 0 << s[0] << " ";
      cout << s[1] + 0 << s[1] << " ";
      cout << s[2] + 0 << s[2] << " ";
      cout << s[3] + 0 << s[3] << " ";

      return 0;
}