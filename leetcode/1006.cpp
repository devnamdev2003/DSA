#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int clumsy(int n)
    {
        int co = n;
        int ans = 0;
        if (n < 4)
        {
            if (n % 4 == 1)
            {
                return n;
            }
            else if (n % 4 == 2)
            {
                return n * (n - 1);
            }
            else if (n % 4 == 3)
            {
                return n * (n - 1) / (n - 2);
            }
        }
        if ((n / 4) > 0)
        {
            ans = n * (n - 1) / (n - 2) + (n - 3);
            n = n - 4;
        }
        for (int i = 1; i < co / 4; i++)
        {
            ans = ans - n * (n - 1) / (n - 2) + (n - 3);
            n = n - 4;
        }
        if (n % 4 == 1)
        {
            ans = ans - n;
        }
        else if (n % 4 == 2)
        {
            ans = ans - n * (n - 1);
        }
        else if (n % 4 == 3)
        {
            ans = ans - n * (n - 1) / (n - 2);
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    cout << obj.clumsy(1);

    return 0;
}