#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

#define red1 printf("\033[31m")
#define green1 printf("\033[32m")
#define yellow1  printf("\033[33m")
#define blue1 printf("\033[34m")
#define magenta1 printf("\033[35m")
#define cyan1 printf("\033[36m")

using namespace mylib;

 int main()
 {
  srand(time(NULL)); 
  Game game;
  game.Gamemenu(); 
  return 0;
 }


