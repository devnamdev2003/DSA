#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    string str = "abcdeababcd";
    map<char, int> hmap;
    for (int i = 0; i < str.size(); i++)
    {
        hmap[str[i]] += 1;
    }
    for (auto v : hmap)
    {
        cout << "accurence of [" << v.first << "]: " << hmap[v.first] << endl;
    }
    
    return 0;
}