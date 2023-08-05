#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n=7;
    int a[]={10,31,2,13,4,5,6};
    sort(a,a+n);
    cout<<a[n-1];   
    return 0;
}