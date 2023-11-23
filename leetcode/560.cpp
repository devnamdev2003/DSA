#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> sumFreq;
        int count = 0;
        int cumulativeSum = 0;
        sumFreq[0] = 1;
        for (int num : nums)
        {
            cumulativeSum += num;
            if (sumFreq.find(cumulativeSum - k) != sumFreq.end())
            {
                count += sumFreq[cumulativeSum - k];
            }
            sumFreq[cumulativeSum]++;
        }

        return count;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << obj.subarraySum(nums, k) << endl;
    return 0;
}