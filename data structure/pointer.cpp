#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
      static int a;
};

int Node::a = 90;
int fun()
{
      
}
int main()
{
      cout << Node::a;
      return 0;
}