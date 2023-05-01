#include <stdlib.h>
#include <iostream>
#include <string>


using namespace std;

struct node
{
  int data;
  int Node;
  struct node *firstchild = NULL;
  struct node *nextsibling = NULL;
};

struct node* newNode(int data,int Node)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->Node = Node;
    node->firstchild = NULL;
    node->nextsibling = NULL;
    return (node);
}

void PrintTree(struct node* temp, string indent, int number)
{
    string s1 = "   ";
    if (temp != NULL)
    {
       if (number == 2)
          indent.append(s1);
        cout <<indent<< " - " << temp->data <<"("<<temp->Node<< ")\n";
        PrintTree(temp->firstchild, indent,  2);
        PrintTree(temp->nextsibling, indent, 1);
    }
}

void foundNode(struct node* temp,int val)
{
  if (temp != NULL)
  {
    if (val ==  temp->data )
    {
      cout<<temp->Node<<"  ";
    }
    foundNode(temp->firstchild,val);
    foundNode(temp->nextsibling,val);
  }
}

int foundNode1(struct node* temp,int val, int& x)
{
  if (temp != NULL)
  {
    if (val ==  temp->data )
    {
      x++;
    }
    foundNode1(temp->firstchild,val,x);
    foundNode1(temp->nextsibling,val,x);
  }
  return x;
}

void found(struct node* temp,struct node* head, int* mas,int max)
{
  int val;
  int x=0;
  if (temp != NULL)
  {
    val = temp->data;
    for (int i=0; i < max;  i++ )
    {
       if (val == mas[i])
       {
          break;
       }
       if (mas[i] == 0)
       {
             mas[i] = val;
             int kol = foundNode1(head,val,x);
             if (kol != 1)
             {
               cout<< val<<" - ";
               foundNode(head,val);
               cout<<"\n";
             }
             break;
      }
    }
    found(temp->firstchild,head,mas,max);
    found(temp->nextsibling,head,mas,max);
  }
}

struct node* My_TREE(struct node* root, int& max)
{
    root = newNode(1, 0);
    root->firstchild = newNode(5,1);
    root->firstchild->nextsibling = newNode(4,2);
    root->firstchild->nextsibling->nextsibling = newNode(3,3);
    root->firstchild->nextsibling->nextsibling->nextsibling = newNode(2,4);
    root->firstchild->firstchild = newNode(1,5);
    root->firstchild->firstchild->nextsibling = newNode(8,6);
    root->firstchild->firstchild->nextsibling->nextsibling = newNode(6,7);
    root->firstchild->firstchild->nextsibling->nextsibling->nextsibling = newNode(5,8);
    root->firstchild->nextsibling->firstchild = newNode(2,9);
    root->firstchild->nextsibling->firstchild->nextsibling = newNode(0,10);
    root->firstchild->nextsibling->firstchild->firstchild = newNode(7,11);
    root->firstchild->nextsibling->firstchild->firstchild->nextsibling = newNode(1,12);
    root->firstchild->nextsibling->firstchild->firstchild->nextsibling->nextsibling = newNode(6,13);
    root->firstchild->nextsibling->firstchild->firstchild->nextsibling->nextsibling->nextsibling = newNode(5,14);
    max=14;
    return (root);
}

void create_root(struct node*& root,int N,int n , int& i)
{

  if (i != N)
  {
     int a;
     cout<<"Enter Node\n";
     cin>> a;
     root = newNode(a,i);
     i++;
     if ((i-1)%n == 0)
     {
        create_root(root->firstchild,N,n,i);
     }
     else
     {
        create_root(root->nextsibling,N,n,i);
     }
   }
   else
   {
     return;
   }

}

int main()
{

    int number=2;

    int max, n, N,i=0;
    struct node* root = NULL;
    string indent = "";
    cout <<"If you want to type the tree yourself, enter 1, otherwise 2\n";
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
        {
           cout<<"Enter kol-vo son\n";
           cin>>n;
           cout << "\nEnter size \n ";
           cin>>max;
           N=max;
           max = max -1;
           create_root(root,N,n,i);
           cout<<n<<"-tree\n";
           break;
        }
    case 2:
         {
           root = My_TREE(root,max);
           cout<<4<<"-tree\n";
           break;
         }
    default:
      {
        break;
      }
    }
    PrintTree(root, indent,number);
    int *mas = (int*)malloc(sizeof(int) * max);
    for (int i=0; i<max; i++)
    {
      mas[i]=0;
    }
    cout<<"\n\n";
    found(root,root,mas,max);
}
