#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> orders(n);
    for (int i = 0; i < n; i++)
    {
        cin >> orders[i];
    }
    int k;
    cin >> k;

    int count = 0;

    while (orders[k - 1] != 0)
    {
        auto it = max_element(orders.begin(), orders.end());
        int index = it - orders.begin();
        orders[index] = 0;
        for (int i = index - 1; i >= 0; i--)
        {
            if (orders[i] == 0)
            {
                continue;
            }
            else
            {
                orders[i] = orders[i] + 1;
            }
        }
        count++;
    }
    cout << count;

    return 0;
}
