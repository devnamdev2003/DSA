#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *pre;
    node *next;
    node(int data)
    {
        this->data = data;
        this->pre = nullptr;
        this->next = nullptr;
    }
};
void insert(node *&head, node *&tail, int val, int p = 0)
{
    if (head == nullptr)
    {
        head = new node(val);
        tail = head;
        return;
    }
    if (p == 0)
    {
        node *temp = new node(val);
        temp->next = head;
        head->pre = temp;
        head = temp;
        return;
    }
    int count = 0;
    node *temp = head;
    while (count != p - 1)
    {
        if (temp->next == nullptr)
        {
            temp->next = new node(val);
            tail = temp->next;
            tail->pre = temp;
            return;
        }
        temp = temp->next;
        count++;
    }
    if (temp->next == nullptr)
    {
        temp->next = new node(val);
        tail = temp->next;
        tail->pre = temp;
        return;
    }
    node *temp2 = new node(val);
    temp2->next = temp->next;
    temp2->pre = temp;
    temp->next->pre = temp2;
    temp->next = temp2;
}
void display1(node *head)
{
    if (head == nullptr)
    {
        cout << "Empty" << endl;
    }
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void display2(node *tail)
{
    if (tail == nullptr)
    {
        cout << "Empty" << endl;
    }
    while (tail != nullptr)
    {
        cout << tail->data << " ";
        tail = tail->pre;
    }
}
int main()
{
    node *head = nullptr;
    node *tail = nullptr;
    insert(head, tail, 12, 11);
    insert(head, tail, 13, 22);
    insert(head, tail, 14, 12);
    insert(head, tail, 15);
    insert(head, tail, 18, 1);
    insert(head, tail, 16, 2);
    insert(head, tail, 17, 6);
    display1(head);
    cout << endl;
    // display2(tail);

    return 0;
}