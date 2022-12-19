#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int function(vector<string> operations)
{
      int ans=0;
      for(int i=0;i<operations.size();i++){
            if(operations[i]=="X++" || operations[i]=="++X"){
                  ans=ans+1;
            }
            else{
                  ans=ans-1;
            }
      }
      return ans;
}
void show(vector<string> v)
{

      for (int i = 0; i < v.size(); i++)
      {
            cout << v[i] << " ";
      }
      cout<<endl;
}
int main()
{
      vector<string> v1 = {"X++","++X","--X","X--"};
      show(v1);
      int v2 = function(v1);
      cout<<v2;
      return 0;
}