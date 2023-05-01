#include "mylib.h"
#include <cstdlib> 
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <fstream> 
#include <ostream> 
#include<iomanip>
#include <term.h>
#include <cstring>
#include <ctime>
#include <ctime>

#define KEY_ESX   113
#define KEY_ENTER 32
#define KEY_DOWN  115
#define KEY_UP    119
#define KEY_RIGHT 100
#define KEY_LEFT  97
#define KEY_PAUSE 112

#define red     printf("\033[48;5;9m")
#define green   printf("\033[48;5;10m")
#define yellow  printf("\033[48;5;11m")
#define blue    printf("\033[48;5;12m")
#define magenta printf("\033[48;5;13m")
#define cyan    printf("\033[48;5;14m")

#define red1     printf("\033[38;5;9m")
#define green1   printf("\033[38;5;10m")
#define yellow1  printf("\033[38;5;11m")
#define blue1    printf("\033[38;5;12m")
#define magenta1 printf("\033[38;5;13m")
#define cyan1    printf("\033[38;5;14m")

#define red3     printf("\033[48;5;1m")
#define green3   printf("\033[48;5;2m")
#define yellow3  printf("\033[48;5;3m")
#define blue3    printf("\033[48;5;4m")
#define magenta3 printf("\033[48;5;5m")
#define cyan3    printf("\033[48;5;6m")


namespace mylib {

