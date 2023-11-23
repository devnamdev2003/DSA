#include <iostream>
#include <string>
using namespace std;

class student
{
private:
      string name;
      int age;
      string branch;

public:
      void show(string nam, int agi, string bran)
      {
            name = nam;
            age = agi;
            branch = bran;
            cout << name << " " << age << " " << branch;
      }
};

int main()
{
      student dev;
      dev.show("dev", 12, "CSE");
      return 0;
}