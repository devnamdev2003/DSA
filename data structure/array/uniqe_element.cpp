#include <iostream>
using namespace std;
int fun(int arr[], int s)
{
    int ans = 0;
    for (int i = 0; i < s; i++)
    {
        ans = arr[i] ^ ans;
    }
    return ans;
}
int main()
{
    int arr[7] = {1, 4, 2, 2, 4, 1, 5};
    cout << fun(arr,7);

    return 0;
}