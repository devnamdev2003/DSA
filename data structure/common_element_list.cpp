#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    Node *head1 = new Node(4);
    head1->next = new Node(8);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(17);
    head1->next->next->next->next = new Node(18);
    Node *head2 = new Node(4);
    head2->next = new Node(10);
    head2->next->next = new Node(18);
    Node *result = findIntersection(head1, head2);
    printList(head1);
    cout << endl;
    printList(head2);
    cout << endl;
    printList(result);

    return 0;
}

Node *findIntersection(Node *head1, Node *head2)
{
    Node *head = nullptr;
    Node *itr;
    while (head1 != nullptr)
    {
        if (head1->data == head2->data)
        {
            if (head == nullptr)
            {
                head = new Node(head1->data);
                itr = head;
            }
            else
            {
                itr->next = new Node(head1->data);
                itr = itr->next;
            }
            head2 = head2->next;
        }
        head1 = head1->next;
    }
    return head;
}