 void gotoxy(int x,int y)
 {
    printf("%c[%d;%df",0x1B,y,x);
 }
 void Game::Came_Title()
{
printf("\n\n\n\n\n\n\n\n\n\n\n");
printf("                                          \033[31m ##########   \033[33m ##########   \033[32m ##########   \033[36m ##########   \033[34m ##        ###   \033[35m ##########          \n");
printf("                                          \033[31m #   ##   #   \033[33m ##       #   \033[32m #   ##   #   \033[36m ##      ##   \033[34m ##     ### ##   \033[35m ##       #           \n");
printf("                                          \033[31m     ##       \033[33m ##           \033[32m     ##       \033[36m ##      ##   \033[34m ##    ###  ##   \033[35m ##                   \n");
printf("                                          \033[31m     ##       \033[33m #########    \033[32m     ##       \033[36m ##########   \033[34m ##   ###   ##   \033[35m ##                   \n");
printf("                                          \033[31m     ##       \033[33m ##           \033[32m     ##       \033[36m ##           \033[34m ##  ###    ##   \033[35m ##                   \n");
printf("                                          \033[31m     ##       \033[33m ##       #   \033[32m     ##       \033[36m ##           \033[34m ## ###     ##   \033[35m ##       #           \n");
printf("                                          \033[31m    ####      \033[33m ##########   \033[32m    ####     \033[36m ####          \033[34m ###        ##   \033[35m ##########          \n");
printf("\n\n\n\n\n\n\n");
}
 /*void Game::LOOSE()
{
printf("\n\n\n\n\n\n\n\n\n\n\n");
printf("        \033[31m ##########   \033[33m ##########   \033[32m   #######   \033[34m ##        ###   \033[35m ########## \033[33m ########## \033[31m ##       ## \033[34m ##    ##    ##\n");
printf("        \033[31m ##      ##   \033[33m ##      ##   \033[32m  ##     ##  \033[34m ##     ### ##   \033[35m ##       # \033[33m ##      ## \033[31m ##       ## \033[34m ##    ##    ##\n");
printf("        \033[31m ##      ##   \033[33m ##      ##   \033[32m  ##     ##  \033[34m ##    ###  ##   \033[35m ##         \033[33m ##      ## \033[31m ##       ## \033[34m ##    ##    ##\n");
printf("        \033[31m ##      ##   \033[33m ##########   \033[32m  ##     ##  \033[34m ##   ###   ##   \033[35m ##         \033[33m ########## \033[31m ######## ## \033[34m ##    ##    ##\n");
printf("        \033[31m ##      ##   \033[33m ##           \033[32m  ##     ##  \033[34m ##  ###    ##   \033[35m ##         \033[33m ##         \033[31m ##    ## ## \033[34m ##    ##    ##\n");
printf("        \033[31m ##      ##   \033[33m ##           \033[32m  ##     ##  \033[34m ## ###     ##   \033[35m ##         \033[33m ##         \033[31m ##    ## ## \033[34m ##    ##    ##\n");
printf("        \033[31m####    ####  \033[33m####          \033[32m   #######   \033[34m ###        ##   \033[35m ##         \033[33m####        \033[31m ######## ## \033[34m ##############\n");
printf("\n\n\n\n\n\n\n");
}*/
void Game::Pause()
{
printf("\n\n\n\n\n\n\n\n\n\n\n");
printf("                                          \033[31m ##########   \033[33m    #####     \033[32m ##    ##	    \033[36m  ########   \033[34m      #####     \n");
printf("                                          \033[31m ##      ##   \033[33m    ## ##     \033[32m ##    ##     \033[36m ##           \033[34m     ## ##     \n");
printf("                                          \033[31m ##      ##   \033[33m   ##   ##    \033[32m  ##  ##      \033[36m ##           \033[34m    ##   ##    \n");
printf("                                          \033[31m ##      ##   \033[33m   #######    \033[32m    ###       \033[36m  #########   \033[34m    #######    \n");
printf("                                          \033[31m ##      ##   \033[33m  ##     ##   \033[32m     ##       \033[36m ##           \033[34m   ##     ##   \n");
printf("                                          \033[31m ##      ##   \033[33m ##       ##  \033[32m     ##       \033[36m ##          \033[34m   ##       ##  \n");
printf("                                          \033[31m####    ####  \033[33m ##       ##  \033[32m    ####     \033[36m   #######    \033[34m   ##       ##  \n");
printf("\n\n\n\n\n\n\n");
}
void Game::VIn()
{
printf("\n\n\n\n\n\n\n\n\n\n\n");
printf("                                          \033[31m ##########   \033[33m   #######    \033[32m ########   \033[36m #########   \033[34m     #######     \033[34m      #####     \n");
printf("                                          \033[31m ##      ##   \033[33m  ##     ##   \033[32m ##    ##   \033[36m ##      #   \033[34m      ##  ##     \033[34m      ## ##     \n");
printf("                                          \033[31m ##      ##   \033[33m  ##     ##   \033[32m ##         \033[36m ##          \033[34m     ##   ##     \033[34m     ##   ##    \n");
printf("                                          \033[31m ##      ##   \033[33m  ##     ##   \033[32m #######    \033[36m ########    \033[34m    ##    ##     \033[34m     #######    \n");
printf("                                          \033[31m ##      ##   \033[33m  ##     ##   \033[32m ##   ##    \033[36m ##          \033[34m   ##     ##     \033[34m    ##     ##   \n");
printf("                                          \033[31m ##      ##   \033[33m  ##     ##   \033[32m ##   ##    \033[36m ##     #    \033[34m  ###########    \033[34m   ##       ##  \n");
printf("                                          \033[31m####    ####  \033[33m   #######    \033[32m #######    \033[36m ########    \033[34m  ##       ##    \033[34m   ##       ##  \n");
printf("\n\n\n\n\n\n\n");
}
void Game::Came_Record()
{
printf("\n\n\n\n\n\n\n\n\n\n\n");
printf("                                         \033[31m ##########   \033[33m ##########   \033[32m####   ###   \033[36m  ########    \033[34m ##########  \033[35m  #######   \033[31m ##       ##\n");
printf("                                         \033[31m ##      ##   \033[33m ##       #   \033[32m ##   ###    \033[36m ##      ##   \033[34m ##      ##  \033[35m   ##  ##   \033[31m ##       ##\n");
printf("                                       	 \033[31m ##      ##   \033[33m ##           \033[32m ## ###      \033[36m ##      ##   \033[34m ##      ##  \033[35m  ##   ##   \033[31m ##       ##\n");
printf("                                         \033[31m ##########   \033[33m #########    \033[32m ###         \033[36m ##	   ##  \033[34m  ##########  \033[35m ##    ##   \033[31m ######## ##\n");
printf("                                         \033[31m ##           \033[33m ##           \033[32m ## ###      \033[36m ##      ##   \033[34m ##          \033[35m##     ##   \033[31m ##    ## ##\n");
printf("                                         \033[31m ##           \033[33m ##       #   \033[32m ##   ###    \033[36m ##      ##   \033[34m ##    	    \033[35m###########  \033[31m ##    ## ##\n");
printf("                                         \033[31m ####         \033[33m ##########  \033[32m ####   ###   \033[36m  ########   \033[34m ####        \033[35m##       ##  \033[31m ######## ##\n");
printf("\n\n\n\n\n\n\n");
}
void Turning()
{
printf("\n\n\n\n\n\n\n\n\n\n\n");
printf("               					                                                     \033[31m    ##   ##      \n");
printf("               			                                                                     \033[31m     #####       \n");
printf("		\033[31m ##      ##   \033[33m    #####      \033[32m ##########   \033[36m ##########   \033[34m ##########   \033[35m  ########    \033[31m ##        ###   \033[35m ####   ###   \033[33m ##         ###\n");
printf("		\033[31m ##      ##   \033[33m    ## ##      \033[32m ##       #   \033[36m #   ##   #   \033[34m ##      ##   \033[35m ##      ##   \033[31m ##     ### ##   \033[35m  ##   ###    \033[33m ##      ### ##\n");
printf("		\033[31m ##      ##   \033[33m   ##   ##     \033[32m ##           \033[36m     ##       \033[34m ##      ##   \033[35m ##      ##   \033[31m ##    ###  ##   \033[35m  ## ###      \033[33m ##    ###   ##\n");
printf("		\033[31m ##########   \033[33m   #######     \033[32m ##           \033[36m     ##       \033[34m ##########   \033[35m ##      ##   \033[31m ##   ###   ##   \033[35m  ###         \033[33m ##   ###    ##\n");
printf("		\033[31m ##      ##   \033[33m  ##     ##    \033[32m ##           \033[36m     ##       \033[34m ##           \033[35m ##      ##   \033[31m ##  ###    ##   \033[35m  ## ###      \033[33m ##  ###     ## \n");
printf("		\033[31m ##      ##   \033[33m ##       ##   \033[32m ##       #   \033[36m     ##       \033[34m ##           \033[35m ##      ##   \033[31m ## ###     ##   \033[35m  ##   ###    \033[33m ## ###      ##\n");
printf("		\033[31m ##      ##   \033[33m ##       ##   \033[32m ##########   \033[36m    ####      \033[34m ####         \033[35m  ########    \033[31m ###        ##   \033[35m ####   ###   \033[33m ###         ##\n");
printf("\n\n\n\n\n\n\n");
}
void Game::help()
{
printf("\n\n\n");
printf("\x1B[37m");
printf("	KEY_ENTER -- выбор ; KEY_W -- ↑ ; KEY_S -- ↓ ; KEY_q -- выход ; ");
}
static struct termios initial_settings, new_settings;
static int peek_character = -1;
int readch() {
 char ch;
 if (peek_character != -1) {
  ch = peek_character;
  peek_character = -1;
  return ch;
 }
 read(0, &ch, 1);
 return ch;
}

void init_keyboard() 
{
 tcgetattr(0, &initial_settings);
 new_settings = initial_settings;
 new_settings.c_lflag &= ~ICANON;
 new_settings.c_lflag &= ~ECHO;
 new_settings.c_lflag &= ~ISIG;
 new_settings.c_cc[VMIN] = 1;
 new_settings.c_cc[VTIME] = 0;
 tcsetattr(0, TCSANOW, &new_settings);
}

void close_keyboard() 
{
 tcsetattr(0, TCSANOW, &initial_settings);
}

int kbhit() 
{
 char ch;
 int nread;
 if (peek_character != -1) return 1;
 new_settings.c_cc[VMIN] = 0;
 tcsetattr(0, TCSANOW, &new_settings);
 nread = read(0, &ch, 1);
 new_settings.c_cc[VMIN] = 1;
 tcsetattr(0, TCSANOW, &new_settings);
 if (nread == 1) {
  peek_character = ch;
  return 1;
 }
 return 0;
}

void Game::Gamemenu()
{
 int count[7];
 init_keyboard();
 int p=1;
 printf("\x1B[2J");
 gotoxy(4,6);
 printf("\x1B[34m");
 Came_Title();
 int c;
 int Q=0;
 Meny(p);
 int z=1;
 int S;
 while (z==1)
 {
   c=readch();
   printf("\a");
   switch (c)
   {
     case KEY_UP:{
      if (p>1)
      {
       p--;
        printf("\x1B[2J");
        gotoxy(4,6);
        Came_Title();
        Meny(p);
      }
      break;}
      case KEY_DOWN:{
       if (p<4)
       {
        p++;
        printf("\x1B[2J");
        gotoxy(4,6);
        Came_Title();
        Meny(p);
       }
       break;}
      case KEY_ESX:
        {exit(0);}
        case KEY_ENTER:
         {
           z=0;
           printf("\x1B[2J");
           switch(p)
           {
             case 1:
             { char name[20];
               gotoxy(4,6);
               Hellow();
               printf("\x1B[37m");
               std::ifstream ifs;
               ifs.open("rec.txt");
               int St;
               int start;
               ifs>>St;      
               ifs.close();
               std::cout<<"				КАК ВАС ЗОВУТ?\n";
               std::cin>>name;
               std::cout<<"Хорошей игры "<<name<<"!";
               usleep (200000);
               Glass glass;
                 for(int j=4;j<24;j++)
                 for (int i=0;i<3;i++)
                   glass.array[j][i]=10;
                   for(int j=4;j<24;j++)
                   for (int i=13;i<15;i++)
                     glass.array[j][i]=10;
                   for(int j=24;j<26;j++)
                   for (int i=0;i<15;i++)
                     glass.array[j][i]=10;
               glass.V=St%10;
               printf("\x1B[2J");
               glass.Information(0, start);
               glass.Pointer(0,St);
               int R=1;
               int d=0;
               while (R!=0)
                { 
                  printf("\x1B[2J");
                  Figure figure1;
                  Figure figure;
                  glass.Pointer(0,St);
                  figure.Pointer2(glass.V,count);
                  if (St/10==1) {figure.speed=500000;}
                  if (St/10==2) {figure.speed=250000;}
                  if (St/10==3) {figure.speed=100000;}
                  if (d==0)
                   {  
                     figure1.chg_colour();
                     figure1.chg_form();
                     figure.chg_colour();
                     figure.chg_form();
                     for (int i=0;i<=7;i++){count[i]=0;}
                   }
                   else
                   {
                    figure.color=figure1.color;
                    figure.form=figure1.form;
                    figure1.chg_colour();
                    figure1.chg_form();
                   }
                  d++;
                  figure1.chg_fig();
                  figure.chg_fig();
                  figure.x_pol=6;
		  figure.y_pol=1;
                  glass.Painter(figure.as, figure.x_pol,figure.y_pol);
                  glass.Information(figure.speed, start);
                  figure.Pointer2(glass.V,count);
                  //glass.Pointer(0,St);
                  figure1.Pointer(glass.V,St);
                  usleep (figure.speed);
                  S=1;
                  while (S!=0)
                  {  glass.Pointer(0,St);
                     figure1.Pointer(glass.V,St);
                     Q=glass.proec_figure( figure.x_pol,figure.y_pol,figure.as,Q);
                     glass.Clear();
                     figure.go_down();
                     glass.Painter(figure.as, figure.x_pol,figure.y_pol);
                     glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                     std::cout<<figure.form;
                     usleep (figure.speed);
                     printf("\x1B[2J");
                     figure1.Pointer(glass.V,St); 
                     glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                     glass.Pointer(0,St);
                    if (kbhit()){
                    c=readch();
                    switch(c)
                    {
                      case KEY_UP:
                      {
                        figure.go_rotation();
                        figure.chg_fig();
                        bool W=glass.chg_rotation(figure.as, figure.x_pol,figure.y_pol);
                      	figure.go_rotation2();
                        figure.chg_fig ();
                        if (W!=0) 
                        {
                         glass.proec_figureN();
                         glass.Clear();
                         figure.go_rotation();
                         figure.chg_fig ();
                         Q=glass.proec_figure( figure.x_pol,figure.y_pol,figure.as,Q);
                         glass.Painter(figure.as, figure.x_pol,figure.y_pol);
                         usleep (figure.speed);
                         printf("\x1B[2J");
                         figure1.Pointer(glass.V,St); 
                         glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                         figure1.Pointer(glass.V,St);
                         glass.Pointer(0,St);
                        } 
                        break;
                      }  
                      case KEY_RIGHT:
                      {
                       bool W=glass.chg_right(figure.as, figure.x_pol,figure.y_pol);
                       if (W!=0) 
                        {
                         glass.proec_figureN();
                         glass.Clear();
                         figure.go_right();
                         Q=glass.proec_figure( figure.x_pol,figure.y_pol,figure.as,Q);
                         glass.Painter(figure.as, figure.x_pol,figure.y_pol);
                         glass.Information(figure.speed, start);
                         usleep (figure.speed);
                         printf("\x1B[2J");
                         figure1.Pointer(glass.V,St); 
                         glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                         figure1.Pointer(glass.V,St);
                         glass.Pointer(0,St);
                        }
                       break; 
                      }
                    case KEY_LEFT:
                      {
                       bool W=glass.chg_left(figure.as, figure.x_pol,figure.y_pol);
                       if (W!=0) 
                         {
                          glass.proec_figureN();
                         glass.Clear();
                         figure.go_left();
                         Q=glass.proec_figure( figure.x_pol,figure.y_pol,figure.as,Q);
                         glass.Painter(figure.as, figure.x_pol,figure.y_pol);
                         usleep (figure.speed);
                         printf("\x1B[2J"); 
                         figure1.Pointer(glass.V,St);
                         figure1.Pointer(glass.V,St);
                         glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                         glass.Pointer(0,St);
                         }
                       break; 
                      }
                     case KEY_DOWN :
                      {
                         glass.Clear();
                         figure.y_pol=glass.proec_figureN2(Q,figure.y_pol);
                         usleep (figure.speed);
                         printf("\x1B[2J");
                         figure1.Pointer(glass.V,St);
                         figure1.Pointer(glass.V,St);
                         glass.Painter(figure.as, figure.x_pol,figure.y_pol);
                         glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                         glass.Pointer(0,St);
                       break;
                       }
                      case KEY_ESX :
                      {
                       exit(1);
                       break;
                      }
                     case KEY_PAUSE :
                      {
                       printf("\x1B[2J");
                       gotoxy(1,5);
                       Pause();
                       printf("Если хотите продолжить нажмите любую клавишу!");
                       while (!kbhit())
                       {
                        printf("\x1B[49m");
                        printf("\x1B[37m");}printf("\x1B[2J");
                       break;
                      }   
                   }
                  }
                    glass.proec_figureN(); 
                    glass.Pointer(0,St);
                    R=glass.new_figure(); 
                    S=glass.chg_down(figure.as, figure.x_pol,figure.y_pol);
                  }
                 count[0]=count[0]+1;
                 for (int x=1;x<=7;x++)
                 if (figure.form==x){ count[x]=count[x]+1;}
                 if (count[0]==15 && glass.line==0)
                 {
                  if (St==3){St=2;}
                  if (St==2){St=1;}
                 }
                 glass.old_fig(figure.as, figure.x_pol,figure.y_pol);
                 glass.chg_line();
                 if (glass.level==99999999){printf("\x1B[2J");VIn();exit(0);}
                 if (glass.y1!=0){
                 printf("\x1B[2J");
                 usleep (figure.speed);
                 figure1.Pointer(glass.V,St);
                 glass.Pointer(1,St);
                 printf("\x1B[49m"); 
                 glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                 usleep (200000);
                 printf("\x1B[2J");
                 glass.Pointer(0,St);
                 printf("\x1B[49m"); 
                 glass.Information(figure.speed, start);
                 figure1.Pointer(glass.V,St);
                 usleep (200000);
                 printf("\x1B[2J");   printf("\x1B[49m"); 
                 glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                 glass.Pointer(1,St);
                 figure1.Pointer(glass.V,St);
                 char ch='.';
                 glass.Pointer2(ch);
                 usleep (200000);
                 printf("\x1B[2J");   printf("\x1B[49m"); 
                 glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                 glass.Pointer(1,St);
                 figure1.Pointer(glass.V,St);
                 ch='*';
                 glass.Pointer2(ch);
                 usleep (200000);
                 printf("\x1B[2J");   printf("\x1B[49m"); 
                 glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                 ch='o';
                 glass.Pointer2(ch);
                 figure1.Pointer(glass.V,St);
                 usleep (200000);
                 printf("\x1B[2J");   printf("\x1B[49m"); 
                 glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                 ch='0';
                 glass.Pointer2(ch);
                 figure1.Pointer(glass.V,St);
                 usleep (200000);
                 printf("\x1B[2J");   printf("\x1B[49m"); 
                 glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                 ch='O';
                 glass.Pointer2(ch);
                 figure1.Pointer(glass.V,St);
                 usleep(200000);
                 printf("\x1B[2J");   printf("\x1B[49m"); 
                 glass.Information(figure.speed, start);figure.Pointer2(glass.V,count);
                 glass.go_down_glass_1();
                 figure1.Pointer(glass.V,St);
                 glass.Pointer(1,St);
                 usleep (figure.speed);
                 printf("\x1B[2J");
                 glass.go_down_glass_2();
                 figure1.Pointer(glass.V,St);
                 glass.Pointer(0,St);
                 figure.speed=glass.prize_line(figure.speed);
                 for(int j=0;j<4;j++)
                 for (int i=3;i<13;i++)
                   glass.array[4+j][i]=0;
                 }
                 close_keyboard();
               }
               std::ofstream as;int cou=0;
               int kol[3]={0}; char my_string[3][20];
               ifs.open("records.txt");
               int sc=0;
               char st;int r=0;
               int c=ifs.peek();
               if (c==1)
               {
               ifs.read((char*)&cou,5);
               for(int i=0;i<=cou;i++){
                ifs.read(my_string[i],20);
                ifs.read((char*)&kol[i],5);}
                ifs.close();
              if (cou=1)
               {r=1;
                if (glass.level>kol[0]) 
                 {
                    kol[1]=kol[0];
                    strcpy(my_string[1],my_string[0]);
                    kol[0]=glass.level;
                    if(name!=my_string[0])strcpy(my_string[0],name);
                 }
                 else {kol[1]=glass.level;strcpy(my_string[1],name);}
               }
                if (cou==2)
               {
                for(int i=0;i<2;i++)
               {  r=1;
                  if (glass.level>kol[i]) 
                  {if (i==0)
                   {kol[i+2]=kol[i+1];
                    kol[i+1]=kol[i];
                    strcpy(my_string[i+2],my_string[i+1]);
                    strcpy(my_string[i+2],my_string[i+1]);
                   } 
                   if (i==1)
                   {
                    kol[i+1]=kol[i];
                    strcpy(my_string[i+1],my_string[i]);
                   } 
                   kol[i]=glass.level;
                   if(name!=my_string[i])strcpy(my_string[i],name);
                  } else {kol[2]=glass.level;strcpy(my_string[2],name);}
               }
               }
               if (cou==3){
               for(int i=0;i<3;i++)
               {
                  if (glass.level>kol[i]) 
                  {if (i==0)
                   {
                    kol[i+2]=kol[i+1];
                    kol[i+1]=kol[i];
                    strcpy(my_string[i+2],my_string[i+1]);
                    strcpy(my_string[i+1],my_string[i]);
                   } 
                   if (i==1)
                   {
                    kol[i+1]=kol[i];
                    strcpy(my_string[i+1],my_string[i]);
                   } 
                   kol[i]=glass.level;
                   if(name!=my_string[i])strcpy(my_string[i],name);
                  } 
               }}
               sc++;}
               if (sc==0){as.open("records.txt");cou++;as.write((char*)&cou,5);as.write(name,20);
               as.write((char*)&glass.level,5);as.close(); } 
              else{
               if (r==1){cou++;}
               as.open("records.txt"); 
               as.write((char*)&cou,5);
               for(int i=0;i<cou;i++){
               as.write(my_string[i],20);
               as.write((char*)&kol[i],5);as.close();}}
               break;
               }
            case 2:
           {
             printf("\x1B[2J");
             gotoxy(1,1);
             Came_Record();
             int i=0;
             char my_string[20];
             int kol,cou;
             std::ifstream ifs;
             std::cout<<"							ИМЯ			  		        СЧЕТ\n\n";
             ifs.open("records.txt");
             printf("\x1B[37m");
             ifs.read((char*)&cou,5);
             for(i=0;i<cou;i++)
             { 
              int b=rand() % 6 +1;
              switch(b)
              {
      		case 1:{ red1; break;}
      		case 2:{ green1 ; break;}
      		case 3:{ yellow1  ; break;}
      		case 4:{ blue1 ; break;}
      		case 5:{ magenta1; break;}
      		case 6:{ cyan1 ; break;}
              }
              ifs.read(my_string,20);
              ifs.read((char*)&kol,5);
              std::cout<<"					  		"<<(i+1)<<"."<<my_string<<"		     		        "<<kol ;
              std::cout<<"\n\n";
            } 
            help2();
            int x=readch();
            if (x==32) {   Gamemenu();} else {exit(0);}
          break;
         }
         case 3:
         {
          printf("\x1B[2J");
          gotoxy(1,1);
           int b=rand() % 6 +1;
              switch(b)
              {
      		case 1:{ red1; break;}
      		case 2:{ green1 ; break;}
      		case 3:{ yellow1  ; break;}
      		case 4:{ blue1 ; break;}
      		case 5:{ magenta1; break;}
      		case 6:{ cyan1 ; break;}
              }
          printf("					**************************************************************************\r\n");
          printf("					*	          Nizhniy Novgorod Technical University		         *\r\n");
          printf("					*				Program Tetris		                 *\r\n");
          printf("					*	Performed student grupp 20-IVT-2. Zhalnina Ekaterina Evgenevna	 *\r\n");
          printf("					**************************************************************************\r\n\n\n\n");
          printf("\x1B[37m");
          printf("		            Тетрис - компьютерная игра, изначально придуманная и разработанная советским программистом.\n\n");
          printf("			    Игра реализована практически на всех современных компьютерах, мобильных телефонах, игровых консолях, многих карманных игровых устройствах.\n\n\n"); 
	  printf("			    Суть игры в тетрис состоит в том, что случайные фигуры падают сверху вниз.\n\n"); 	     
          printf("			    Во время полета каждой фигурки игрок может вращать ее вокруг своей оси и перемещаться влево и вправо по горизонтали.\n\n");  
          printf("			    Когда ряд из 10 ячеек заполняется по горизонтали, он исчезает. Очки начисляются за каждую исчезающую линию..\n\n"); 
	  printf("	                    Скорость падения каждой последующей фигурки увеличивается.\n\n"); 
	  printf("        		    Игра заканчивается, когда новая фигура больше не может падать, и затем подсчитывается общее количество очков за игру.\n\n\n"); 
          help2();
          int x=readch();
          if (x==32) {   Gamemenu();}
          break;
         }
         case 4:
         {
          int d=1,s=0;
          printf("\x1B[2J");
          gotoxy(4,6);
          printf("\x1B[34m");
          nastr(d);
          while(s==0)
          {
          c=readch();
          printf("\a");
          switch (c)
          {
          case KEY_UP:
          {
          if (d>1)
          {
          d--;
          printf("\x1B[2J");
          gotoxy(4,6);
          nastr(d);
          }
          break;
          }
          case KEY_DOWN:{
           if (d<3)
           {
           d++;
           printf("\x1B[2J");
           gotoxy(4,6);
           nastr(d);
           }
           break;}
          case KEY_ESX:
           {exit(0);}
          case KEY_ENTER:
          {
          s=d;         
          break;}
         }
       }
          int x=1,a=0;
          printf("\x1B[2J");
          gotoxy(4,6);
          printf("\x1B[34m");
          Size(x);
          while(a==0){
          c=readch();
          printf("\a");
         switch (c)
         {
          case KEY_UP:
          {
          if (x>1)
          {
          x--;
          printf("\x1B[2J");
          gotoxy(4,6);
          Size(x);
          }
          break;
          }
          case KEY_DOWN:{
           if (x<3)
           {
           x++;
           printf("\x1B[2J");
           gotoxy(4,6);
           Size(x);
           }
           break;}
          case KEY_ESX:
           {exit(0);}
          case KEY_ENTER:
          {
            a=x;
            break;}
        }
       }
              std::ofstream as;
              as.open("rec.txt");
              if (as.is_open())
              { 
                as<<s;
                as<<a;
              }
              as.close(); 
        Gamemenu();
          break;
         }
      }
    }
}
}}
void Game::help2()
{
printf("\n\n\n");
printf("\x1B[37m");
printf("	Если ты хочешь выйти нажми -- q ; если ты хочешь войти в меню нажми -- ENTER ;\n\n\n\n ");
}
 void Game::Meny(int p)
 {
  switch (p)
  {
   case 1:
   { 
     int b=rand() % 6 +1;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                               			Играть!\n\n");
     printf("\x1B[37m");
     printf("                                                              			Рекорды!\n\n");
     printf("                                                               			Информация!\n\n");
     printf("                                                              			Настройки!\n\n");
     break;
   }
   case 2:
   {
     printf("\x1B[37m");
     printf("                                                               			Играть!\n\n");
     int b=rand() % 6 +1;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                              			Рекорды!\n\n");
     printf("\x1B[37m");
     printf("                                                               			Информация!\n\n");
     printf("                                                              			Настройки!\n\n");
     break;
  }
  case 3:
  {
     printf("\x1B[37m");
     printf("                                                               			Играть!\n\n");
     printf("                                                              			Рекорды!\n\n");
     int b=rand() % 6 +1;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                               			Информация!\n\n");
     printf("\x1B[37m");
     printf("                                                              			Настройки!\n\n");
    break;
   }
   case 4:
   {
     printf("\x1B[37m");
     printf("                                                               			Играть!\n\n");
     printf("                                                              			Рекорды!\n\n");
     printf("                                                               			Информация!\n\n");
     int b=rand() % 6 +1;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                              			Настройки!\n\n");
     printf("\x1B[37m");
     break;
    }
  }
 printf("\n\n\n");
 printf("\x1B[37m");
 printf("	KEY_ENTER -- выбор ; KEY_W -- ↑ ; KEY_S -- ↓ ; KEY_q -- выход ; ");
 }

void Game::Size(int p)
{
  Turning();
  printf("                                                                 \x1B[37m Теперь выбрем размер игрового поля:\n\n\n\n");
  switch(p)
  {
   case 1:
   { int b=rand() % 6 +1;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                               			\n\n");
     printf("                                                              			1:1 \n\n");
     printf("\x1B[37m");
     printf("                                                               			1:2 \n\n");
     break;
   }
   case 2:
   {     printf("                                                               		\n\n");
     printf("\x1B[37m");
     printf("                                                               			1:1\n\n");
     int b=rand() % 6 +1; 
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                              			1:2\n\n");
     printf("\x1B[37m");
     break;
   }
  }
}
void Game::Hellow()
{
printf("\n\n\n\n\n");
printf("                                           \033[31m##########    \033[33m#########   \033[32m##         ###  \033[36m########    \033[34m#########    \033[35m ##########   \n");
printf("                                           \033[31m##      ##    \033[33m##     ##   \033[32m##      ### ##  \033[36m##      #   \033[34m##      #    \033[35m #   ##   #   \n");
printf("                                           \033[31m##      ##    \033[33m##     ##   \033[32m##    ###   ##  \033[36m##      #   \033[34m##           \033[35m     ##       \n");
printf("                                           \033[31m##      ##    \033[33m#########   \033[32m##   ###    ##  \033[36m########    \033[34m#########    \033[35m     ##       \n");
printf("                                           \033[31m##      ##    \033[33m##          \033[32m##  ###     ##  \033[36m##      #   \033[34m##           \033[35m     ##       \n");
printf("                                           \033[31m##      ##    \033[33m##          \033[32m## ###      ##  \033[36m##      #   \033[34m##      #    \033[35m     ##       \n");
printf("                                          \033[31m####    ####   \033[33m####        \033[32m####        ##  \033[36m## #####    \033[34m#########    \033[35m    ####      \n");
printf("\n\n\n\n\n\n\n");
}

void Game::nastr(int p)
{
  Turning();
  printf("                                                                 \x1B[37m Ты можешь выбрать уровень сложности игры:\n\n\n\n");
  switch(p)
  {
   case 1:
   { int b=rand() % 6 +1;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                               			Новичок!                          \x1B[37m Если вы плохо играете, мы считаем, что\n\n");
     printf("\x1B[37m");
     printf("                                                              			Любитель!                         \x1B[37m вы переоценили свои возможности!      \n\n");
     printf("                                                               			Профи!                            \x1B[37m Ваш уровень будет изменен автоматически!\n\n");
     break;
   }
   case 2:
   {
     printf("\x1B[37m");
     printf("                                                               			Новичок!			  \x1B[37m Если вы плохо играете, мы считаем, что\n\n");
     int b=rand() % 6 +1; 
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                              			Любитель!                         \x1B[37m вы переоценили свои возможности!      \n\n");
     printf("\x1B[37m");
     printf("                                                               			Профи!                            \x1B[37m Ваш уровень будет изменен автоматически!\n\n");
     break;
   }
   case 3:
   {
     printf("\x1B[37m");
     printf("                                                               			Новичок!                          \x1B[37m Если вы плохо играете, мы считаем, что\n\n");
     printf("                                                              			Любитель!                         \x1B[37m вы переоценили свои возможности!      \n\n");
     int b=rand() % 6 +1;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
     printf("                                                               			Профи!                            \x1B[37m Ваш уровень будет изменен автоматически!\n\n");
     break;
     break;
   }
  }
}

int Figure::go_down()
{
 y_pol++;
 return y_pol;
}

int Figure::go_left()
{
 x_pol--;
 return x_pol;
}

int Figure::go_right()
{
 x_pol++;
 return x_pol;
}

int Figure::go_rotation()
{
 rout++;
 if (rout==5) rout=1;
 return rout;
}
int Figure::go_rotation2 ()
{
 rout--;
 if (rout==0) rout=4;
 return rout;
}
int Figure::chg_colour()
{
 color=rand() % 6 +1;
 return color;
}
int Figure::chg_form()
{
 form=rand() % 7 +1;
 return form;
}
void Figure::chg_fig ()
{
 switch(form)
 {
   case 1: {
      for (int i=0;i<4;i++)
       for(int j=0;j<4;j++)
         as[i][j]=a1[i][j];
        break;
       }
  case 2:{
     switch(rout)
     {
      case 4:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a2[i][j];
        break;}
      case 3:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a3[i][j];
        break; }
      case 2:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a4[i][j];
        break;}
       case 1:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a5[i][j];
        break; }
     }
      break;
        }
    case 3:{
     switch(rout)
     {
      case 4:{
     for (int i=0;i<4;i++)
      for(int j=0;j<4;j++)
         as[i][j]=a6[i][j];
        break; }
      case 3:{
      for (int i=0;i<4;i++)
       for(int j=0;j<4;j++)
         as[i][j]=a7[i][j];
        break; }
      case 2:{
      for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a8[i][j];
        break; }
      case 1:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a9[i][j];
	break; }
     }
      break;
     }
     case 4:{
     switch(rout)
     {
      case 4:{
      for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a10[i][j];
         break;}
      case 3:{
      for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a11[i][j];
        break;}
      case 2:{
     for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a12[i][j];
        break;}
       case 1:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a13[i][j];
        break; }
     }
     break;
     }
     case 5:{
     switch(rout)
     {
      case 4:{
      for (int i=0;i<4;i++)
        for(int j=0;j<4;j++)
         as[i][j]=a14[i][j];
        break;}
      case 3:{
      for (int i=0;i<4;i++)
       for(int j=0;j<4;j++)
         as[i][j]=a15[i][j];
        break;}
      case 2:{
      for (int i=0;i<4;i++)
        for(int j=0;j<4;j++)
         as[i][j]=a16[i][j];
        break; }
       case 1:{
      for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a17[i][j];
        break;}
     }
      break;
     }
     case 6:{
     switch(rout)
     {
      case 4:{
        for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a18[i][j];
        break;}
      case 3:{
         for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a19[i][j];
        break;}
      case 2:{
     for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a20[i][j];
        break; }
       case 1:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a21[i][j];
        break;}
     }
     break;
     }
    case 7:{
     switch(rout)
     {
      case 4:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a22[i][j];
        break; }
      case 3:{
       for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a23[i][j];
        break; }
      case 2:{
        for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a24[i][j];
        break; }
       case 1:{
        for (int i=0;i<4;i++)
         for(int j=0;j<4;j++)
         as[i][j]=a25[i][j];
        break;}
     }
      break;
     }
 }
