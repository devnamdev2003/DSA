#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> nums, vector<int> sum = {})
    {
        vector<vector<int>> add1;
        if (nums.size() == 0)
        {
            add1.push_back(sum);
            return add1;
        }
        int add = nums[0];
        nums.erase(nums.begin());
        vector<int> sum0 = sum;
        sum0.push_back(add);
        vector<vector<int>> v1 = subsets(nums, sum0);
        vector<vector<int>> v2 = subsets(nums, sum);
        add1.insert(add1.end(), v1.begin(), v1.end());
        add1.insert(add1.end(), v2.begin(), v2.end());
        return add1;
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
int main()
{
    Solution obj;
    vector<vector<int>> v = obj.subsets({1, 2, 3});
    show_2d(v);

    return 0;
}
