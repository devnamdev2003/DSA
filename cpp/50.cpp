#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        if (n < 0)
        {
            for (int i = n; i < 0; i++)
            {
                ans = ans * x;
            }
            ans = 1 / ans;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ans = ans * x;
            }
        }
        return ans;
    }
};
int main()
{
    Solution o;
    cout << o.myPow(2, 10);

    return 0;
}