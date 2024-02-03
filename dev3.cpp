#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {2, 4, 5, 4, 1, 2, 5};
    int N = 3;
    int sum = 0;
    int start;
    int end;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum = sum + arr[j];
            if (sum == N)
            {
                start = i;
                end = j;
                break;
            }
        }
    }
    for (int i = start; i <= end; i++)
    {
        cout << i << " ";
    }

    return 0;
}
