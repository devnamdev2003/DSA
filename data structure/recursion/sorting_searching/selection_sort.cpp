#include <iostream>
using namespace std;

int count = 0;
int count2 = 0;
void sort_itration(int arr[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
            count2++;
        }
        if (arr[i] > arr[min])
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
void sort_recursion(int arr[], int n, int s, int i, int min)
{
    if (s == n - 1)
    {
        return;
    }
    if (i < n)
    {
        if (arr[min] > arr[i])
        {
            min = i;
        }
        sort_recursion(arr, n, s, i + 1, min);
    }
    else
    {
        int temp = arr[s];
        arr[s] = arr[min];
        arr[min] = temp;
        sort_recursion(arr, n, s + 1, s + 2, s + 1);
    }
}

int main()
{
    int arr[] = {10, 22, 13, 11};
    int n = sizeof(arr) / sizeof(int);
    // sort_itration(arr, n);
    sort_recursion(arr, n, 0, 1, 0);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // cout << endl;
    // cout << count2 << " " << count;
    return 0;
}