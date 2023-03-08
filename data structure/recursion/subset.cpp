#include <iostream>
#include <string>
#include <vector>

// time complexity = O((2^n+1)-1)
// space complexity = O(n)
using namespace std;
int count = 0;
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
    // cout << endl;
}
void subset_string(string s, string s_new = "")
{
    count++;
    if (s.size() == 0)
    {
        if (s_new.size() > 0)
        {
            cout << s_new;
            cout << endl;
        }
        return;
    }
    subset_string(s.substr(1), s_new + s[0]);
    subset_string(s.substr(1), s_new);
}
void sum_subset_vector(vector<int> arr, int sum = 0)
{
    if (arr.size() == 0)
    {
        cout << sum;
        cout << endl;
        return;
    }
    int add = arr[0];
    arr.erase(arr.begin());
    sum_subset_vector(arr, sum + add);
    sum_subset_vector(arr, sum);
}
void subset_vector(vector<int> arr, vector<int> sum = {})
{
    count++;
    if (arr.size() == 0)
    {
        if (!sum.empty())
        {
            show_1d(sum);
        }
        return;
    }
    int add = arr[0];
    arr.erase(arr.begin());
    vector<int> sum0 = sum;
    sum0.push_back(add);
    subset_vector(arr, sum0);
    subset_vector(arr, sum);
}
void show_2d(vector<vector<int>> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> nums, vector<int> sum = {})
    {
        vector<vector<int>> add1;
        if (nums.size() == 0)
        {
            add1.push_back(sum);
            return add1;
        }
        int add = nums[0];
        nums.erase(nums.begin());
        vector<int> sum0 = sum;
        sum0.push_back(add);
        vector<vector<int>> v1 = subsets(nums, sum0);
        vector<vector<int>> v2 = subsets(nums, sum);
        add1.insert(add1.end(), v1.begin(), v1.end());
        add1.insert(add1.end(), v2.begin(), v2.end());
        return add1;
    }
};

int main()
{
    // subset_string("abcdef");
    // sum_subset_vector({1, 2, 3});
    Solution obj;
    vector<vector<int>> v = obj.subsets({1, 2, 3});
    // vector<vector<int>> v;
    // vector<vector<int>> v3 = {{1, 2, 3}, {4, 5, 6}};
    // vector<int> v1 = {1,9,9};
    // v.push_back(v1);
    // show_2d(v);
    // vector<int> v2 = v1;
    // v2.push_back(0);
    // show_1d(v2);
    // vector<vector<int>> v1;
    // v1.insert(v1.end(), v.begin(), v.end());
    // v1.insert(v1.end(), v3.begin(), v3.end());

    show_2d(v);
    // cout << count << endl;
    return 0;
}