#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (matrix[i][j] == 0)
        //         {
        //             for (int k = 0; k < n; k++)
        //             {
        //                 if (matrix[i][k] == 1)
        //                 {
        //                     matrix[i][k] = -1;
        //                 }
        //             }
        //             for (int k = 0; k < m; k++)
        //             {
        //                 if (matrix[k][j] == 1)
        //                 {
        //                     matrix[k][j] = -1;
        //                 }
        //             }
        //         }
        //     }
        // }
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (matrix[i][j] == -1)
        //         {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
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
int main()
{
    Solution obj;
    vector<vector<int>> v{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    obj.setZeroes(v);
    show_2d(v);
    return 0;
}