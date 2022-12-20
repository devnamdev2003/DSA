#include <iostream>
#include <vector>
#include <string>
using namespace std;
int function(vector<string> sentences)
{
      int ans = 0;
      int sum;
      for (int i = 0; i < sentences.size(); i++)
      {
            string words = sentences[i];
            sum = 0;
            for (int j = 0; j < words.length(); j++)
            {
                  if (' ' == words[j])
                  {
                        sum++;
                  }
            }
            if (sum >= ans)
            {
                  ans = sum;
            }
      }

      return ans + 1;
}
void show(vector<int> v)
{

      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      cout << endl;
}
int main()
{
      vector<string> v1 = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
      // cout << v1[0];
      cout << function(v1);

      return 0;
}