#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
void insertH(node *&tail, int val)
{
    if (tail == nullptr)
    {
        tail = new node(val);
        tail->next = tail;
    }
    else
    {
        node *temp = new node(val);
        temp->next = tail->next;
        tail->next = temp;
    }
}
void insertT(node *&tail, int val)
{
    if (tail == nullptr)
    {
        tail = new node(val);
        tail->next = tail;
    }
    else
    {
        node *temp = new node(val);
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}
void print(node *tail)
{
    node *temp = tail;
    if (tail == nullptr)
    {
        cout << "empty";
        return;
    }
    while (temp->next != tail)
    {
        cout << temp->next->data << " ";
        temp = temp->next;
    }
    cout << temp->next->data;
    cout << endl;
}
int main()
{
    node *tail = nullptr;
    for (int i = 1; i <= 6; i++)
    {
        insertT(tail, i);
    }
    // insertT(tail, 12);
    // insertT(tail, 122);
    // insertH(tail, 11);
    // insertH(tail, 10);
    // insertH(tail, 177);
    print(tail);
    return 0;
}