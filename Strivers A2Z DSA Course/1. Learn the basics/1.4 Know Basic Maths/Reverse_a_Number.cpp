#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n != 0)
    {
        // Check for overflow
        if (ans > INT32_MAX / 10 || (ans == INT32_MAX / 10 && n % 10 > INT32_MAX % 10))
        {
            cout << "Overflow occurred!";
            return 1;
        }
        ans = ans * 10 + n % 10;
        n = n / 10;
    }
    cout << ans;
    return 0;
}
