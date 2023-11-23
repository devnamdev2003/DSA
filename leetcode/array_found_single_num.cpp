#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int function(vector<int> nums)
{
      int result{0};
      for (const auto &c : nums)
            result ^= c;
      return result;
}
int main()
{

      vector<int> v1 = {4, 1, 2, 1, 2};
      cout << function(v1);
}