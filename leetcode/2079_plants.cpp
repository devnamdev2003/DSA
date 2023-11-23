#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
      int wateringPlants(vector<int> plants, int capacity)
      {
            int ans=0;
            int full = capacity;
            for (int i = 0; i < plants.size(); i++)
            {
                  if (capacity < plants[i])
                  {
                        capacity = full;
                        ans = ans + (2 * i) + 1;
                        capacity = capacity - plants[i];
                  }
                  else
                  {
                        capacity = capacity - plants[i];
                        ans = ans + 1;
                  }
            }
            return ans;
      }
};
void show_1d(vector<int> v)
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
      cout << obj.wateringPlants({2, 2, 3, 3}, 5);

      return 0;
}