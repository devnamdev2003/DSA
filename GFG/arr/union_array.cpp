#include <set>
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
    // int doUnion(int a[], int n, int b[], int m)
    // {
    //     int ap = 0;
    //     int bp = 0;
    //     vector<int> vec;
    //     while (ap < n && bp < m)
    //     {
    //         if (a[ap] < b[bp])
    //         {
    //             if (vec.size() == 0 || vec.back() != a[ap])
    //             {
    //                 vec.push_back(a[ap]);
    //             }
    //             ap++;
    //         }
    //         else
    //         {
    //             if (vec.size() == 0 || vec.back() != b[bp])
    //             {
    //                 vec.push_back(b[bp]);
    //             }
    //             bp++;
    //         }
    //     }
    //     while (ap < n)
    //     {
    //         if (vec.size() == 0 || vec.back()!= a[ap])
    //         {
    //             vec.push_back(a[ap]);
    //         }
    //         ap++;
    //     }
    //     while(bp<m){
    //         if (vec.size() == 0 || vec.back()!= b[bp])
    //         {
    //             vec.push_back(b[bp]);
    //         }
    //         bp++;
    //     }
    //     show_1d(vec);
    //     return vec.size();
    // }
    int doUnion(int a[], int n, int b[], int m)
    {
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(a[i]);
        }
        for(int i = 0; i < m; i++){
            s.insert(b[i]);
        }
        return s.size();
    }
};
int main()
{
    Solution obj;
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[3] = {1, 2, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    cout << obj.doUnion(arr1, n, arr2, m);
    return 0;
}