#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int z = INT32_MAX;
    vector<vector<int>> m = {{0, 2, 1, z},
                             {1, 0, 3, z},
                             {z, z, 0, z},
                             {3, 5, 4, 0}};
    for (int n = 0; n < m.size(); n++)
    {
        for (int i = 0; i < m.size(); i++)
        {
            if (i != n)
            {
                for (int j = 0; j < m.size(); j++)
                {
                    int c1 = m[i][j];
                    int c2 = m[i][n];
                    int c3 = m[n][j];
                    if (c2 != z && c3 != z)
                    {
                        int temp = m[i][n] + m[n][j];
                        if (temp < m[i][j])
                        {
                            m[i][j] = temp;
                        }
                    }
                }
            }
        }
    }
    for (auto v : m)
    {
        for (auto i : v)
        {
            if (i < 0)
            {
                cout << endl;
                cout << "negative cycle detected";
                return -1;
            }
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}