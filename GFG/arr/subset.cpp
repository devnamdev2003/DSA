#include <iostream>
#include <vector>
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
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> v2;
        return helper(nums, v2);
    }
    int helper(vector<int> v1, vector<int> v2, int max = 0)
    {

        if (v1.empty())
        {
            int sum = 0;
            for (int i = 0; i < v2.size(); i++)
            {
                sum = sum + v2[i];
            }
            show_1d(v2);
            if (max <= sum)
            {
                max = sum;
            }
            return max;
        }
        v2.push_back(v1[v1.size() - 1]);
        v1.pop_back();
        max = helper(v1, v2, max);
        v2.pop_back();
        max = helper(v1, v2, max);
        return max;
    }
};

int main()
{
    vector<int> v1 = {-2, 1,};
    Solution obj;
    cout << obj.maxSubArray(v1);
    return 0;
}