#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int functions(vector<int> seats, vector<int> students)
{
      sort(seats.begin(), seats.end());
      sort(students.begin(), students.end());
      int ans = 0;
      int start = 0;
      int end = 0;

      while (start < seats.size() && end < students.size())
      {
            ans += std::abs(seats[start] - students[end]);
            start++;
            end++;
      }
      return ans;
}

int main()
{
      vector<int> seats = {1, 5, 3};
      vector<int> students = {2, 7, 4};
      cout << functions(seats, students);
      return 0;
}