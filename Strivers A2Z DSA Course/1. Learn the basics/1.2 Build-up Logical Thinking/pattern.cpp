#include <bits/stdc++.h>
using namespace std;
void a()
{
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void b()
{
    int h;
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void c()
{
    int h;
    cin >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void d()
{
    int h;
    cin >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

void e()
{
    int h;
    cin >> h;
    for (int i = h; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void f()
{
    int h;
    cin >> h;
    for (int i = h; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void g()
{
    int N;
    cin >> N;
    int total = (2 * (N - 1)) + 1;

    for (int i = 0; i < N; i++)
    {
        int total_star = (i * 2) + 1;
        for (int j = 0; j < (total - total_star) / 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < total_star; j++)
        {

            cout << "*";
        }
        for (int j = 0; j < (total - total_star) / 2; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void h()
{
    int N;
    cin >> N;
    int total = (2 * (N - 1)) + 1;

    for (int i = N - 1; i >= 0; i--)
    {
        int total_star = (i * 2) + 1;
        for (int j = 0; j < (total - total_star) / 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < total_star; j++)
        {

            cout << "*";
        }
        for (int j = 0; j < (total - total_star) / 2; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void i()
{
    int N;
    cin >> N;
    int total = (2 * (N - 1)) + 1;

    for (int i = 0; i < N; i++)
    {
        int total_star = (i * 2) + 1;
        for (int j = 0; j < (total - total_star) / 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < total_star; j++)
        {

            cout << "*";
        }
        for (int j = 0; j < (total - total_star) / 2; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = N - 2; i >= 0; i--)
    {
        int total_star = (i * 2) + 1;
        for (int j = 0; j < (total - total_star) / 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < total_star; j++)
        {

            cout << "*";
        }
        for (int j = 0; j < (total - total_star) / 2; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void j()
{
    int h;
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = h - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void k()
{
    int h;
    cin >> h;
    bool b = true;
    for (int i = 0; i < h; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout << b;
            b = (b ? false : true);
        }
        cout << endl;
    }
}

void l()
{
    int h;
    cin >> h;
    int total = h * 2;
    for (int i = 0; i < h; i++)
    {
        int space = (i + 1) * 2;
        for (int j = 1; j <= space / 2; j++)
        {
            cout << j;
        }
        for (int j = 0; j < total - space; j++)
        {
            cout << " ";
        }
        for (int j = space / 2; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}

void m()
{
    int h;
    cin >> h;
    int count = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << count;
            count++;
        }
        cout << endl;
    }
}

void n()
{
    int h;
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << static_cast<char>('A' + j);
        }
        cout << endl;
    }
}

void o()
{
    int h;
    cin >> h;
    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << static_cast<char>('A' + j);
        }
        cout << endl;
    }
}

void p()
{
    int h;
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << static_cast<char>('A' + i);
        }
        cout << endl;
    }
}

void q()
{
    int N;
    cin >> N;
    int total = (2 * (N - 1)) + 1;

    for (int i = 0; i < N; i++)
    {
        int total_char = (i * 2) + 1;
        for (int j = 0; j < (total - total_char) / 2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (total_char / 2) + 1; j++)
        {
            cout << static_cast<char>('A' + j);
        }
        for (int j = (total_char / 2) - 1; j >= 0; j--)
        {
            cout << static_cast<char>('A' + j);
        }
        for (int j = 0; j < (total - total_char) / 2; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void r()
{
    int h;
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            cout << static_cast<char>('A' + (h - 1) - j);
        }
        cout << endl;
    }
}

void s()
{
    int h;
    cin >> h;
    int total = h * 2;
    for (int i = h - 1; i >= 0; i--)
    {
        int space = (i + 1) * 2;
        for (int j = 1; j <= space / 2; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < total - space; j++)
        {
            cout << " ";
        }
        for (int j = space / 2; j >= 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < h; i++)
    {
        int space = (i + 1) * 2;
        for (int j = 1; j <= space / 2; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < total - space; j++)
        {
            cout << " ";
        }
        for (int j = space / 2; j >= 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void t()
{
    int h;
    cin >> h;
    int total = h * 2;

    for (int i = 0; i < h; i++)
    {
        int space = (i + 1) * 2;
        for (int j = 1; j <= space / 2; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < total - space; j++)
        {
            cout << " ";
        }
        for (int j = space / 2; j >= 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = h - 2; i >= 0; i--)
    {
        int space = (i + 1) * 2;
        for (int j = 1; j <= space / 2; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < total - space; j++)
        {
            cout << " ";
        }
        for (int j = space / 2; j >= 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void u()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0 || j == n - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }

        cout << endl;
    }
}

void v()
{
    int n;
    cin >> n;
    int total = (2 * n) - 1;
    for (int i = 1; i <= n - 1; i++)
    {
        int num = i * 2;
        for (int j = 0; j < num / 2; j++)
        {
            cout << n - j;
        }
        for (int j = 0; j < total - num; j++)
        {
            cout << n - i + 1;
        }
        for (int j = (num / 2) - 1; j >= 0; j--)
        {
            cout << n - j;
        }
        cout << endl;
    }
    for (int i = n; i > 0; i--)
    {
        cout << i;
    }
    for (int i = 2; i <= n; i++)
    {
        cout << i;
    }
    cout << endl;

    for (int i = n - 1; i >= 1; i--)
    {
        int num = i * 2;
        for (int j = 0; j < num / 2; j++)
        {
            cout << n - j;
        }
        for (int j = 0; j < total - num; j++)
        {
            cout << n - i + 1;
        }
        for (int j = (num / 2) - 1; j >= 0; j--)
        {
            cout << n - j;
        }
        cout << endl;
    }
}

int main()
{
    v();
    return 0;
}

// *****
// *****
// *****
// *****
// *****
// ---------------------------------
// *
// **
// ***
// ****
// *****
// ---------------------------------
// 1
// 12
// 123
// 1234
// 12345
// ---------------------------------
// 1
// 22
// 333
// 4444
// 55555
// ---------------------------------
// *****
// ****
// ***
// **
// *
// ---------------------------------
// 12345
// 1234
// 123
// 12
// 1
// ---------------------------------
//     *
//    ***
//   *****
//  *******
// *********
// ---------------------------------
// *********
//  *******
//   *****
//    ***
//     *
// ---------------------------------
//     *    
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *
// ---------------------------------
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
// ---------------------------------
// 1
// 01
// 010
// 1010
// 10101
// ---------------------------------
// 1        1
// 12      21
// 123    321
// 1234  4321
// 1234554321
// ---------------------------------
// 1
// 23
// 456
// 78910
// 1112131415
// ---------------------------------
// A
// AB
// ABC
// ABCD
// ABCDE
// ---------------------------------
// ABCDE
// ABCD
// ABC
// AB
// A
// ---------------------------------
// A
// BB
// CCC
// DDDD
// EEEEE
// ---------------------------------
//     A    
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
// ---------------------------------
// E
// DE
// CDE
// BCDE
// ABCDE
// ---------------------------------
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ---------------------------------
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// ---------------------------------
// *****
// *   *
// *   *
// *   *
// *****
// ---------------------------------
// 555555555
// 544444445
// 543333345
// 543222345
// 543212345
// 543222345
// 543333345
// 544444445
// 555555555
// ---------------------------------