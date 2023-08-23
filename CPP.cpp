#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void print(int n)
{
    if (n % 10 == 0)
    {
        return;
    }
    cout << n % 10;
    print(n / 10);
}
bool palindrone1(int n)
{
    int d = n;
    int ans = 0;
    while (n > 0)
    {
        ans = (ans * 10) + (n % 10);
        n = n / 10;
    }
    bool s = d == ans ? 1 : 0;
    return s;
}
bool armstrong(int n)
{
    int d = n;
    int sum = 0;
    while (n > 0)
    {
        sum = sum + (pow((n % 10), 3));
        n = n / 10;
    }
    bool ok = (d == sum) ? true : false;
    return ok;
}
void print_divisiors(int n)
{
    int ans = 1;
    while (ans <= n / ans)
    {
        if (n % ans == 0)
        {
            cout << ans << endl;
            if (ans != n / ans)
            {
                cout << n / ans << endl;
            }
        }
        ans++;
    }
}
int gcd_number(int n1, int n2)
{
    if (n1 != 0 && n2 != 0)
    {
        int mn = min(n1, n2);
        int mx = max(n1, n2);
        int ans = gcd_number(mx - mn, mn);
        return ans;
    }
    else
    {
        return max(n1, n2);
    }
    return 1;
}

int sumofn(int n)
{
    if (n == 0)
    {
        return n;
    }
    return sumofn(n - 1) + n;
}

int factorialofn(int n)
{
    if (n == 1)
    {
        return n;
    }
    return factorialofn(n - 1) * n;
}

void reverseanarry(int *a, int l, int r)
{
    if (l > r)
    {
        return;
    }

    swap(a[l], a[r]);
    reverseanarry(a, l++, r--);
}

bool palindrone2(string s, int r, int l = 0)
{
    if (l > r)
    {
        return true;
    }
    if (s[l] != s[r])
    {
        return false;
    }
    return palindrone2(s, --r, ++l);
}
int main()
{
    // cout<<palindrrome(434);
    // cout << armstrong(371);
    // print_divisiors(23);
    // cout << gcd_number(22, 150);
    // cout << sumofn(5);
    // int arr[] = {1, 2, 3, 4, 56};
    // reverseanarry(arr, 0, 4);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << palindrone2("a", 0);

    return 0;
}