for (int i=0;i<4;i++)
 for(int j=0;j<4;j++)
  if (as[i][j]!=0) as[i][j]=as[i][j]+color;
}


void Figure::Pointer( int V, int St)
{    if ((St/10)!=3){
     if (V==1)
     { gotoxy(35,5);
     printf("\x1B[49m");
     printf("\x1B[37m");
     printf("Следующая фигура:");}
     if (V==2)
     { gotoxy(58,5);
     printf("\x1B[49m");
     printf("\x1B[37m");
     printf("Следующая фигура:");}
     int b=color;
     switch(b)
     {
      case 1:{ red; break;}
      case 2:{ green ; break;}
      case 3:{ yellow  ; break;}
      case 4:{ blue ; break;}
      case 5:{ magenta; break;}
      case 6:{ cyan ; break;}
     }
 for (int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   { 
   if (as[i][j]!=0)
     {
       if (V==1) 
          {
           gotoxy(38+j*2,7+i);
           printf("  ");}
        if (V==2) 
       {
       gotoxy(58+j*4,7+i*2); 
       printf("    ");
       gotoxy(58+j*4,8+i*2);
       printf("    "); 
       }
     }
   }
  printf("\x1B[49m"); 
  }
}

void Figure::Pointer2(int V, int count[7])
{
  red;
  for (int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   { 
     if (a1[i][j]!=0)
     {
       if (V==1) 
          {
           gotoxy(80+j*2,7+i);
           printf("  ");
           gotoxy(88,8);
           printf("\x1B[49m");
           printf("\x1B[37m");
           std::cout<<"  --- "<<count[1]; red;}
        if (V==2) 
       {
       gotoxy(100+j*2,7+i);
       printf("  ");
       gotoxy(108,8);
       printf("\x1B[49m");
       printf("\x1B[37m");
       std::cout<<"  --- "<<count[1];red; 
       }
     }
     }green;
   for (int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   { 
   if (a5[i][j]!=0)
     {
       if (V==1) 
          {
           gotoxy(80+j*2,10+i);
           printf("  ");
           gotoxy(88,12);
           printf("\x1B[49m");
           printf("\x1B[37m");
           std::cout<<"  --- "<<count[2]; green;}
        if (V==2) 
       {
        gotoxy(100+j*2,10+i); 
        printf("  ");
        gotoxy(108,12);
        printf("\x1B[49m");
        printf("\x1B[37m");
        std::cout<<"  --- "<<count[2]; green;}
     }
     }
   yellow;
   for (int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   { 
   if (a7[i][j]!=0)
     {
       if (V==1) 
          {
           gotoxy(80+j*2,7+i+8);
           printf("  ");          
           gotoxy(88,16);
           printf("\x1B[49m");
           printf("\x1B[37m");
           std::cout<<"  --- "<<count[3]; yellow;}
        if (V==2) 
       {
       gotoxy(100+j*2,7+i+8); 
       printf("  ");
       gotoxy(108,16);
       printf("\x1B[49m");
       printf("\x1B[37m");
       std::cout<<"  --- "<<count[3]; yellow;
       }
     }
     }
   blue;
   for (int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   { 
   if (a10[i][j]!=0)
     {
       if (V==1) 
          {
           gotoxy(80+j*2,7+12+i);
           printf("  ");
           gotoxy(88,20);
           printf("\x1B[49m");
           printf("\x1B[37m");
        std::cout<<"  --- "<<count[4]; blue;}
        if (V==2) 
       {
       gotoxy(100+j*2,7+12+i); 
       printf("  ");
        gotoxy(108,20);
        printf("\x1B[49m");
        printf("\x1B[37m");
        std::cout<<"  --- "<<count[4]; blue;
       }
     }
     }magenta;
   for (int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   { 
   if (a14[i][j]!=0)
     {
       if (V==1) 
          {
           gotoxy(80+j*2,7+i+15);
           printf("  ");
           gotoxy(88,23);
           printf("\x1B[49m");
           printf("\x1B[37m");
        std::cout<<"  --- "<<count[5]; magenta;}
        if (V==2) 
       {
       gotoxy(100+j*2,7+i+15); 
       printf("  ");
       gotoxy(108,23);
       printf("\x1B[49m");
       printf("\x1B[37m");
       std::cout<<"  --- "<<count[5]; magenta;
       }
     }
     }cyan;
   for (int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   { 
   if (a18[i][j]!=0)
     {
       if (V==1) 
          {
           gotoxy(80+j*2,7+18+i);
           printf("  ");
           gotoxy(88,26);
           printf("\x1B[49m");
           printf("\x1B[37m");
        std::cout<<"  --- "<<count[6]; cyan;}
        if (V==2) 
       {
       gotoxy(100+j*2,7+18+i); 
       printf("  ");
       gotoxy(108,26);
       printf("\x1B[49m");
       printf("\x1B[37m");
       std::cout<<"  --- "<<count[6]; cyan;}
     }
     }red;
   for (int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   { 
   if (a22[i][j]!=0)
     {
       if (V==1) 
          {
           gotoxy(80+j*2,7+21+i);
           printf("  ");           
           gotoxy(88,29);
           printf("\x1B[49m");
           printf("\x1B[37m");
        std::cout<<"  --- "<<count[4]; red;}
        if (V==2) 
       {
       gotoxy(100+j*2,7+21+i); 
       printf("  ");
       gotoxy(108,29);
       printf("\x1B[49m");
       printf("\x1B[37m");
       std::cout<<"  --- "<<count[4]; red;}
     }
     }
     printf("\x1B[49m");
     printf("\x1B[37m");
     if (V==1){ gotoxy(80,34);        std::cout<<"Всего:     --- "<<count[0];}
     if (V==2){ gotoxy(100,34);        std::cout<<"Всего:    --- "<<count[0];}
  gotoxy(100,100);     
}


bool Glass::chg_down(int as[4][4], int x,int y)
{
 for (int i=0;i<4;i++)
  for(int j=0;j<4;j++)
   {
     if (as[i][j]!=0 && array[y+i+1][x+j]/10==1)
     {
       return false;
     }
   }  
 return true;
}

 void Glass::gotoxy(int x,int y)
 {
    printf("%c[%d;%df",0x1B,y,x);
 }

bool  Glass::chg_left(int as[4][4], int x,int y)
{
 for (int i=0;i<4;i++)
  for(int j=0;j<4;j++)
   {
     if (as[i][j]/10==2 && array[y+i][x+j-1]/10==1)
     {
       return false;
       break;
     }
   }
 return true;
}


bool  Glass::chg_right(int as[4][4], int x,int y)
{
  for (int i=0;i<4;i++)
  for(int j=0;j<4;j++)
   {
   if ((as[i][j]/10==2 && array[y+i][x+j+1]/10==1))
     {
       return false;
       break;
     }
   }
 return true;
}

bool  Glass::chg_rotation(int as[4][4], int x,int y)
{
 for (int i=0;i<4;i++)
  for(int j=0;j<4;j++)
     {if (as[i][j]/10==2 && array[y+i][x+j]/10==1)
       {
       return false;
       break;
       }
     }
 return true;
}

void  Glass::Painter(int as[4][4], int x,int y)
{
 for (int i=0;i<4;i++)
 for(int j=0;j<4;j++)
  {
  if (as[i][j]/10==2) {array[y+i][x+j]=as[i][j];}
  }
}


void  Glass::Clear()
{
 for (int i=4;i<24;i++)
  for(int j=3;j<23;j++)
  {
  if (array[i][j]/10==2) {array[i][j]=0;}
  }
}

void  Glass::old_fig(int as[4][4],int x,int y)
{
 for (int i=0;i<4;i++)
  for(int j=0;j<4;j++)
  {
  int k=as[i][j]%10;
  if (as[i][j]/10==2) { array[y+i][x+j]=10+k;}
  }
}
void  Glass::chg_line()
{
 y1=0;
 y2=0;
 y3=0;
 y4=0;
int x=0;
for(int i=4;i<24;i++)
 {
   for(int j=3;j<13;j++)
    {
     if (array[i][j]/10==1) x++;
    }
   if (x==10)
   {
    if (y1==0) y1=i;
    else
     if (y2==0) y2=i;
     else
      if (y3==0) y3=i;
      else
       if (y4==0) y4=i;
   }
 x=0;
 }
}
int  Glass::prize_line(int speed)
{
 if (y1!=0) {level=level+100; speed=speed-500;}
 if (y2!=0) {level=level+100; speed=speed-500;}
 if (y3!=0) {level=level+300; speed=speed-500;}
 if (y4!=0) {level=level+400; speed=speed-500;}
 return speed;
}
void  Glass::go_down_glass_1()
{
 int i,j;
 if (y1!=0)
 for (int i=3;i<13;i++)
  {
    array[y1][i]=0;
    line++;
  }
  if (y2!=0)
   for (int i=3;i<13;i++)
  {
    array[y2][i]=0;
    line++;
  }
 if (y3!=0)
   for (int i=3;i<13;i++)
  {
    array[y3][i]=0;
    line++;
  }
  if (y4!=0)
   for (int i=3;i<13;i++)
  {
    array[y4][i]=0;
    line++;
  }
}
void  Glass::go_down_glass_2()
{
 int i,j;
 if (y1!=0)
  for(int j=y1;j>=4;j--)
    for (int i=3;i<13;i++)
  {
    array[j][i]=array[j-1][i];
  }
  if (y2!=0)
    for(int j=y2;j>=4;j--)
    for (int i=3;i<13;i++)
  {
    array[j][i]=array[j-1][i];
  }
  if (y3!=0)
   for(int j=y3;j>=4;j--)
    for (int i=3;i<13;i++)
  {
    array[j][i]=array[j-1][i];
  }
  if (y4!=0)
    for(int j=y4;j>=4;j--)
    for (int i=3;i<13;i++)
  {
    array[j][i]=array[j-1][i];
  }
}

void Glass::Pointer(int f, int St)
{
 int i;
 if (V==1){
 gotoxy(6,6);
 printf("\x1B[47m");
 for (i=0;i<(12);i++) {printf("  ");}
 gotoxy(6,27);
 for (i=0;i<(12);i++) {printf("  ");} 
 for (i=0;i<(21);i++) 
 {
  gotoxy(6,7+i);
  printf("  ");
 }
  for (i=0;i<(21);i++) 
 {
  gotoxy(28,7+i);
  printf("  ");
 } 
  for (int i=0;i<20;i++)
   for(int j=0;j<10;j++)
    {
     int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red; break;}
      case 2:{ green ; break;}
      case 3:{ yellow  ; break;}
      case 4:{ blue ; break;}
      case 5:{ magenta; break;}
      case 6:{ cyan ; break;}
     }
     if (array[i+4][j+3]!=0)
      {
       if (array[i+4][j+3]/10!=3)
       {
       if (f==1){
       if (y1==(i+4) || y2==(i+4) || y3==(i+4) || y4==(i+4)) {     
       int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red3; break;}
      case 2:{ green3 ; break;}
      case 3:{ yellow3  ; break;}
      case 4:{ blue3 ; break;}
      case 5:{ magenta3; break;}
      case 6:{ cyan3 ; break;}
     }}
       gotoxy(8+j*2,7+i);
       printf("  "); 
     }
       gotoxy(8+j*2,7+i); 
       printf("  ");
       }
       else{
       if (St/10==1) {
       printf("\x1B[49m");
       int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     } 
       gotoxy(8+j*2,7+i); 
       printf("##");
         }}
      }    
    } 
   printf("\x1B[49m");
   printf("\x1B[37m");
   gotoxy(10,50);    
  printf("	Если ты хочешь выйти нажми -- q ; если ты хочешь сделать паузу нажми -- p ;\n\n\n\n ");
}
 if (V==2){ 
 gotoxy(6,6);
 printf("\x1B[47m");
 for (i=0;i<(11);i++) {printf("    ");}
 gotoxy(6,47);
 for (i=0;i<(11);i++) {printf("    ");}
 for (i=0;i<(20*2);i++) 
 {
  gotoxy(6,7+i);
  printf("  ");
 }
  for (i=0;i<(20*2);i++) 
 {
  gotoxy(48,7+i);
  printf("  ");
 }
  for (int i=0;i<20;i++)
   for(int j=0;j<10;j++)
    {
    int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red; break;}
      case 2:{ green ; break;}
      case 3:{ yellow  ; break;}
      case 4:{ blue ; break;}
      case 5:{ magenta; break;}
      case 6:{ cyan ; break;}
     }
     if (array[i+4][j+3]!=0)
      {
      if (array[i+4][j+3]/10!=3)
       {
       if (f==1){
       if (y1==i+4 || y2==i+4 || y3==i+4 || y4==i+4) {
       int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red3; break;}
      case 2:{ green3 ; break;}
      case 3:{ yellow3  ; break;}
      case 4:{ blue3 ; break;}
      case 5:{ magenta3; break;}
      case 6:{ cyan3 ; break;}
     }
      }
      }
       gotoxy(8+j*4,7+i*2); 
       printf("    ");
       gotoxy(8+j*4,8+i*2);
       printf("    "); 
       }
       else{
       if (St/10==1){
       printf("\x1B[49m");
           int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
       gotoxy(8+j*4,7+i*2); 
       printf("####");
       gotoxy(8+j*4,8+i*2);
       printf("####");
        }} 
      }    
    }
   printf("\x1B[37m");
    printf("\x1B[49m");
   gotoxy(10,50); 
   printf("	Если ты хочешь выйти нажми -- q ; если ты хочешь сделать паузу нажми -- p ;\n\n\n\n ");
}
 printf("\x1B[49m"); 
}

