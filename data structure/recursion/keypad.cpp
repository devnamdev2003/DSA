#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
void show_1d(vector<string> v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1)
        {
            cout << v[i] << ",";
        }
        else
        {
            cout << v[i];
        }
    }
    cout << "]";
    cout << endl;
}
void print_key(int n)
{
    char c;
    for (int i = 'a' + (3 * (n - 1)); i < ('a' + (3 * (n - 1))) + 3; i++)
    {
        if (i > 122)
        {
            break;
        }
        c = i;
        cout << c;
        cout << endl;
    }
}
void keypad_print(string s, string s_new = "")
{
    if (s.size() == 0)
    {
        cout << s_new;
        cout << endl;
        return;
    }
    int digit = s[0] - '0';
    for (int i = (digit - 1) * 3; i < digit * 3; i++)
    {
        char c = 'a' + i;
        if ('a' + i > 'z')
        {
            break;
        }
        else
        {
            keypad_print(s.substr(1), s_new + c);
        }
    }
}
vector<string> keypad_print_vector(string s, string s_new = "")
{
    vector<string> ans;
    if (s.size() == 0)
    {
        ans.push_back(s_new);
        return ans;
    }
    int digit = s[0] - '0';
    for (int i = (digit - 1) * 3; i < digit * 3; i++)
    {
        char c = 'a' + i;
        if ('a' + i > 'z')
        {
            break;
        }
        else
        {
            vector<string> v2 = keypad_print_vector(s.substr(1), s_new + c);
            ans.insert(ans.end(), v2.begin(), v2.end());
        }
    }
    return ans;
}

int main()
{
    show_1d(keypad_print_vector("9"));
    return 0;
}