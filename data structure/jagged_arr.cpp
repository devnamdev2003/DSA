#include <iostream>
using namespace std;

int main()
{
      int row;
      cout << "Enter: ";
      cin >> row;
      int **arr = new int *[row];
      int *size = new int[row];
      for (int i = 0; i < row; i++)
      {
            cout
                << "Enter " << i << "th"
                << " col size: ";
            cin >> size[i];
            *(arr + i) = new int[size[i]];
      }
      for (int i = 0; i < row; i++)
      {
            for (int j = 0; j < size[i]; j++)
            {
                  cin >> arr[i][j];
            }
      }
      cout << endl;
      for (int i = 0; i < row; i++)
      {
            for (int j = 0; j < size[i]; j++)
            {

                  cout << arr[i][j] << " ";
            }
            cout << endl;
      }
}