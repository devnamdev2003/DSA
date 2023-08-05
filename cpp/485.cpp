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
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                v.push_back(count);
                count = 0;
            }
        }
        v.push_back(count);
        show_1d(v);
        int max = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if (max < v[i])
            {
                max = v[i];
            }
        }
        return max;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0};
    cout << obj.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}