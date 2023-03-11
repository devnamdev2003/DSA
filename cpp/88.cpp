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
    void merge(vector<int> nums1, int m, vector<int> nums2, int n)
    {
        int i = 0, j = 0, k = 0;
        vector<int> v;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
                k++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
                k++;
            }
        }
        if (i < m)
        {
            while (i < m)
            {
                v.push_back(nums1[i]);
                i++;
            }
        }
        else
        {
            while (j < n)
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        nums1.clear();
        nums1 = v;
        show_1d(nums1);
    }
};

int main()
{
    Solution obj;
    obj.merge({1, 2, 3}, 3, {2, 5, 6}, 3);

    return 0;
}