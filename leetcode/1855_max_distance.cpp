#include <iostream>
#include <vector>
using namespace std;
// vector<int> nums1 = {9914, 9434, 8808, 8041, 7548, 6727, 5637, 4635, 2937, 607, 384, 335},
// nums2 = {9980, 9826, 9620, 9600, 9455, 9448, 9374, 9367, 9278, 9251, 9083, 8987, 8952, 8932, 8762, 8705, 8595, 8460};
int function(vector<int> nums1, vector<int> nums2)
{
      int f = 0, s = 0;
      for (int i = 0; i < nums1.size(); i++)
      {
            for (int j = i; j < nums2.size(); j++)
            {
                  if (nums1[i] <= nums2[j])
                  {
                        if (j - i >= s - f)
                        {
                              f = i;
                              s = j;
                        }
                  }
                  else if (nums1[i] > nums2[j])
                  {
                        break;
                  }
            }
            if (s - f >= nums1.size() - i && s - f >= nums2.size())
            {
                  break;
            }
      }

      return s - f;
}
int main()
{
      vector<int> nums1 = {9914, 9434, 8808, 8041, 7548, 6727, 5637, 4635, 2937, 607, 384, 335}, nums2 = {9980, 9826, 9620, 9600, 9455, 9448, 9374, 9367, 9278, 9251, 9083, 8987, 8952, 8932, 8762, 8705, 8595, 8460};
      cout << function(nums1, nums2);
      return 0;
}
