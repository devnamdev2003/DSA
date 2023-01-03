#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> arr, int k)
{
      int count = 0;
      int i = 0;
      int in = 0;
      for (i = 1; i < arr.size() + k; i++)
      {
            if (arr[in] != i)
            {
                  count++;
                  if (count == k)
                  {
                        return i;
                  }
            }
            else
            {
                  if (in < arr.size()-1)
                  {
                        in++;
                  }
            }
            cout<<arr[in]<<" "<<in<<" ";
      }
      cout<<endl;
      return i;
}

int main()
{
      vector<int> v1 = {1,2,3,4};
      int k = 5;
      cout << function(v1, k);
      return 0;
}