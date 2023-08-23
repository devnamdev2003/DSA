#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        string ans = "";
        map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(pq.size() > 1)
        {
            pair<int,char> p, q;
            p = pq.top();
            pq.pop();
            q = pq.top();
            pq.pop();
            ans += p.second;
            p.first--;
            ans += q.second;
            q.first--;
            if(p.first > 0)
                pq.push(p);
            if(q.first > 0)
                pq.push(q);
        }
        if(pq.size() == 1)
        {
            pair<int,char> p = pq.top();
            if(p.first == 1)
                ans += p.second;
            else
                return "";
        }
        return ans;
    }
};
// class Solution
// {
// public:
//     string reorganizeString(string s)
//     {
//         map<char, string> hmap;
//         for (int i = 0; i < s.size(); i++)
//         {

//             if (hmap[s[i]].size() == 0)
//             {
//                 hmap[s[i]] = s[i];
//                 continue;
//             }
//             hmap[s[i]] += s[i];
//         }
//         vector<pair<int, string>> vec;
//         int full_length = 0;
//         for (auto v : hmap)
//         {
//             vec.push_back(make_pair(v.second.size(), v.second));
//             full_length = full_length + v.second.size();
//         }
//         sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
//              { return a.first > b.first; });
//         for (auto v : vec)
//         {
//             cout << v.first << " " << v.second << endl;
//         }
//         full_length = 2 * vec[0].second.size() - full_length;

//         if (full_length >= 2)
//         {
//             return "";
//         }
//         string ans = "";
//         while (vec.size() > 0)
//         {
//             if (vec.size() >= 2)
//             {
//                 if (vec[0].second.size() != 0 && vec[1].second.size() != 0)
//                 {

//                     if (ans.length() > 1 && (ans[ans.length() - 1] == vec[0].second[0]))
//                     {
//                         ans = ans + vec[1].second[0] + vec[0].second[0];
//                         vec[0].second.pop_back();
//                         vec[1].second.pop_back();
//                     }
//                     else
//                     {

//                         ans = ans + vec[0].second[0] + vec[1].second[0];
//                         vec[0].second.pop_back();
//                         vec[1].second.pop_back();
//                     }
//                 }
//                 if (vec[1].second.size() == 0)
//                 {
//                     vec.erase(vec.begin() + 1);
//                 }
//                 if (vec[0].second.size() == 0)
//                 {
//                     vec.erase(vec.begin() + 0);
//                 }
//             }
//             else
//             {
//                 if (vec[0].second.size() == 2)
//                 {
//                     return "";
//                 }
//                 ans = ans + vec[0].second;
//                 vec.erase(vec.begin() + 0);
//             }
//         }

//         return ans;
//     }
// };

int main()
{
    Solution o;
    cout << o.reorganizeString("ogccckcwmbmxtsbmozli");

    return 0;
}