#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class MyHashMap
{
public:
    map<int, int> m;
    MyHashMap()
    {
        map<int, int> mp;
        m = mp;
    }

    void put(int key, int value)
    {
        m[key] = value;
    }

    int get(int key)
    {
        for (auto v : m)
        {
            if (v.first == key)
            {
                return 1;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        m.erase(key);
    }
};
int main()
{
    MyHashMap mp;
    mp.put(1, 2);
    cout << mp.get(1);
    cout<<endl;
    mp.put(1, 22);
    cout<<mp.m[1];
    mp.remove(1);
    cout << mp.get(1);


    return 0;
}