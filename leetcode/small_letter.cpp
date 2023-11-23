#include <iostream>
#include <vector>
#include <set>
using namespace std;

char function(vector<char> letters, char target)
{
      set<char> st;
      char ans = letters[0];
      for (auto i : letters)
      {
            st.insert(i);
      }
      for (auto i : st)
      {
            // cout<<i<<" ";
            if (i > target)
            {
                  ans = i;
                  break;
            }
      }
      return ans;
}
int main()
{
      vector<char> letters = {'c', 'f', 'j'};
      char target = 'a';
      cout << function(letters, target);
}