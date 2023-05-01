#ifndef MYLIB_H__
#define MYLIB_H__
#include <ctime>
namespace mylib {
//фигура
class Figure
{
public:
  int  a1[4][4]={
        {0,20,20,0},
        {0,20,20,0},
        {0,0,0,0},
        {0,0,0,0},
      };
  int a5[4][4]={
           {0,0,20,0},
           {0,0,20,0},
           {0,0,20,0},
           {0,0,20,0},
         };
    int a4[4][4]={
             {0,0,0,0},
             {0,0,0,0},
             {20,20,20,20},
             {0,0,0,0},
         };
    int a3[4][4]={
             {0,20,0,0},
             {0,20,0,0},
             {0,20,0,0},
             {0,20,0,0},
         };
   int a2[4][4]={
            {0,0,0,0},
            {20,20,20,20},
            {0,0,0,0},
            {0,0,0,0},
         };
   int a6[4][4]={
            {20,0,0,0},
            {20,20,20,0},
            {0,0,0,0},
            {0,0,0,0},
         };
   int a7[4][4]={
            {0,0,20,20},
            {0,0,20,0},
            {0,0,20,0},
            {0,0,0,0},
         };
   int a8[4][4]={
            {0,20,20,20},
            {0,0,0,20},
            {0,0,0,0},
            {0,0,0,0},
         };
  int  a9[4][4]={
            {0,0,0,0},
            {0,20,0,0},
            {0,20,0,0},
            {20,20,0,0},
         };
  int a10[4][4]={
            {0,20,20,0},
            {20,20,0,0},
            {0,0,0,0},
            {0,0,0,0},
         };
  int a11[4][4]={
            {0,0,20,0},
            {0,0,20,20},
            {0,0,0,20},
            {0,0,0,0},
         };
  int a12[4][4]={
            {0,0,0,0},
            {0,0,0,0},
            {0,20,20,0},
            {20,20,0,0},
         };
  int a13[4][4]={
            {20,0,0,0},
            {20,20,0,0},
            {0,20,0,0},
            {0,0,0,0},
         };
  int a14[4][4]={
            {0,20,0,0},
            {20,20,20,0},
            {0,0,0,0},
            {0,0,0,0},
         };
  int a15[4][4]={
            {0,0,20,0},
            {0,0,20,20},
            {0,0,20,0},
            {0,0,0,0},
         };
  int a16[4][4]={
            {0,0,0,0},
            {0,0,0,0},
            {20,20,20,0},
            {0,20,0,0},
         };
  int a17[4][4]={
            {0,20,0,0},
            {20,20,0,0},
            {0,20,0,0},
            {0,0,0,0},
         };

  int a18[4][4]={
            {20,20,0,0},
            {0,20,20,0},
            {0,0,0,0},
            {0,0,0,0},
         };
  int  a19[4][4]={
            {0,0,0,20},
            {0,0,20,20},
            {0,0,20,0},
            {0,0,0,0},
         };
  int a20[4][4]={
            {0,0,0,0},
            {0,0,0,0},
            {20,20,0,0},
            {0,20,20,0},
         };
  int  a21[4][4]={
            {0,20,0,0},
            {20,20,0,0},
            {20,0,0,0},
            {0,0,0,0},
         };
  int  a22[4][4]={
            {0,0,0,20},
            {0,20,20,20},
            {0,0,0,0},
            {0,0,0,0},
         };
  int  a23[4][4]={
            {20,20,0,0},
            {0,20,0,0},
            {0,20,0,0},
            {0,0,0,0},
         };
  int a24[4][4]={
            {0,0,0,20},
            {0,20,20,20},
            {0,0,0,0},
            {0,0,0,0},
         };
  int a25[4][4]={
            {0,0,0,0},
            {0,0,20,0},
            {0,0,20,0},
            {0,0,20,20},
         };
int color;
int form;
int rout=1,z;
int x_pol;
int y_pol;
int speed;
int as[4][4];
int go_down();
int go_left();
int go_right();
int go_rotation();
int go_rotation2();
int chg_colour();
int chg_form();
void chg_fig ();
void Pointer( int V, int St);
void Pointer2(int V, int count[7]);
};

//стакан
class Glass 
{
public:
int i,j;
int l;
int V=2;
int y1=0;
int y2=0;
int y3=0;
int y4=0;
int width=20; //ширина поля
int height=10; //высота поля
int line=0;
int level=0;
int array[26][15]={0};
bool chg_down(int as[4][4], int x,int y);
bool chg_left(int as[4][4], int x,int y);
bool chg_right(int as[4][4], int x,int y);
bool chg_rotation(int as[4][4], int x,int y);
void Painter(int as[4][4],int x,int y);
void Clear();
void old_fig(int as[4][4],int x,int y);
void chg_line();
int  prize_line(int speed);
void go_down_glass_1();
void go_down_glass_2();
void Pointer(int f, int St);
void gotoxy(int x,int y);
bool new_figure();
int  proec_figure(int x,int y,int as[4][4],int N);
void proec_figureN();
int  proec_figureN2(int N, int y);
void Pointer2(char ch);
void Information(int speed, int& start);
};
//игра
class Game 
{ public:
  void Came_Title();
  void Pause();
  void VIn();
  void Came_Record();
  void help();
  void help2();
  void Hellow();
  void nastr(int p);
  void Size(int p);
  void Meny(int p); 
  void Gamemenu();
};

}

#endif
