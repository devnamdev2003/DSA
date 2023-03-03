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

void insert_T(node *&head, int data)
{
    if (head == nullptr)
    {
        head = new node(data);
        return;
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new node(data);
}

void display(node *head)
{
    if (head == nullptr)
    {
        cout << "empty";
        return;
    }
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
node *rehead = nullptr;
node *reverse(node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    node *temp = reverse(head->next);
    if (temp == nullptr)
    {
        rehead = head;
        return head;
    }
    temp->next = head;
    head->next = nullptr;
    return head;
}
int main()
{
    // a is a first node
    node *head = nullptr;
    insert_T(head, 12);
    insert_T(head, 11);
    insert_T(head, 10);
    insert_T(head, 9);
    insert_T(head, 8);
    display(head);
    reverse(head);
    cout << endl;
    display(rehead);

    return 0;
}