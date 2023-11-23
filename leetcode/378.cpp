#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> max_heap;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                max_heap.push(matrix[i][j]);
                if (max_heap.size() > k)
                {
                    max_heap.pop();
                }
            }
        }
        return max_heap.top();
    }
};
int main()
{
    Solution o;
    vector<vector<int>> v = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout<<o.kthSmallest(v,8);

    return 0;
}