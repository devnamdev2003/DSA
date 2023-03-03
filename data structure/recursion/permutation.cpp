#include <iostream>
#include <string>
using namespace std;
int count = 0;
void per(string s, string new_s = "")
{
    count++;
    if (s.size() == 0)
    {

        cout << new_s;
        cout << endl;
        return;
    }
    for (int i = 0; i <= new_s.size(); i++)
    {
        per(s.substr(1), (new_s.substr(0, i) + s[0] + new_s.substr(i, new_s.size())));
    }
}
int per_count(string s, string new_s = "", int c = 0)
{
    count++;
    if (s.size() == 0)
    {
        return 1;
    }
    c = 0;
    for (int i = 0; i <= new_s.size(); i++)
    {
        c = c + per_count(s.substr(1), (new_s.substr(0, i) + s[0] + new_s.substr(i, new_s.size())), c);
    }
    return c;
}

int main()
{
    per("012");
    // cout << per_count("0123456789");
    // cout<<endl;
    // cout << count;
    // string s = "dev";
    // for (int i = 0; i <= 3; i++)
    // {
    //     cout << s.substr(0, i) + 'a' + s.substr(i, s.size());
    //     cout << endl;
    // }
    return 0;
}