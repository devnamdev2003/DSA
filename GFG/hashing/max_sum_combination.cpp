#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
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
class Solution
{
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    {
        if (N == 1)
        {
            return {A[0] + B[0]};
        }
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        vector<int> ans;
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ans.push_back(A[i] + B[j]);
            }

        }
        sort(ans.begin(), ans.end(), greater<int>());
        vector<int> ans2;
        ans2.insert(ans2.begin(), ans.begin(), ans.begin() + K);
        return ans2;
    }
};
int main()
{
    Solution obj;
    int N = 1;
    int C = 1;
    vector<int> A = {7};
    vector<int> B = {9};
    vector<int> ans;
    ans = obj.maxCombinations(N, C, A, B);
    show_1d(ans);
    return 0;
}