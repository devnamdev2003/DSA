#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices)
    {

        if (prices.size() == 1)
            return 0;

        int low = 0;
        int maxprofit = 0;

        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < prices[low])
            {
                low = i;
                continue;
            }
            maxprofit = max(maxprofit, prices[i] - prices[low]);
        }
        return maxprofit;
    }
    int maxProfit2(vector<int> prices)
    {
        int sum=0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i + 1])
            {
                sum += prices[i + 1] - prices[i];
            }
        }
        return sum;
    }
};
int main()
{
    Solution o;
    cout << o.maxProfit2({1,2,3,4,5});

    return 0;
}