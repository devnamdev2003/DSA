#include <iostream>
using namespace std;
void fun(int a)
{
      a = a + 1;
      cout << a << endl;
}
void fun2(int &a)
{
      a += 1;
      cout << a << endl;
}
int main()
{
      char *c = "abcde";
      char **p = &c;

      cout << *c << endl;
      *p = "1234";
      cout << c << endl;
      cout << *p << endl;

      return 0;
}