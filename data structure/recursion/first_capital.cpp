#include <iostream>
#include <string>
using namespace std;

int i = 0;
void helper(string s)
{
    if (i == s.size())
    {
        return;
    }
    if (int(s[i]) > 59 && int(s[i]) < 91)
    {
        cout << s[i];
        return;
    }
    i = i + 1;
    helper(s);
}

void fun(string s)
{
    helper(s);
}

int main()
{
    string s;
    cout << "Enter: ";
    getline(cin, s);
    fun(s);
    return 0;
}