#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
// "001011"
      vector<int> minOperations(string boxes)
      {
            vector<int> ans(boxes.size(), 0);
            for (int i = 0; i < boxes.size(); i++)
            {
                  for (int l = i - 1; l >= 0; l--)
                  {
                        // cout << l << " ";
                        if(boxes[l]=='1'){
                              ans[i]=ans[i]+(i-l);
                        }
                  }
                  for (int r = i + 1; r < boxes.size(); r++)
                  {
                        // cout << r << " ";
                        if(boxes[r]=='1'){
                              ans[i]=ans[i]+(r-i);
                        }
                  }
            }
            return ans;
      }
};
void show(vector<int> v)
{

      cout << "[";
      for (int i = 0; i < v.size(); i++)
      {
            if (i < v.size() - 1)
            {
                  cout << v[i] << ",";
            }
            else
            {
                  cout << v[i];
            }
      }
      cout << "]";
      cout << endl;
}
int main()
{
      Solution obj;
      show(obj.minOperations("11"));
      return 0;
}