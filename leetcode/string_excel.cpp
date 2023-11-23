#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> function(string s)
{
      vector<string> ans;
      string s1 = "";
      char c1 = s[0];
      char n1 = s[1];
      char c2 = s[3];
      char n2 = s[4];
      int nc1 = c1 - 65;
      int nn1 = n1 - 49;
      int nc2 = c2 - 65;
      int nn2 = n2 - 49;
      int diff = (nc2 - nc1) + 1;
      int diff2 = (nn2 - nn1) + 1;
      for (int i = 0; i < diff; i++)
      {
            for (int j = 0; j < diff2; j++)
            {
                  char caracter = c1 + i;
                  char charnum = n1 + j;
                  s1 = caracter;
                  s1 = s1 + charnum;
                  ans.push_back(s1);
            }
      }
      return ans;
}
void show(vector<string> v)
{
      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      cout << endl;
}
int main()
{
      string s = "K1:L2";
      vector<string> v = function(s);
      show(v);
      return 0;
}