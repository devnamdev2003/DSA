#include <iostream>
#include <vector>
using namespace std;
vector<int> sort(vector<int> v)
{

      for (int i = 0; i < v.size() - 1; i++)
      {
            int min = v[i];
            int min_index = i;
            for (int j = i + 1; j < v.size(); j++)
            {
                  if (min > v[j])
                  {
                        min = v[j];
                        min_index = j;
                  }
            }
            if (v[i] > v[min_index])
            {
                  int temp = v[i];
                  v[i] = v[min_index];
                  v[min_index] = temp;
            }
      }

      return v;
}

void show(vector<int> v, int index)
{
      if (index == v.size())
      {
            return;
      }
      cout << v[index] << " ";
      show(v, index + 1);
}
int main()
{
      show(sort({11, 12, 5}), 0);
      return 0;
}