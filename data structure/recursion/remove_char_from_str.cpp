#include <iostream>
using namespace std;
string s2;
string fun(string s, int n, char c)
{
    if (n == s.size())
    {
        return s2;
    }
    if (s[n] != c)
    {
        s2 = s2 + s[n];
    }
    return fun(s, n + 1, c);
}

int main()
{
    cout << fun("devnamdev", 0, 'e');
    return 0;
}