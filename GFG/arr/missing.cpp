#include <iostream>
#include<vector>
#include<algorithm>
class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        int i=0;
        int total;
        total=(n*(n+1))/2;
        for(int j=0;j<n;j++){
            i+=array[j];
        }
        return total-i;
    }
};
using namespace std;
int main()
{
    Solution obj;
    int arr[6]={1,2,3,4,5,6};
    cout<<obj.missingNumber(arr,7);
    
    return 0;
}