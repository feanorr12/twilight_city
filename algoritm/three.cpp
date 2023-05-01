#include <stdlib.h>
#include <iostream>
#include <string>


using namespace std;

struct node
{
    int height;
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data, int val)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->height = val;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}


void PrintTree(struct node* temp, string indent , int number)
{
    string s1 = "   ";
    char array[] = { 'o', 'R', 'L' };
    if (temp != NULL)
    {
        cout <<indent<< " [" << array[number] << "]" << " - " << temp->data << "\n";
        indent.append(s1);
        //рекурсивный вызов для левой и правой веток
        PrintTree(temp->left, indent, 2);
        PrintTree(temp->right, indent, 1);
    }
}

struct node* findList(struct node* cur, int* deapth)
{
    struct node* rv = cur;
    int curDeapth = *deapth;
    if (cur->left)
    {
        (*deapth)++;
        rv = findList(cur->left, deapth);
    }
    if (cur->right)
    {
        int rightDeapth = curDeapth + 1;
        struct node* rightDeapest = findList(cur->right, &rightDeapth);
        if (rightDeapth < *deapth)
        {
            *deapth = rightDeapth;
            rv = rightDeapest;
        }
    }
    return rv;
}

void Go(struct node* temp)
{
    if (temp != NULL)
    {
        int deapth = 0;
        struct node* min = findList(temp, &deapth);
        if (temp->height == (min->height - temp->height))
        {
            cout << temp->data << "  ";
        }
        Go(temp->left);
        Go(temp->right);
    }
}


struct node* My_TREE(struct node* root)
{
    root = newNode('A', 0);
    root->left = newNode('B',1);
    root->right = newNode('C',1);
    root->left->left = newNode('D',2);
    root->left->right = newNode('E',2);
    root->right->left = newNode('F',2);
    root->right->right = newNode('G',2);
    root->left->left->left = newNode('S',3);
    root->left->left->right = newNode('Q',3);
    root->left->left->right->left = newNode('V', 4);
    root->left->left->right->left->right = newNode('H', 5);
    return (root);
};

void create_tree(struct node*& p, int n,int i)
{
    if (n == 0)
        p = NULL;
    else
    {
        p = new node;
        cin >> p->data;
        p->height = i;
        int nl = n / 2, nr = n - nl - 1;
        i++;
        create_tree(p->left, nl, i);
        create_tree(p->right, nr, i);
    }
}

int main()
{
    int number = 0;
    int n;
    struct node* root1 = NULL;
    struct node* root = NULL;
    string indent = "";
    int a;
    int i = 0;
    cout <<"If you want to type the tree yourself, enter 1, otherwise 2\n";
    cin >> a;
    switch (a)
    {
    case 1:
        {
        cout << "Enter size \n ";
        cin >> n;
        cout << "Enter Node..\n";
        create_tree(root, n, i);
        break;
        }
    case 2:
         {
           root = My_TREE(root1);
           break;
         }
    }
    PrintTree(root, indent,number);
    cout << "Node equidistant from the root and from the nearest leaf\n";
    Go(root);
  }
