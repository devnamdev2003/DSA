#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> v = {1, 2, 3, 1, 1, 2, 4, 5};
    vector<int> v2(v.size(), 0);
    for (int i = 0; i < v.size(); i++)
    {
        v2[v[i]] += 1;
    }
    show_1d(v2);

    return 0;
}