int Glass::proec_figure(int x,int y, int as[4][4], int N) 
{
 N=0;
bool    S=chg_down(as,x,y);
while (S!=0)
   {
    y++;
    N++;
   S=chg_down(as,x,y);
 }
 for (int i=0;i<4;i++)
  for(int j=0;j<4;j++)
  {
  int k=as[i][j]%10;
  if (as[i][j]/10==2) array[y+i][x+j]=30+k;
  }
 return N;
}
void  Glass::proec_figureN()
{
  for (int i=0;i<26;i++){
   for(int j=0;j<15;j++) 
     if (array[i][j]/10==3)
      array[i][j]=0;
     }
}
int Glass::proec_figureN2(int N, int y)
{
  for (int i=0;i<26;i++){
   for(int j=0;j<15;j++) 
     if (array[i][j]/10==3)
        {
           int k=array[i][j]%10;
           array[i][j]=10+k;
        }
     }
 y=y+N-1;
 return y;  
}
bool Glass::new_figure()
{
 bool z=1;
 for(i=3;i<13;i++)
  {
    if (array[4][i]!=0){z=0; break;}
  }
 return z;
}

void Glass::Pointer2(char ch)
{
 int i;
 if (V==1){
 gotoxy(6,6);
 printf("\x1B[47m");
 for (i=0;i<(12);i++) {printf("  ");}
 gotoxy(6,27);
 for (i=0;i<(12);i++) {printf("  ");} 
 for (i=0;i<(21);i++) 
 {
  gotoxy(6,7+i);
  printf("  ");
 }
  for (i=0;i<(21);i++) 
 {
  gotoxy(28,7+i);
  printf("  ");
 } 
  for (int i=0;i<20;i++)
   for(int j=0;j<10;j++)
    {
     int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red; break;}

      case 2:{ green ; break;}
      case 3:{ yellow  ; break;}
      case 4:{ blue ; break;}
      case 5:{ magenta; break;}
      case 6:{ cyan ; break;}
     }
     if (array[i+4][j+3]!=0)
      {
       if (array[i+4][j+3]/10!=3)
       {
       if (y1==(i+4) || y2==(i+4) || y3==(i+4) || y4==(i+4)) {     
       int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}    
     } printf("\x1B[49m");
       gotoxy(8+j*2,7+i);
       std::cout<<ch;
       gotoxy(9+j*2,7+i);
       std::cout<<ch; 
       } else
         {
          gotoxy(8+j*2,7+i);
          printf("  ");
           }
         }
       else{
       printf("\x1B[49m");
       int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     } 
       gotoxy(8+j*2,7+i); 
       printf("##");
         }
      }    
    } 
}
 if (V==2){ 
 gotoxy(6,6);
 printf("\x1B[47m");
 for (i=0;i<(11);i++) {printf("    ");}
 gotoxy(6,47);
 for (i=0;i<(11);i++) {printf("    ");}
 for (i=0;i<(20*2);i++) 
 {
  gotoxy(6,7+i);
  printf("  ");
 }
  for (i=0;i<(20*2);i++) 
 {
  gotoxy(48,7+i);
  printf("  ");
 }
  for (int i=0;i<20;i++)
   for(int j=0;j<10;j++)
    {
    int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red; break;}
      case 2:{ green ; break;}
      case 3:{ yellow  ; break;}
      case 4:{ blue ; break;}
      case 5:{ magenta; break;}
      case 6:{ cyan ; break;}
     }
     if (array[i+4][j+3]!=0)
      {
      if (array[i+4][j+3]/10!=3)
       {
       if (y1==i+4 || y2==i+4 || y3==i+4 || y4==i+4) {
       int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1 ; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     } printf("\x1B[49m");
       gotoxy(8+j*4,7+i*2); 
       std::cout<<ch; 
       gotoxy(9+j*4,7+i*2);
       printf(" ");
       gotoxy(10+j*4,7+i*2);
       std::cout<<ch; 
       gotoxy(11+j*4,7+i*2);
       printf(" ");
       gotoxy(8+j*4,8+i*2); 
       std::cout<<ch; 
       gotoxy(9+j*4,8+i*2);
       printf(" ");
       gotoxy(10+j*4,8+i*2);
       std::cout<<ch; 
       gotoxy(11+j*4,8+i*2);
       printf(" "); 
       }  else 
         {       
          gotoxy(8+j*4,7+i*2);
          printf("    ");
          gotoxy(8+j*4,8+i*2);
          printf("    "); 
         }}
       else{
       printf("\x1B[49m");
           int b=array[i+4][j+3]%10;
     switch(b)
     {
      case 1:{ red1; break;}
      case 2:{ green1 ; break;}
      case 3:{ yellow1  ; break;}
      case 4:{ blue1; break;}
      case 5:{ magenta1; break;}
      case 6:{ cyan1 ; break;}
     }
       gotoxy(8+j*4,7+i*2); 
       printf("####");
       gotoxy(8+j*4,8+i*2);
       printf("####");
        } 
      }    
    }
 }
 gotoxy(8,49);
 printf("\x1B[49m"); 
 printf("	Если ты хочешь выйти нажми -- q ; если ты хочешь сделать паузу нажми -- p ;\n\n\n\n ");
 printf("\n\n");
}

