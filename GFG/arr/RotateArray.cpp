#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotateArr(int arr[], int d, int n)
    {
        d=d%n;
        reverse(arr,arr+d);
        reverse(arr+d,arr+n);
        reverse(arr,arr+n);

    }
};
int main()
{
    Solution s;
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    s.rotateArr(arr,2,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}