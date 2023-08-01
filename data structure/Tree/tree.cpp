#include <iostream>
#include <queue>

using namespace std;
class node
{
public:
    int data;
    node *l;
    node *r;
    node(int data)
    {
        this->data = data;
        this->l = nullptr;
        this->r = nullptr;
    }
};

node *insert(node *root)
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    root = new node(data);
    cout << "left side: ";
    root->l = insert(root->l); // Pass root->l as argument
    cout << "right side: ";
    root->r = insert(root->r); // Pass root->r as argument
    return root;
}

void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->l);
    preorder(root->r);
}
void inorder(node *root)
{
    if (root == nullptr)
    {
        // cout << root->data << " ";
        return;
    }
    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
}
void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->r);
    postorder(root->l);
    cout << root->data << " ";
}
int CountLeaf(node *root, int count)
{
    if (root == nullptr)
    {
        // count++;
        return count;
    }
    if (root->l == nullptr && root->r == nullptr)
    {
        count++;
        return count;
    }
    count = CountLeaf(root->l, count);
    count = CountLeaf(root->r, count);
    return count;
}
void level(node *root)
{
    int count = 0;
    queue<node *>
        q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                count++;
                q.push(nullptr);
            }
        }
        else
        {
            if (temp->l)
            {
                q.push(temp->l);
            }
            if (temp->r)
            {
                q.push(temp->r);
            }
        }
    }
    cout << endl;
    cout << count;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
int main()
{
    node *root = nullptr;
    root = insert(root);
    cout << endl;
    // preorder(root);
    // cout << endl;
    inorder(root);
    // cout << endl;
    // postorder(root);
    cout << endl;
    level(root);
    cout << endl;
    // cout << CountLeaf(root, 0);

    return 0;
}