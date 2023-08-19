#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    string reorganizeString(string s)
    {
        map<char, string> hmap;
        for (int i = 0; i < s.size(); i++)
        {
            if (hmap[s[i]].size() == 0)
            {
                hmap[s[i]] = s[i];
                continue;
            }
            hmap[s[i]] += s[i];
        }
        string ans = "";
        while (ans.size() != s.size())
        {
            for (auto v : hmap)
            {
                if (hmap[v.first].size() > 0)
                {
                    ans = ans + hmap[v.first][0];
                    hmap[v.first].pop_back();
                }
            }
        }
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (ans[i] == ans[i + 1])
            {
                return "";
            }
        }
        return ans;
    }
};
int main()
{
    Solution o;
    cout<<o.reorganizeString("aab");

    return 0;
}