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

void display_recursively(node *head)
{
    if (head == nullptr)
    {
        return;
    }
    cout << head->data << " ";
    display_recursively(head->next);
}

node *rehead = nullptr;
node *reverse1(node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    node *temp = reverse1(head->next);
    if (temp == nullptr)
    {
        rehead = head;
        return head;
    }
    temp->next = head;
    head->next = nullptr;
    return head;
}

node *reverse2(node *head)
{
    if (head->next == nullptr)
    {
        return head;
    }
    node *prev = nullptr;
    node *temp = head;
    while (temp != nullptr)
    {
        node *temp2 = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp2;
    }
    return prev;
}

void reverse3_recursively(node *&head, node *curr, node *prev)
{
    if (curr == nullptr)
    {
        head = prev;
        return;
    }
    reverse3_recursively(head, curr->next, curr);
    curr->next = prev;
}

node *reverse4_recursively(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    node *temp = reverse4_recursively(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}

node *reverse_group(node *head, int k)
{
    if (head == nullptr, head->next == nullptr)
    {
        return head;
    }
    node *temp = head;
    node *prev2 = nullptr;
    int a = 0;
    while (temp != nullptr)
    {
        int c = 0;
        a++;
        node *prev = nullptr;
        node *head_temp = temp;
        while (c != k)
        {
            if (temp == nullptr)
            {
                break;
            }
            c++;
            node *temp2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp2;
        }
        if (a == 1)
        {
            head = prev;
        }
        else
        {
            prev2->next = prev;
        }
        prev2 = head_temp;
    }
    return head;
}

int middle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast->next != nullptr)
    {
        slow = slow->next;
        if (fast->next->next == nullptr)
        {
            break;
        }
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    node *head = nullptr;
    for (int i = 1; i <= 4; i++)
    {
        insert_T(head, i);
    }
    display_recursively(head);
    cout << endl;
    // reverse3_recursively(head, head, nullptr);
    // display_recursively(reverse4_recursively(head));
    // display_recursively(reverse_group(head, 2));
    cout << middle(head);

    return 0;
}