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
    int maxScore(vector<int> nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        show_1d(nums);
        vector<int> v;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans + nums[i];
            v.push_back(ans);
        }
        show_1d(v);
        return *max_element(v.begin(), v.end());
    }
};
int main()
{
    Solution o;
    cout << o.maxScore({-687767, -860350, 950296, 52109, 510127, 545329, -291223, -966728, 852403, 828596, 456730, -483632, -529386, 356766, 147293, 572374, 243605, 931468, 641668, 494446});
    return 0;
}
