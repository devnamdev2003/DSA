#include <iostream>
#include <vector>
#include <array>
using namespace std;
int count = 0;
int count2 = 0;
void sort_itration(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            count2++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sort_recursion(int arr[], int s, int e)
{
    if (e < 1)
    {
        return;
    }
    if (s < e)
    {
        if (arr[s] > arr[s + 1])
        {
            int temp = arr[s];
            arr[s] = arr[s + 1];
            arr[s + 1] = temp;
        }
        count++;
        sort_recursion(arr, s + 1, e);
    }
    else
    {
        count++;
        sort_recursion(arr, 0, e - 1);
    }
}
int main()
{
    int arr[] = {15, 12, 3, 8};
    int n = sizeof(arr) / sizeof(int);
    sort_itration(arr, n);
    sort_recursion(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<count2<<" "<<count;
    return 0;
}