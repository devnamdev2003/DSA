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
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        cout<<k;
        reverse(nums.begin(), nums.end());
        show_1d(nums);
        reverse(nums.begin(), nums.begin() + k);
        show_1d(nums);
        reverse(nums.begin() + k, nums.end());
        show_1d(nums);

    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 4,5,10,10};
    s.rotate(nums, 1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;

}