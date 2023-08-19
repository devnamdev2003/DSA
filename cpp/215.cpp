#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < nums.size(); i++)
        {
            min_heap.push(nums[i]);
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};
int main()
{
    Solution onj;
    vector<int> v={3,2,1,5,6,4};
    cout<<onj.findKthLargest(v,2)<<endl;

    return 0;
}