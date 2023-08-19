#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    string s = "devnamdev";
    priority_queue<char> max_heap;
    for (int i = 0; i < s.size(); i++)
    {
        max_heap.push(s[i]);
        cout<<s[i]<<" "<<max_heap.top()<<endl;
    }
    cout<<endl;
    while(!max_heap.empty())
    {
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }

    return 0;
}