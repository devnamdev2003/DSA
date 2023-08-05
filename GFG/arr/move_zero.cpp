#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                int temp = arr[i];
                arr[i] = 0;
                arr[k] = temp;
                k++;
            }
        }
    }
};
int main()
{
    Solution obj;
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.pushZerosToEnd(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;

    return 0;
}