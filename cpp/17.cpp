#include <iostream>
#include <vector>
using namespace std;
void show_1d(vector<string> v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1)
        {
            cout << v[i] << ",";
        }
        else
        {
            cout << v[i];
        }
    }
    cout << "]";
    cout << endl;
}
class Solution
{
public:
    vector<string> letterCombinations(string digits, string s_new = "")
    {

        vector<string> ans;
        if (digits.size() == 0)
        {
            ans.push_back(s_new);
            return ans;
        }
        int digit = digits[0] - '1';
        if (digit == 6)
        {
            for (int i = 0; i < 4; i++)
            {
                char c = 'p' + i;
                vector<string> v2 = letterCombinations(digits.substr(1), s_new + c);
                ans.insert(ans.end(), v2.begin(), v2.end());
            }
        }
        else if (digit == 7)
        {
            for (int i = 0; i < 3; i++)
            {
                char c = 't' + i;
                vector<string> v2 = letterCombinations(digits.substr(1), s_new + c);
                ans.insert(ans.end(), v2.begin(), v2.end());
            }
        }
        else if (digit == 8)
        {
            for (int i = 0; i < 4; i++)
            {
                char c = 'w' + i;
                vector<string> v2 = letterCombinations(digits.substr(1), s_new + c);
                ans.insert(ans.end(), v2.begin(), v2.end());
            }
        }
        else
        {
            for (int i = (digit - 1) * 3; i < digit * 3; i++)
            {
                char c = 'a' + i;
                if ('a' + i > 'z')
                {
                    break;
                }
                else
                {
                    vector<string> v2 = letterCombinations(digits.substr(1), s_new + c);
                    ans.insert(ans.end(), v2.begin(), v2.end());
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    show_1d(obj.letterCombinations("7"));

    return 0;
}