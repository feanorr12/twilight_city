#include<iostream>
#include <fstream>
#include<iomanip>
#include<cstdlib>

class list // класс для хранения одномерных массивов
{
private:
   struct Node
   {
       int value;
       struct Node* next;
   };
   Node* head = NULL;
public:
   void addNode(int a);
   int foundNode(int i);
};

class CRSArray
{
public:
   int x, y;
   list Lj, Li, A;
   int count = 0;
   void PrintArr();

};

class CSArray
{
private:
   list Lj, Li, A;
   int x, y;
   int count = 0;
public:
   void FillingFile();
   void FillingHand();
   void PrintArr();
   bool CheckSumm(CSArray one);
   friend CRSArray  operator + (CSArray& one, CSArray& two);
};

int main()
{
   int a;
   CSArray CS_1;
   CSArray CS_2;
   CRSArray CRS_1;
   std::cout << "If you want to type the data for the solution yourself, type 1,\n";
   std::cout << "if you want to read the data from the file, type 2\n";
   std::cin >> a;
   switch (a)
   {
   case 1:
   {
       CS_1.FillingHand();
       CS_2.FillingHand();
       break;
   }
   case 2:
   {
       CS_1.FillingFile();
       CS_2.FillingFile();
       break;
   }
   default:
   {
       std::cout << "Open the program again\n";
       exit(1);
   }
   }
   CS_1.PrintArr();
   CS_2.PrintArr();
   if (CS_1.CheckSumm(CS_2) == true)
   {
       std::cout << "\nSumma matrix:\n";
       CRS_1 = CS_1 + CS_2;
       CRS_1.PrintArr();
   }
   else
   {
       std::cout << "We cannot add up the matrix data\n";
       std::cout << "Because the number of rows and columns in them are not equal\n";
   }
   return 0;
}

void CSArray::FillingFile()
{
   int a;
   std::cout << "write the name of the file.\n";
   std::cout << "It must be located in the same package as the program and contain data for operation.\n";
   char name[10];
   std::cin >> name;
   std::ifstream read;
   read.open(name, std::ifstream::in);
   if (read.is_open())
   {
       read >> x;
       read >> y;
       for (int j = 0; j < y; j++)
       {
           for (int i = 0; i < x; i++)
           {
               read >> a;
               if (a != 0)
               {
                   A.addNode(a); // не нулевые элементы
                   Li.addNode(i); // строк в которой содержится данный не нулевой элмент
                   Lj.addNode(j); // столбец в котором содержится данный не нулевой элемент
                   count++; //кол-во не нулевых элементов
               }
           }
       }
   }
   else
   {
       std::cout << "There is no such file open the program again\n";
       exit(1);
   }
}

void CRSArray::PrintArr()
{
   int a = 0; // кол-во не нулевых элементов в данной строке
   int b = 0; // номер не нулевого элемента
   std::cout << "----------------------------------------\n";
   for (int j = 0; j < y; j++)
   {
       a = Li.foundNode(j + 1) - Li.foundNode(j);
       for (int i = 0; i < x; i++)
       {
           if (a != 0)
           {
               if (Lj.foundNode(b) == i)
               {
                   std::cout << std::setw(4) << A.foundNode(b);
                   b++;
                   a--;
               }
               else
               {
                   std::cout << std::setw(4) << "0";
               }
           }
           else
           {
              std::cout << std::setw(4) << "0";
           }
       }
       std::cout << "\n";
   }
}

bool CSArray::CheckSumm(CSArray one)
{
   return (one.x == x && one.y == y);
}

void CSArray::PrintArr()
{
   int a = 0; // кол-во не нулевых элементов
   std::cout << "----------------------------------------\n";
   for (int j = 0; j < y; j++)
   {
       for (int i = 0; i < x; i++)
       {
           if (a != count)
           {
               if (Li.foundNode(a) == i && Lj.foundNode(a) == j)
               {
                   std::cout << std::setw(4) << A.foundNode(a);
                   a++;
               }
               else
               {
                   std::cout << std::setw(4) << "0";
               }
           }
           else
           {
               std::cout << std::setw(4) << "0";
           }
       }
       std::cout << "\n";
   }
}

void CSArray::FillingHand()
{
   int a;
   std::cout << "Enter the number of rows and columns\n";
   std::cin >> x;
   std::cin >> y;
   for (int j = 0; j < y; j++)
   {
       for (int i = 0; i < x; i++)
       {
           std::cout << "Enter the element [" << i << "][" << j << "]\n";
           while (true)
           {
               std::cin >> a;
               if (std::cin.fail()) // если предидущее считывание было не удачным
               {
                   std::cout << "Enter the number ...\n";
                   std::cin.clear();
                   std::cin.ignore(32767, '\n');
               }
               else
               {
                   std::cin.ignore(32767, '\n');
                   break;
               }
           }
           if (a != 0) // если элемент не нулевой записываем его
           {
               A.addNode(a);
               Li.addNode(i);
               Lj.addNode(j);
               count++;
           }
       }
   }
}

CRSArray  operator + (CSArray& two, CSArray& one)
{
   int a = 0; // кол-во не нулевых элементов 1 массива
   int b = 0; // кол-во не нулевых элементов 2 массива
   int sum;
   int count = 1; // кол-во не нулевых элементов в итоге
   CRSArray CRS_1;
   CRS_1.x = one.x;
   CRS_1.y = one.y;
   CRS_1.Li.addNode(0);
   for (int j = 0; j < one.y; j++)
   {
       for (int i = 0; i < one.x; i++)
       {
           sum = 0;
           if (a != two.count)
           {
               if (two.Li.foundNode(a) == i && two.Lj.foundNode(a) == j)
               {
                   sum = two.A.foundNode(a);
                   a++;
               }
           }
           if (b != one.count)
           {
               if (one.Li.foundNode(b) == i && one.Lj.foundNode(b) == j)
               {
                   sum = sum + one.A.foundNode(b);
                   b++;
               }
           }
           if (sum != 0)
           {
               CRS_1.A.addNode(sum);
               CRS_1.Lj.addNode(i);
               CRS_1.count++;
               count++;
           }
       }
       CRS_1.Li.addNode(count);
   }
   return CRS_1;
}



void list::addNode(int a)
{
   Node* ptr = new Node;
   ptr->value = a;
   ptr->next = NULL;
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

int list::foundNode(int i)
{
   Node* ptr = head;
   for (int x = 1; x <= i; x++)
   {
       ptr = ptr->next;
   }
   return (ptr->value);
}

list::~list()
{
   std::cout<<"WE WORK!";
   Node* ptr = head->next;
   head->next = NULL;
   head = ptr;
   while (head)
   {
       ptr = head->next;
       delete head;
       head = ptr;
   }
}
