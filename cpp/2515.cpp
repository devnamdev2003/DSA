#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
      int closetTarget(vector<string> words, string target, int startIndex)
      {
            int ans = words.size();
            bool t = false;
            for (int i = 0; i < words.size(); i++)
            {
                  if (words[i] == target)
                  {
                        t = 1;
                        int temp = std::abs(startIndex - i);
                        if (temp < ans)
                        {
                              ans = temp;
                        }
                        temp = words.size() - temp;
                        if (temp < ans)
                        {
                              ans = temp;
                        }
                  }
            }
            if (t == 1)
            {
                  return ans;
            }
            else
            {
                  return -1;
            }
      }
};

int main()
{
      Solution obj;
      cout << obj.closetTarget({"hello", "i", "am", "leetcode", "hello"}, "hello", 1);

      return 0;
}