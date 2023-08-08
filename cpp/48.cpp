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
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};
// class Solution
// {
// public:
//     void rotate(vector<vector<int>> &matrix)
//     {
//         int n = matrix.size();

//         // Transpose the matrix
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }

//         // Reverse each row
//         for (int i = 0; i < n; i++)
//         {
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
//     }
// };
int main()
{

    Solution obj;
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    obj.rotate(matrix);
    show_2d(matrix);

    return 0;
}