#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "devnamdev";
    string news = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        news = news + s[i];
    }
    cout<<news;
    return 0;
}