void Glass::Information( int speed, int& start)
{ int b;
  speed=speed/100;
  if (V==1)
  {
   printf("\x1B[49m");
   printf("\x1B[37m");
   gotoxy(55,5);
   std::cout<<"кол-во линий:   "<<line/10;
   gotoxy(55,7);
   std::cout<<"Очки:	      "<<level;
   gotoxy(55,9);
   std::cout<<"Скорость:	  "<<speed;
   gotoxy(35,15);
   printf("Помощь:");
   gotoxy(35,17);
   printf("d:	влево");
   gotoxy(35,19);
   printf("a:	вправо");
   gotoxy(35,21);
   printf("s:	резко вниз");
   gotoxy(35,23);
   printf("w:	поворот");
  }
    if (V==2)
  {
   printf("\x1B[49m");
   printf("\x1B[37m");
   gotoxy(78,5);
   std::cout<<"кол-во линий:  "<<line/10;
   gotoxy(78,7);
   std::cout<<"Очки:	     "<<level;
   gotoxy(78,9);
   std::cout<<"Скорость:	 "<<speed;
   gotoxy(58,15);
   printf("Помощь:");
   gotoxy(58,17);
   printf("d:	влево");
   gotoxy(58,19);
   printf("a:	вправо");
   gotoxy(58,21);
   printf("s:	резко вниз");
   gotoxy(58,23);
   printf("w:	поворот");
  }
   if (V==1)
     { gotoxy(80,5);
     printf("\x1B[49m");
     printf("\x1B[37m");
     printf("Статистика:");}
     if (V==2)
     { gotoxy(100,5);
     printf("\x1B[49m");
     printf("\x1B[37m");
     printf("Статистика:");}
};

}
