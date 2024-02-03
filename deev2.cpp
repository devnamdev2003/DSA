#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> customzigzag(int h, vector<int> nodes)
{
    vector<int> result;
    if (h % 2 == 0)
    {
        int term = 0;
        for (int i = 0; i < h; i++)
        {
            term = pow(2, i)-1;
            cout << term << " ";
            result.push_back(nodes[term]);
        }
    }
    else
    {
        int term = 0;
        for (int i = 0; i < h; i++)
        {
            term = pow(2, i + 1) - 2;
            cout << term << " ";
            result.push_back(nodes[term]);
        }
    }
    cout << endl;
    return result;
}

int main()
{
    vector<int> nodes = {1, 2, 5, 3, 4, 4, 9};
    vector<int> result = customzigzag(3, nodes);

    for (int value : result)
    {
        cout << value << " ";
    }

    return 0;
}
