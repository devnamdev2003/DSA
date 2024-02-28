#include <iostream>
#include <cmath>
// Armstrong Numbers are the numbers having the sum of digits raised to power no. of digits is equal to a given number. Examples- 0, 1, 153, 370, 371, 407, and 1634 are some of the Armstrong Numbers.
using namespace std;

bool ArmstrongNumber(int n)
{
    if (n <= 0)
    {
        return false; // Exclude non-positive numbers
    }

    int originalno = n;
    int count = 0;
    int temp = n;

    // Count the number of digits
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }

    int sumofpower = 0;

    // Compute the sum of powers of digits
    while (n != 0)
    {
        int digit = n % 10;
        int ans = pow(digit, count);
        sumofpower += ans;
        n /= 10;
    }
    cout << sumofpower;
    cout << endl;
    cout << originalno;
    // Check if the sum of powers is equal to the original number
    return (sumofpower == originalno);
}

int main()
{
    int n1;
    cout << "Enter a number: ";
    n1 = 153;

    if (ArmstrongNumber(n1))
    {
        cout << "Yes, it is an Armstrong Number\n";
    }
    else
    {
        cout << "No, it is not an Armstrong Number\n";
    }

    return 0;
}
