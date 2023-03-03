#include <iostream>
using namespace std;

void merge(int *left, int *right, int n)
{
    int i = 0, j = 0, k = 0;
    int arr[n];
    while (left + i < right && right + j < left + n)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    if (k < n)
    {
        if (left + i < right)
        {
            while (left + i < right)
            {
                arr[k] = left[i];
                i++;
                k++;
            }
        }
        else
        {
            while (right + j < left + n)
            {
                arr[k] = right[j];
                j++;
                k++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        left[i] = arr[i];
    }
}
void merge1(int *left, int *right, int n)
{
    int i = 0, j = 0;
    while (left + i != right + j)
    {
        if (left[i] < right[j])
        {
            i++;
        }
        else
        {
            int temp = left[i];
            left[i] = right[j];
            right[j] = temp;
            i++;
            j++;
        }
    }
}

void merge_sort(int arr[], int low, int high)
{
    if ((high - low + 1) == 1)
    {
        return;
    }
    int mid = (high + low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr + low, arr + mid + 1, (high - low + 1));
}

int main()
{
    int arr[] = {811, 113, 4, 12, 5, 6, 17, 14, 112, 15, 56};
    int n = 11;
    // merge1(arr + 0, arr + 3, n);
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}