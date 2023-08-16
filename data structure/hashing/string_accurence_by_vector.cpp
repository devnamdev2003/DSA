#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void show_1d(vector<int> v)
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
int main()
{
    string str = "abcdeababcdzz";
    vector<int> v(26, 0);
    // * a=97
    for (int i = 0; i < str.size(); i++)
    {
        v[str[i] - 97] += 1;
    }
    show_1d(v);
    return 0;
}