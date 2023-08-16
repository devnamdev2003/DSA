#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int i = 5;
        int ans = 0;
        while (n / i > 0)
        {
            ans = ans + (n / i);
            i = i * 5;
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    // cout << obj.trailingZeroes(4)<<endl;
    // cout << obj.trailingZeroes(15)<<endl;
    cout << obj.trailingZeroes(200)<<endl;

    return 0;
}