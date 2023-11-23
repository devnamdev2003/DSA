#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;
    // vector<string> v = {"dev1", "dev2", "dev"};
    // v.clear();
    for (auto val : v)
    {
        cout<<val<<" ";
    }
    // cout<<endl;
    // v.resize(10);
    // v.resize(10,7);
    // for (auto val : v)
    // {
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    if(v.empty()){
        cout<<"empty"<<endl;
    }
    else{
        cout << "not empty" << endl;
    }


    vector<int> v1={1,2,3,4,5,6,7,8,9,10};
    vector<int> v2={11,21,31,41,51,61,71,81,91,10};
    v1.insert(v1.begin()+v1.size()-1, v2.begin(), v2.end());
    for(auto val:v1){
        cout<<" "<<val;
    }
    cout<<endl;
    cout<<*v1.begin()<<endl;

    return 0;
}