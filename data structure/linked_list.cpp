#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
      int data;
      Node *next = nullptr;
      Node(int val)
      {
            this->data = val;
            this->next = nullptr;
      }
};

// void printList(Node *n)
// {
//       while (n != nullptr)
//       {
//             cout << n->data << " ";
//             n = n->next;
//       }
// }
// void insert(Node *last_node)
// {
//       while (last_node->next != nullptr)
//       {
//             last_node = last_node->next;
//       }
//       int val;
//       cout << "val: ";
//       cin >> val;
//       Node *p = new Node;
//       last_node->next = p;
//       p->data = val;
//       p->next = nullptr;
// }

void print(Node *head)
{
      while (head != nullptr)
      {
            cout << head->data << " ";
            head = head->next;
      }
}
int main()
{

      Node *head;
      Node *h = new Node(12);
      h->next = new Node(13);
      h->next->next = new Node(132);
      h->next->next->next = new Node(134);
      h->next->next->next->next = new Node(136);
      head = nullptr;
      Node *itr = new Node(0);
      head = itr;
      for (int i = 1; i <= 5; i++)
      {
            Node *temp = new Node(i);
            itr->next = temp;
            itr = temp;
      }

      print(head);
      // int s;
      // cout << "size: ";
      // cin >> s;
      // Node *head = new Node;
      // int i = 0;
      // while (i < s)
      // {
      //       insert(head);
      //       i++;
      // }

      // printList(head->next);

      return 0;
}
