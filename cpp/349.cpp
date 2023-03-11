#include <iostream>
#include <vector>
#include <set>
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
    vector<int> intersection(vector<int> nums1, vector<int> nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> v;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
        }
        set<int> s(v.begin(), v.end());
        vector<int> v2(s.begin(), s.end());
        return v2;
    }
};
int main()
{
    Solution o;
    show_1d(o.intersection({4, 9, 5}, {9, 4, 9, 8, 4}));

    return 0;
}