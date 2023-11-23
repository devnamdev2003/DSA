#include <iostream>
using namespace std;

bool function(int num)
{
      int count = 0;
      for (long long i = 1; i <= num; i++)
      {
            count++;
            if (i * i == num)
            {
                  cout << count <<" "<<i*i<< endl;

                  return true;
            }
            else if (i * i > num)
            {
                  cout << count <<" "<<i*i<< endl;

                  return false;
            }
      }
      return false;
}
int main()
{
      int n;
      cin >> n;
      cout << function(n);
      return 0;
}