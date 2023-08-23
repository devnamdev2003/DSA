#include <iostream>
#include <vector>
using namespace std;

vector<int> function(vector<int> nums1, vector<int> nums2)
{
      vector<int> ans;
      for (int i = 0; i < nums1.size(); i++)
      {
            for (int j = 0; j < nums2.size(); j++)
            {
                  if (nums1[i] == nums2[j] && nums1[i] >= 0)
                  {
                        ans.push_back(nums1[i]);
                        auto it = nums1.begin();
                        auto it2 = nums2.begin();
                        nums1.erase(i + it);
                        nums1.insert(i + it, -1);
                        nums2.erase(j + it2);
                        nums2.insert(j + it2, -1);
                  }
            }
      }
      /* vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        vector<int> result;
        int pos1 = 0 , pos2 = 0;
        while(pos1 < nums1.size() && pos2 < nums2.size()){
            if(nums1[pos1] == nums2[pos2]){
                result.push_back(nums1[pos1]);
                pos1++;
                pos2++;
            }
            else if(nums1[pos1] > nums2[pos2]){
                pos2++;
            }
            else pos1++;
        }
       return result; */

return ans;
}
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
      vector<int> num1 = {1, 2, 2, 1};
      vector<int> num2 = {2, 2};
      show(function(num1, num2));

      return 0;
}
