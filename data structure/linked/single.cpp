#include <iostream>
using namespace std;
class node
{
public:
    int val;
    node *point;
    node(int val)
    {
        this->val = val;
        this->point = nullptr;
    }
};
void insert_H(node *&a, int val)
{
    if (a == nullptr)
    {
        a = new node(val);
        return;
    }
    node *temp = new node(val);
    temp->point = a;
    a = temp;
}
void insert_T(node *&a, int val)
{
    if (a == nullptr)
    {
        a = new node(val);
        return;
    }
    node *b = a;
    while (b->point != nullptr)
    {
        b = b->point;
    }
    b->point = new node(val);
}
void insert_M(node *&a, int val, int p = 0)
{
    if (p == 0)
    {
        insert_H(a, val);
        return;
    }
    if (a == nullptr)
    {
        a = new node(val);
        return;
    }
    int count = 0;
    node *temp = a;
    while (count != p - 1)
    {
        if (temp->point == nullptr)
        {
            break;
        }
        temp = temp->point;
        count++;
    }
    node *b = new node(val);
    b->point = temp->point;
    temp->point = b;
}
void delete_M(node *&a, int val)
{
    if (a == nullptr)
    {
        return;
    }
    else if (a->point == nullptr)
    {
        if (a->val == val)
        {
            node *temp;
            temp = a;
            a = temp->point;
            delete temp;
        }
        return;
    }
    else if (a->val == val)
    {
        node *temp;
        temp = a;
        a = temp->point;
        delete temp;
    }
    node *temp = a;
    while (temp->point != nullptr)
    {
        if (temp->point->val == val)
        {
            temp->point = temp->point->point;
            temp = temp->point;
            delete temp;
            return;
        }
        temp = temp->point;
    }
}
bool search(node *a, int key)
{
    if (a == nullptr)
    {
        return 0;
    }
    while (a != nullptr)
    {
        if (a->val == key)
        {
            return 1;
        }
        a = a->point;
    }
    return 0;
}
void display(node *a)
{
    if (a == nullptr)
    {
        cout << "empty";
        return;
    }
    while (a != nullptr)
    {
        cout << a->val << " ";
        a = a->point;
    }
}
int main()
{
    // a is a first node
    node *a = nullptr;
    insert_M(a, 11, 12);
    insert_M(a, 12, 12);
    insert_M(a, 13, 17);
    insert_M(a, 14, 12);
    insert_M(a, 15, 12);
    insert_M(a, 16, 12);
    insert_M(a, 17, 12);
    search(a, 11) ? cout << "Exist" << endl : cout << "Not Exist" << endl;
    search(a, 19) ? cout << "Exist" << endl : cout << "Not Exist" << endl;
    search(a, 14) ? cout << "Exist" << endl : cout << "Not Exist" << endl;
    search(a, 17) ? cout << "Exist" << endl : cout << "Not Exist" << endl;
    display(a);
    cout << endl;
    delete_M(a, 11);
    delete_M(a, 14);
    delete_M(a, 17);
    delete_M(a, 170);
    display(a);

    return 0;
}