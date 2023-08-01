#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int max = INT32_MIN;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int sum = 0;

//             for (int j = i; j < nums.size(); j++)
//             {
//                 sum = sum + nums[j];
//                 if (max < sum)
//                 {
//                     max = sum;
//                 }
//             }
//         }
//         return max;
//     }
// };

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxSum = nums[0]; // Initialize the maximum sum
        int currentSum = nums[0]; // Initialize the current sum
    // {-2, 1, -3, 4, -1, 2, 1, -5, 4};

        for (int i = 1; i < nums.size(); i++) {
            // Calculate the current sum by either starting a new subarray or extending the existing one
            currentSum = std::max(nums[i], currentSum + nums[i]);

            // Update the maximum sum if the current sum is greater
            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;
    }
};
int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution obj;
    cout << obj.maxSubArray(v);

    return 0;
}