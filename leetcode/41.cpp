#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> nums)
    {
        set<int> s(nums.begin(), nums.end());
        vector<int> nums2(s.begin(), s.end());
        sort(nums2.begin(), nums2.end());
        int point = nums2.size() - 1;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums2[i] > 0)
            {
                point = i;
                break;
            }
        }
        int k = 1;
        for (int j = point; j < nums2.size(); j++)
        {
            if (nums2[j] == k)
            {
                k++;
            }
            else
            {
                return k;
            }
        }
        return k;
    }
};
int main()
{
    Solution o;
    cout << o.firstMissingPositive({1, 2, 0});

    return 0;
}