#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// Should return data of node at given index. The function may
//  assume that there are at least index+1 nodes in linked list
int GetNth(struct node *head, int index)
{
    // Code here
    int count = 1;
    while (count != index)
    {
        head = head->next;
    }
    return head->data;
}
int main()
{
    node *head = new node(11);
    head->next = new node(12);
    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << GetNth(head, 0);

    return 0;
}