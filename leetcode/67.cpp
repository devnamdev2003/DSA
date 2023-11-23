#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long btod(string str)
    {
        long ans = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '1')
            {
                ans = ans + (pow(2, (str.length() - 1 - i)));
            }
        }
        return ans;
    }
    string dtob(long n)
    {
        string nstr = "";
        if (n == 0)
            return "0";
        while (n > 0)
        {
            nstr = to_string(n % 2) + nstr;
            n = n / 2;
        }
        return nstr;
    }
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string str = "";
        int carry = 0;
        for (int i = 0; i < a.length() && i < b.length(); i++)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                if (carry == 1)
                {
                    str = "1" + str;
                    carry = 1;
                }
                else
                {
                    str = "0" + str;
                    carry = 1;
                }
            }
            else if (a[i] == '0' && b[i] == '0')
            {
                if (carry == 1)
                {
                    str = "1" + str;
                    carry = 0;
                }
                else
                {
                    str = "0" + str;
                    carry = 0;
                }
            }
            else
            {
                if (carry == 1)
                {
                    str = "0" + str;
                    carry = 1;
                }
                else
                {
                    str = "1" + str;
                    carry = 0;
                }
            }
        }
        int n = min(a.length(), b.length());
        if (n == a.length())
        {
            for (int i = n; i < b.length(); i++)
            {
                if (carry == 1)
                {
                    if (b[i] == '1')
                    {
                        str = '0' + str;
                        carry = 1;
                    }
                    else
                    {
                        str = '1' + str;
                        carry = 0;
                    }
                }
                else
                {
                    str = b[i] + str;
                }
            }
        }
        else
        {
            for (int i = n; i < a.length(); i++)
            {
                if (carry == 1)
                {
                    if (a[i] == '1')
                    {
                        str = '0' + str;
                        carry = 1;
                    }
                    else
                    {
                        str = '1' + str;
                        carry = 0;
                    }
                }
                else
                {
                    str = a[i] + str;
                }
            }
        }
        if (carry == 1)
        {
            str = '1' + str;
        }
        return str;
    }
};
int main()
{
    Solution obj;
    cout << obj.addBinary("0", "0");

    return 0;
}