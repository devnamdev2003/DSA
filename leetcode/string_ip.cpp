#include <iostream>
#include <vector>
#include <string>
using namespace std;

string function(string address)
{
      string ans;
      for (int i = 0; i < address.length(); i++)
      {
            if ('.' == address[i])
            {
                  ans = ans + "[" + address[i] + "]";
            }
            else
            {
                  ans = ans + address[i];
            }
      }

      return ans;
}

int main()
{
      string name = "1.1.1.1";
      cout << function(name);
      return 0;
}