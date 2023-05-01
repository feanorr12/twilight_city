#include <cmath>
#include <iostream>
#include <fstream>
#include<cstring>
#include<iomanip>
using namespace std;

//хеш функция умножение
int HashFunction(int k,int N)
{
double A=0.618033;
int h=N*fmod(k*A, 1);
return h;
}
class HashTable
{
private:
   struct Node
   {
       int Kollizia;
       struct Node* kolizia;
       string Company, Country,town,street;
       int home;
       struct Node* next;
   };
   Node* head = NULL;
   Node* head1 = NULL;
   int col = 0;
   int n = 10;
public:
   void addNode(int a);
   int foundNode(int i);
   void Resize();
   void MakeArr();
   void FirdtRead();
   void PritnArr();
   void Delete(string name);
   void Search(string name);
   void Insert();
};

//рехеширование
void HashTable::Resize()
{
  if (n <= col*2 )
  {
    n = n*2;
    for(int i = 0; i < n; i++)
    {
         Node* ptr1 = new Node;
         ptr1->Kollizia = 0;
         ptr1->next = NULL;
         ptr1->kolizia = NULL;
         ptr1->Company = "";
         if (head1 == NULL)
             head1 = ptr1;
         else
         {
             Node* current = head1;
             while (current->next != NULL)
                 current = current->next;
             current->next = ptr1;
         }
      }
      Node* ptr2 = head1;
      Node* ptr = head;
      string s = { "" };
    for (int x = 0; x <n/2; x++)
    {
        if ( s!= ptr->Company)
        {
          int z = HashFunction(ptr->Company.size(),n);
          ptr2 = head1;
          for (int i = 1; i <= z; i++)
          {
             ptr2 = ptr2->next;
          }
          ptr2->Company = ptr->Company;
          ptr2->Country = ptr->Country;
          ptr2->town    = ptr->town;
          ptr2->street  = ptr->street;
          ptr2->home    = ptr->home;
        }
        Node* ptr4 = ptr->kolizia ;
        for (int j=1; j <= ptr->Kollizia; j++)
        {
           ptr2->Kollizia ++;
           Node* ptr3 = new Node;
           ptr3->Kollizia = 0;
           ptr3->next = NULL;
           if (ptr2->kolizia == NULL)
           {
             ptr2->kolizia = ptr3;
           }
           else
           {
              Node* current = ptr2->kolizia;
              while (current->next != NULL)
              {
                  current = current->next;
                  ptr4 = ptr4->next;
              }
              current->next = ptr3;
           }
           ptr3->Company = ptr4->Company;
           ptr3->Country = ptr4->Country;
           ptr3->town    = ptr4->town;
           ptr3->street  = ptr4->street;
           ptr3->home    = ptr4->home;
        }
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
      head = head1;
      head1 = NULL;
  }
}

void HashTable::Delete(string name)
{
    col--;
    int i=HashFunction(name.size(),n);
    Node* ptr = head;
    for (int x = 1; x <= i; x++)
    {
        ptr = ptr->next;
    }
    if (ptr->Company == name )
    {
      cout<<"DELETE! \n";
      ptr->Company = "";
      ptr->Country = "";
      ptr->town = "";
      ptr->street = "";
      ptr->home = 0;
    }
    else
    {
      Node* ptr1 = ptr->kolizia;
      while (ptr1->next != NULL)
      {
          if (ptr1->Company == name)
          {
            break;
          }
          ptr1 = ptr1->next;
      }
      ptr->Kollizia --;
      ptr1->Company = "";
      ptr1->Country = "";
      ptr1->town = "";
      ptr1->street = "";
      ptr1->home = 0;
      cout<<"DELETE! \n";
    }
}
void HashTable::Insert()
{
  string name;
  cin>>name;
  col++;
  int i=HashFunction(name.size(),n);
  Node* ptr = head;
  for (int x = 1; x <= i; x++)
  {
      ptr = ptr->next;
  }
  if (ptr->Company == "")
  {
   ptr->Company = name;
   cout<<"Country\n";
   cin>>ptr->Country;
   cout<<"Town\n";
   cin>>ptr->town;
   cout<<"Street\n";
   cin>>ptr->street;
   cout<<"Home\n";
   cin>>ptr->home;
  }
  else
  {
    ptr->Kollizia ++;
    Node* ptr1 = new Node;
    ptr1->Kollizia = 0;
    ptr1->next = NULL;
    if (ptr->kolizia == NULL)
    {
       ptr->kolizia = ptr1;
    }
    else
    {
        Node* current = ptr->kolizia;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = ptr1;
    }
    ptr1->Company = name;
    cout<<"Country\n";
    cin>>ptr1->Country;
    cout<<"Town\n";
    cin>>ptr1->town;
    cout<<"Street\n";
    cin>>ptr1->street;
    cout<<"Home\n";
    cin>>ptr1->home;
  }
}

void HashTable::Search(string name)
{
    int i=HashFunction(name.size(),n);
    Node* ptr = head;
    for (int x = 1; x <= i; x++)
    {
        ptr = ptr->next;
    }
    if (ptr->Company == name)
    {
       std::cout<<std::setw(15)<<std::left<<ptr->Company<<":   "<<std::setw(15)<<ptr->Country<<std::setw(20)<<ptr->town<<std::setw(25)<<ptr->street<<std::setw(15)<<ptr->home<<"\n";
    }
    else
    {
      Node* ptr1 = ptr->kolizia;
      for(int j = 1; j<=ptr->Kollizia; j++)
      {
        if (ptr1->Company == name)
        {
            std::cout<<std::setw(15)<<std::left<<ptr1->Company<<":   "<<std::setw(15)<<ptr1->Country<<std::setw(20)<<ptr1->town<<std::setw(25)<<ptr1->street<<std::setw(15)<<ptr1->home<<"\n";
        }
        ptr1 = ptr1->next;
      }
    }
}

void HashTable::MakeArr()
{
   for(int i = 0; i < n; i++)
   {
        Node* ptr = new Node;
        ptr->Kollizia = 0;
        ptr->next = NULL;
        ptr->kolizia = NULL;
        ptr->Company = "";
        if (head == NULL)
            head = ptr;
        else
        {
            Node* current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = ptr;
        }
   }
}

void HashTable::PritnArr()
{
  Node* ptr = head;
  string s = { "" };
  for (int x = 0; x <n; x++)
  {
      if (s!=ptr->Company)
      {
              std::cout<<std::setw(15)<<std::left<<ptr->Company<<":   "<<std::setw(15)<<ptr->Country<<std::setw(20)<<ptr->town<<std::setw(25)<<ptr->street<<std::setw(15)<<ptr->home<<"\n";
              if (ptr->Kollizia!=0)
              {
                 Node* ptr1 = ptr->kolizia;
                 for(int j = 1; j<=ptr->Kollizia; j++)
                 {
                  std::cout<<std::setw(15)<<std::left<<ptr1->Company<<":   "<<std::setw(15)<<ptr1->Country<<std::setw(20)<<ptr1->town<<std::setw(25)<<ptr1->street<<std::setw(15)<<ptr1->home<<"\n";
                  ptr1 = ptr1->next;
                 }
             }
      }
      ptr = ptr->next;
  }
}

void HashTable::FirdtRead()
{
  string name = {"data3.txt"};
  std::ifstream read;
  read.open(name, std::ifstream::in);
  string Name_Company;
  int i;
  while(!read.eof())
  {
    read>>Name_Company;
    if (read.eof())
    {
      break;
    }
    i=HashFunction(Name_Company.size(),n);
    col++;
    Node* ptr = head;
    for (int x = 1; x <= i; x++)
    {
        ptr = ptr->next;
    }
    if (ptr->Company == "")
    {
     ptr->Company = Name_Company;
     read>>ptr->Country;
     read>>ptr->town;
     read>>ptr->street;
     read>>ptr->home;
    }
    else
    {
      ptr->Kollizia ++;
      Node* ptr1 = new Node;
      ptr1->Kollizia = 0;
      ptr1->next = NULL;
      if (ptr->kolizia == NULL)
      {
         ptr->kolizia = ptr1;
      }
      else
      {
          Node* current = ptr->kolizia;
          while (current->next != NULL)
          {
              current = current->next;
          }
          current->next = ptr1;
      }
      ptr1->Company = Name_Company;
      read>>ptr1->Country;
      read>>ptr1->town;
      read>>ptr1->street;
      read>>ptr1->home;
    }

  }
}

int main()
{
  int a;
  HashTable hash;
  hash.MakeArr();
  hash.FirdtRead();
  cout<<"Choose command:\n";
  cout<<"1 - print table\n";
  cout<<"2 - delete element\n";
  cout<<"3 - serch element\n";
  cout<<"4 - insert element\n";
  cout<<"5 - exsit\n";
  cin>>a;
  while (a !=5)
  {
    hash.Resize();
    switch(a)
    {
      case 1:
      {
        hash.PritnArr();
        break;
      }
      case 2:
      {
        cout<<"Enter name company that you want delete\n";
        string name;
        cin>>name;
        hash.Delete(name);
        break;
      }
      case 3:
      {
        cout<<"Enter name company that you want search\n";
        string name;
        cin>>name;
        hash.Search(name);
        break;
      }
      case 4:
      {
        cout<<"Enter name company that you want insert\n";
        hash.Insert();
        hash.PritnArr();
        break;
      }
      default:
      {
         exit(1);
      }
    }
    cout<<"Choose command:\n";
    cin>>a;
  }
  return 0;
}
