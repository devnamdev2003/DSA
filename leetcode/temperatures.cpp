#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> temperatures)
{
      vector<int> ans;
      for (int i = 0; i < temperatures.size(); i++)
      {
            int count = 1;
            for (int j = i + 1; j < temperatures.size(); j++)
            {

                  if (temperatures[i] < temperatures[j])
                  {

                        ans.push_back(count);
                        break;
                  }

                  else if (j == temperatures.size() - 1)
                  {
                        count = 0;
                        ans.push_back(count);
                  }
                  else
                  {

                        count = count + 1;
                  }
            }
      }
      ans.push_back(0);
      return ans;
}
// vector<int> dailyTemperatures(vector<int>& temps){
//         stack<int> s;
//         vector<int> result(temps.size());
//         for (int i = 0; i < temps.size(); i++){
//             while (s.size() && temps[s.top()] < temps[i] ){
//                 result[s.top()] = i-s.top();
//                 s.pop();
//             }
//             s.push(i);
//         }
//         return result;
//     }
void show(vector<int> v)
{

      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
}
int main()
{
      vector<int> v1 = {73, 74, 75, 71, 69, 72, 76, 77};
      vector<int> v2 = dailyTemperatures(v1);
      show(v2);
      return 0;
}
