#include <iostream>
using namespace std;
bool function(int c)
{
      long long a = 0;
      long long b = 0;
      if (c == 1 || c == 0)
      {
            return true;
      }
      for (a = 0; a < c; a++)
      {
            for (b = c/2; b >=0; b--)
            {
                  if ((a * a) + (b * b) == c)
                  {
                        return true;
                  }
                  else if ((a * a) + (b * b) > c)
                  {
                        break;
                  }
            }
      }
      /* long long int lo=0,hi=sqrt(c);
        while(lo<=hi){
            long long int cur=(lo*lo)+(hi*hi);
            if(cur==c)return true;
            if(cur>c){
                hi--;
            }
            else{
                lo++;
            }
        }
        return false; */

      return false;
}
int main()
{
      cout << function(2);
      return 0;
}
// 2147482647
