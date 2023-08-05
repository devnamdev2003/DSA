#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show_2d(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
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

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        int show;
        while (i < n - i || j < m - j)
        {
            int a = i;
            for (; a < n - i; a++)
            {
                ans.push_back(matrix[i][a]);
                show = (matrix[i][a]);
                cout << show << " ";
            }
            cout << endl;
            int b = j + 1;
            for (; b < m - j; b++)
            {
                ans.push_back(matrix[b][a - 1]);
                show = (matrix[b][a - 1]);
                cout << show << " ";
            }
            cout << endl;
            int c = a - 2;
            for (; c >= i; c--)
            {
                ans.push_back(matrix[b - 1][c]);
                show = (matrix[b - 1][c]);
                cout << show << " ";
            }
            cout << endl;
            int d = c + 1;
            for (; d > j; d--)
            {
                ans.push_back(matrix[d][i]);
                show = (matrix[d][i]);
                cout << show << " ";
            }
            cout << endl;
            show_1d(ans);
            i++;
            j++;
        }

        return {};
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix = {{0, 1, 2, 3},
                                  {10, 21, 32, 43},
                                  {10, 21, 32, 43},
                                  {10, 21, 32, 43},
                                  {10, 21, 32, 43}};
    vector<int> ans = s.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}