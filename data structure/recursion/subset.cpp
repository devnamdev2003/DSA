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
    cout << endl;
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
int main()
{
    subset_string("abcdef");
    // sum_subset_vector({1, 2, 3});
    // subset_vector({1, 2, 3});
    cout << count << endl;
    return 0;
}