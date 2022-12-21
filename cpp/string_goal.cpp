#include <iostream>
#include <string>
using namespace std;
string function(string command)
{
      string ans = "";
      for (int i = 0; i < command.length(); i++)
      {
            if ('(' == command[i])
            {
                  if (')' == command[i + 1])
                  {
                        ans = ans + 'o';
                        i = i + 1;
                  }
                  else if('a'==command[i+1])
                  {
                        ans = ans + "al";
                        i = i + 3;
                  }
            }
            else
            {
                  ans = ans + 'G';
            }
      }

      return ans;
}
int main()
{
      string command = "(al)G(al)()()G";
      cout << function(command);
      return 0;
}
