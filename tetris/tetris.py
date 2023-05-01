import curses
import os
import random
import time
import sys
import string

def end(win):
     win.clear()
     win.refresh()
     curses.echo()
     curses.nocbreak()
     win.nodelay(False)
     win.keypad(False) 
     curses.curs_set(1)
     curses.endwin()

class Figure:
    a1=[
        [0,20,20,0],
        [0,20,20,0],
        [0,0,0,0],
        [0,0,0,0],
      ]
    a5=[
        [0,0,20,0],
        [0,0,20,0],
        [0,0,20,0],
        [0,0,20,0],
    ]
    a4=[
        [0,0,0,0],
        [0,0,0,0],
        [20,20,20,20],
        [0,0,0,0],
    ]
    a3=[
             [0,20,0,0],
             [0,20,0,0],
             [0,20,0,0],
             [0,20,0,0],
    ]
    a2=[
            [0,0,0,0],
            [20,20,20,20],
            [0,0,0,0],
            [0,0,0,0],
    ]
    a6=[
            [20,0,0,0],
            [20,20,20,0],
            [0,0,0,0],
            [0,0,0,0],
    ]
    a7=[
            [0,0,20,20],
            [0,0,20,0],
            [0,0,20,0],
            [0,0,0,0],
    ]
    a8=[
            [0,20,20,20],
            [0,0,0,20],
            [0,0,0,0],
            [0,0,0,0],
    ]
    a9=[
            [0,0,0,0],
            [0,20,0,0],
            [0,20,0,0],
            [20,20,0,0],
    ]
    a10=[
            [0,20,20,0],
            [20,20,0,0],
            [0,0,0,0],
            [0,0,0,0],
     ]
    a11=[
            [0,0,20,0],
            [0,0,20,20],
            [0,0,0,20],
            [0,0,0,0],
     ]
    a12=[
            [0,0,0,0],
            [0,0,0,0],
            [0,20,20,0],
            [20,20,0,0],
     ]
    a13=[
            [20,0,0,0],
            [20,20,0,0],
            [0,20,0,0],
            [0,0,0,0],
     ]
    a14=[
            [0,20,0,0],
            [20,20,20,0],
            [0,0,0,0],
            [0,0,0,0],
     ]
    a15=[
            [0,0,20,0],
            [0,0,20,20],
            [0,0,20,0],
            [0,0,0,0],
     ]
    a16=[
            [0,0,0,0],
            [0,0,0,0],
            [20,20,20,0],
            [0,20,0,0],
    ]
    a17=[
            [0,20,0,0],
            [20,20,0,0],
            [0,20,0,0],
            [0,0,0,0],
     ]
    a18=[
            [20,20,0,0],
            [0,20,20,0],
            [0,0,0,0],
            [0,0,0,0],
     ]
    a19=[
            [0,0,0,20],
            [0,0,20,20],
            [0,0,20,0],
            [0,0,0,0],
     ]
    a20=[
            [0,0,0,0],
            [0,0,0,0],
            [20,20,0,0],
            [0,20,20,0],
     ]
    a21=[
            [0,20,0,0],
            [20,20,0,0],
            [20,0,0,0],
            [0,0,0,0],
     ]
    a22=[
            [0,0,0,20],
            [0,20,20,20],
            [0,0,0,0],
            [0,0,0,0],
     ]
    a23=[
            [20,20,0,0],
            [0,20,0,0],
            [0,20,0,0],
            [0,0,0,0],
     ]
    a24=[
            [0,0,0,20],
            [0,20,20,20],
            [0,0,0,0],
            [0,0,0,0],
     ]
    a25=[
            [0,0,0,0],
            [0,0,20,0],
            [0,0,20,0],
            [0,0,20,20],
     ]
    z=0
    x_pol=0
    y_pol=0
    count=[0,0,0,0,0,0,0,0]
    speed=0

    def __init__(self):
        self.as0=[
      [0,0,0,0],
      [0,0,0,0],
      [0,0,0,0],
      [0,0,0,0], 
    ]
        self.color = random.randint(1, 6)
        self.form = random.randint(1, 7)
        self.rout = 1
        if self.form==1:
            for i in range(4):
                for j in range(4):
                    self.as0[i][j]=self.a1[i][j] 
        if self.form==2:
            for i in range(4):
                for j in range(4):
                    self.as0[i][j]=self.a5[i][j]
        if self.form==3:     
            for i in range(4):
                for j in range(4):
                    self.as0[i][j]=self.a9[i][j] 
        if self.form==4:     
            for i in range(4):
                for j in range(4):
                    self.as0[i][j]=self.a13[i][j]     
        if self.form==5:
            for i in range(4):
                for j in range(4):
                    self.as0[i][j]=self.a17[i][j] 
        if self.form==6:
            for i in range(4):
                for j in range(4):
                    self.as0[i][j]=self.a21[i][j] 
            if self.form==7:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a25[i][j] 
        for i in range(4):
          for j in range(4):
              if self.as0[i][j]!=0:
                  self.as0[i][j]=self.as0[i][j]+self.color
    
    def go_rotation2 (self):
        self.rout=self.rout-1
        if self.rout==0:
            self.rout=4

    def go_rotation(self):
        self.rout=self.rout+1
        if self.rout==5:
            self.rout=1

    def go_down(self):
        self.y_pol=self.y_pol+1

    def go_right(self):
        self.x_pol=self.x_pol+1

    def go_left(self):
        self.x_pol=self.x_pol-1

    def Pointer2(self,V,win): 
        for i in range(4):
            for j in range(4):
                if (self.a1[i][j]!=0):
                    if (V==1): 
                        win.addstr(7+i, 100+j*2, "  ", curses.color_pair(9))
                        win.addstr(8, 108, "  --- ", curses.color_pair(7))
                        win.addstr(8, 114, str(self.count[1]), curses.color_pair(7))
                    if (V==2):
                        win.addstr(7+i, 120+j*2, "  ", curses.color_pair(9))
                        win.addstr(8, 128, "  --- ", curses.color_pair(7))
                        win.addstr(8, 134, str(self.count[1]), curses.color_pair(7))   
        for i in range(4):
            for j in range(4):
                if (self.a5[i][j]!=0):
                    if (V==1): 
                        win.addstr(10+i, 100+j*2, "  ", curses.color_pair(10))
                        win.addstr(12, 108, "  --- ", curses.color_pair(7))
                        win.addstr(12, 114, str(self.count[2]), curses.color_pair(7))
                    if (V==2):
                        win.addstr(10+i, 120+j*2, "  ", curses.color_pair(10))
                        win.addstr(12, 128, "  --- ", curses.color_pair(7))
                        win.addstr(12, 134, str(self.count[2]), curses.color_pair(7))  
        for i in range(4):
            for j in range(4):
                if (self.a7[i][j]!=0):
                    if (V==1): 
                        win.addstr(15+i, 100+j*2, "  ", curses.color_pair(11))
                        win.addstr(16, 108, "  --- ", curses.color_pair(7))
                        win.addstr(16, 114, str(self.count[3]), curses.color_pair(7))
                    if (V==2):
                        win.addstr(15+i, 120+j*2, "  ", curses.color_pair(11))
                        win.addstr(16, 128, "  --- ", curses.color_pair(7))
                        win.addstr(16, 134, str(self.count[3]), curses.color_pair(7))  
        for i in range(4):
            for j in range(4):
                if (self.a10[i][j]!=0):
                    if (V==1): 
                        win.addstr(19+i, 100+j*2, "  ", curses.color_pair(12))
                        win.addstr(20, 108, "  --- ", curses.color_pair(7))
                        win.addstr(20, 114, str(self.count[4]), curses.color_pair(7))
                    if (V==2):
                        win.addstr(19+i, 120+j*2, "  ", curses.color_pair(12))
                        win.addstr(20, 128, "  --- ", curses.color_pair(7))
                        win.addstr(20, 134, str(self.count[4]), curses.color_pair(7))  
        for i in range(4):
            for j in range(4):
                if (self.a14[i][j]!=0):
                    if (V==1): 
                        win.addstr(22+i,100+j*2, "  ", curses.color_pair(13))
                        win.addstr(23, 108, "  --- ", curses.color_pair(7))
                        win.addstr(23, 114, str(self.count[5]), curses.color_pair(7))
                    if (V==2):
                        win.addstr(22+i, 120+j*2, "  ", curses.color_pair(13))
                        win.addstr(23, 128, "  --- ", curses.color_pair(7))
                        win.addstr(23, 134, str(self.count[5]), curses.color_pair(7))  
        for i in range(4):
            for j in range(4):
                if (self.a18[i][j]!=0):
                    if (V==1): 
                        win.addstr(25+i, 100+j*2, "  ", curses.color_pair(14))
                        win.addstr(26, 108, "  --- ", curses.color_pair(7))
                        win.addstr(26, 114, str(self.count[5]), curses.color_pair(7))
                    if (V==2):
                        win.addstr(25+i, 120+j*2, "  ", curses.color_pair(14))
                        win.addstr(26, 128, "  --- ", curses.color_pair(7))
                        win.addstr(26, 134, str(self.count[5]), curses.color_pair(7)) 
        for i in range(4):
            for j in range(4):
                if (self.a22[i][j]!=0):
                    if (V==1): 
                        win.addstr(28+i, 100+j*2, "  ", curses.color_pair(9))
                        win.addstr(29, 108, "  --- ", curses.color_pair(7))
                        win.addstr(29, 114, str(self.count[7]), curses.color_pair(7))
                    if (V==2):
                        win.addstr(28+i,120+j*2, "  ", curses.color_pair(9))
                        win.addstr(29, 128, "  --- ", curses.color_pair(7))
                        win.addstr(29, 134, str(self.count[7]), curses.color_pair(7)) 
        if (V==1):
            win.addstr(33, 100, "Всего:", curses.color_pair(7))
            win.addstr(33, 108, "  --- ", curses.color_pair(7))
            win.addstr(33, 114, str(self.count[0]), curses.color_pair(7))
        if (V==2):
            win.addstr(33, 120, "Всего:	--- ", curses.color_pair(7))
            win.addstr(33, 128, "  --- ", curses.color_pair(7))
            win.addstr(33, 134, str(self.count[0]), curses.color_pair(7)) 
        win.refresh()

    def chg_fig (self):
        if self.form==1:
            for i in range(4):
                for j in range(4):
                    self.as0[i][j]=self.a1[i][j]
        if self.form==2:
            if self.rout==4:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a2[i][j]
            if self.rout==3:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a3[i][j] 
            if self.rout==2:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a4[i][j]      
            if self.rout==1:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a5[i][j] 
        if self.form==3:
            if self.rout==4:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a6[i][j]
            if self.rout==3:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a7[i][j] 
            if self.rout==2:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a8[i][j]      
            if self.rout==1:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a9[i][j] 
        if self.form==4:
            if self.rout==4:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a10[i][j]
            if self.rout==3:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a11[i][j] 
            if self.rout==2:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a12[i][j]      
            if self.rout==1:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a13[i][j]     
        if self.form==5:
            if self.rout==4:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a14[i][j]
            if self.rout==3:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a15[i][j] 
            if self.rout==2:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a16[i][j]      
            if self.rout==1:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a17[i][j] 
        if self.form==6:
            if self.rout==4:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a18[i][j]
            if self.rout==3:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a19[i][j] 
            if self.rout==2:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a20[i][j]      
            if self.rout==1:
                for i in range(4):
                    for j in range(4):
                        self.as0[i][j]=self.a21[i][j] 
        if self.form==7:
                if self.rout==4:
                    for i in range(4):
                        for j in range(4):
                            self.as0[i][j]=self.a22[i][j]
                if self.rout==3:
                    for i in range(4):
                        for j in range(4):
                            self.as0[i][j]=self.a23[i][j] 
                if self.rout==2:
                    for i in range(4):
                        for j in range(4):
                            self.as0[i][j]=self.a24[i][j]      
                if self.rout==1:
                    for i in range(4):
                        for j in range(4):
                            self.as0[i][j]=self.a25[i][j] 
        for i in range(4):
          for j in range(4):
              if self.as0[i][j]!=0:
                  self.as0[i][j]=self.as0[i][j]+self.color

    def Pointer(self,V, St,win):
        if ((St//10)!=3):
            if (V==1):
                win.addstr(5, 35, "Следующая фигура:", curses.color_pair(7))
            if (V==2):
                win.addstr(5, 58, "Следующая фигура:", curses.color_pair(7))
            for i in range(4):
                for j in range(4):
                    if (self.as0[i][j]!=0):
                        if (V==1):
                            win.addstr(7+i, 38+j*2, "  ", curses.color_pair(8+self.color)) 
                        if (V==2): 
                            win.addstr(7+i*2, 58+j*4, "    ", curses.color_pair(8+self.color)) 
                            win.addstr(8+i*2, 58+j*4, "    ", curses.color_pair(8+self.color)) 
        win.refresh()

class Glass: 
    l=0
    V=2
    y1=0
    y2=0
    y3=0
    y4=0
    line=0
    level=0
    array = [0] * 26 

    def proec_figureN2(self, N, y):
        for i in range(0, 26, 1):
            for j in range(0, 15, 1): 
                if (self.array[i][j]//10==3):
                    k=self.array[i][j]%10
                    self.array[i][j]=10+k
        y=y+N-1
        return y

    def new_figure(self):
        z=1
        for i in range(3, 13, 1):
            if (self.array[4][i]!=0):
                z=0
        return z

    def chg_rotation(self,as0,x,y):
        for i in range(4):
            for j in range(4):
                if (as0[i][j]//10==2):
                    if(self.array[y+i][x+j]//10==1):
                        return False
        return True

    def chg_down(self, as0,x,y):
        for i in range(4):
            for j in range(4):
                if (as0[i][j]!=0):
                    if (self.array[y+i+1][x+j]//10==1):
                        return False
        return True

    def chg_left(self, as0,x,y):
        for i in range(4):
            for j in range(4):
                if (as0[i][j]//10==2):
                    if(self.array[y+i][x+j-1]//10==1):
                        return False
        return True

    def chg_right(self,as0,x,y):
        for i in range(4):
            for j in range(4):
                if (as0[i][j]//10==2):
                    if(self.array[y+i][x+j+1]//10==1):
                        return False
        return True
  
    def Clear(self):
        for i in range(0, 26, 1):
            for j in range(0, 15, 1):
                if (self.array[i][j]//10==2):
                    self.array[i][j]=0 

    def chg_line(self):
        self.y1=0
        self.y2=0
        self.y3=0
        self.y4=0
        x=0
        for i in range(4, 24, 1):
            for j in range(3, 13, 1):
                if self.array[i][j]//10==1:
                    x=x+1
            if x==10:
                if self.y1==0:
                    self.y1=i
                else:
                    if self.y2==0:
                        self.y2=i
                    else:
                        if self.y3==0:
                            self.y3=i
                        else:
                            if self.y4==0:
                                self.y4=i
            x=0

    def prize_line(self, speed):
        if self.y1!=0:
            self.level=self.level+100
            speed=speed-0.02
        if self.y2!=0: 
            self.level=self.level+300
            speed=speed-0.02
        if self.y3!=0: 
            self.level=self.level+400
            speed=speed-0.02
        if self.y4!=0: 
            self.level=self.level+500
            speed=speed-0.02
        return speed

    def go_down_glass_1(self):
        if (self.y1!=0):
            for i in range(3, 13, 1):
                self.array[self.y1][i]=0
                self.line=self.line+1
        if (self.y2!=0):
            for i in range(3, 13, 1):
                self.array[self.y1][i]=0
                self.line=self.line+1   
        if (self.y3!=0):
            for i in range(3, 13, 1):
                self.array[self.y3][i]=0
                self.line=self.line+1
        if (self.y4!=0):
            for i in range(3, 13, 1):
                self.array[self.y3][i]=0
                self.line=self.line+1

    def go_down_glass_2(self):
        if self.y1!=0:
            for i in range(self.y1, 4, -1):
                for j in range(3, 13, 1):
                    self.array[i][j]=self.array[i-1][j]
        if self.y2!=0:
            for i in range(self.y2, 4, -1):
                for j in range(3, 13, 1):
                    self.array[i][j]=self.array[i-1][j]
        if self.y3!=0:
            for i in range(self.y3, 4, -1):
                for j in range(3, 13, 1):
                    self.array[i][j]=self.array[i-1][j]
        if self.y4!=0:
            for i in range(self.y4, 4, -1):
                for j in range(3, 13, 1):
                    self.array[i][j]=self.array[i-1][j]
       
    def Pointer(self, f, St, ch, endline,win,speed):#1-вывести символ;f-мигание
        if (self.V==1):
            win.addstr(5, 75, "кол-во линий: ", curses.color_pair(7))
            win.addstr(7, 75, str(self.line//10), curses.color_pair(7))
            win.addstr(9, 75, "Очки: ", curses.color_pair(7))            
            win.addstr(11,75, str(self.line*10), curses.color_pair(7))
            win.addstr(13,75, "Cкорость: ", curses.color_pair(7))
            win.addstr(15,75, str(round(speed,2)), curses.color_pair(7))
            win.addstr(19,55, "Помощь: ", curses.color_pair(7))
            win.addstr(21,55,"d:	влево", curses.color_pair(7))
            win.addstr(23,55,"a:	вправо", curses.color_pair(7))
            win.addstr(25,55,"s:	резко вниз", curses.color_pair(7))
            win.addstr(27,55,"w:	поворот", curses.color_pair(7))
            win.addstr(5,100,"Статистика:", curses.color_pair(7))
        if (self.V==2):
            win.addstr(5, 100, "кол-во линий: ", curses.color_pair(7))
            win.addstr(7, 100, str(self.line//10), curses.color_pair(7))
            win.addstr(9, 100, "Очки: ", curses.color_pair(7))            
            win.addstr(11, 100, str(self.line*10), curses.color_pair(7))
            win.addstr(13, 100, "Cкорость: ", curses.color_pair(7))
            win.addstr(15,100, str(round(speed,2)), curses.color_pair(7))
            win.addstr(19,80, "Помощь: ", curses.color_pair(7))
            win.addstr(21,80, "d:	влево", curses.color_pair(7))
            win.addstr(23,80, "a:	вправо", curses.color_pair(7))
            win.addstr(25,80, "s:	резко вниз", curses.color_pair(7))
            win.addstr(27,80, "w:	поворот", curses.color_pair(7))
            win.addstr(5,120,"Статистика:", curses.color_pair(7))
        if self.V==1:
            for i in range(0, 12, 1):
                win.addstr(6,6+i*2,"  ", curses.color_pair(8))
            for i in range(0, 12, 1):
                win.addstr(27,6+i*2,"  ", curses.color_pair(8)) 
            for i in range(0, 21, 1):
                win.addstr(7+i,6,"  ", curses.color_pair(8)) 
            for i in range(0, 21, 1):
                win.addstr(6+i,28,"  ", curses.color_pair(8)) 
            for i in range(0, 20, 1):
                for j in range(0, 10, 1):   
                    if (self.array[i+4][j+3]!=0):
                        b=self.array[i+4][j+3]%10
                        if (self.array[i+4][j+3]//10!=3):
                            if (self.y1==(i+4) or self.y2==(i+4) or self.y3==(i+4) or self.y4==(i+4)):     
                                if (endline==1):
                                    win.addstr(7+i,8+j*2,ch, curses.color_pair(b))
                                    win.addstr(7+i,9+j*2,ch, curses.color_pair(b))       
                            else: 
                                b=b+8
                                win.addstr(7+i,8+j*2,"  ", curses.color_pair(b)) 
                        else:
                            if (St//10==1):
                                win.addstr(7+i,8+j*2,"##", curses.color_pair(b)) 
            win.addstr(40,10,"Если ты хочешь выйти нажми -- q ; если ты хочешь сделать паузу нажми -- p ;", curses.color_pair(7))
        if (self.V==2):
            for i in range(0, 11, 1):
                win.addstr(1,6+i*4,"    ", curses.color_pair(8))
            for i in range(0, 11, 1):
                win.addstr(42,6+i*4,"    ", curses.color_pair(8)) 
            for i in range(0, 42, 1):
                win.addstr(1+i,4,"    ", curses.color_pair(8)) 
            for i in range(0, 40, 1):
                win.addstr(2+i,48,"    ", curses.color_pair(8)) 
            win.addstr(1,50,"  ", curses.color_pair(8))
            win.addstr(42,50,"  ", curses.color_pair(8))
            for i in range(0, 20, 1):
                for j in range(0, 10, 1):   
                     if (self.array[i+4][j+3]!=0):
                         b=self.array[i+4][j+3]%10
                         if (self.array[i+4][j+3]//10!=3):
                             if (self.y1==(i+4) or self.y2==(i+4) or self.y3==(i+4) or self.y4==(i+4)):     
                                 if (endline==1):
                                     win.addstr(2+i*2,8+j*4, ch, curses.color_pair(b))
                                     win.addstr(2+i*2,9+j*4, ch, curses.color_pair(b))
                                     win.addstr(2+i*2,10+j*4,ch, curses.color_pair(b))
                                     win.addstr(2+i*2,11+j*4,ch, curses.color_pair(b))
                                     win.addstr(3+i*2,8+j*4, ch, curses.color_pair(b))
                                     win.addstr(3+i*2,9+j*4, ch, curses.color_pair(b))
                                     win.addstr(3+i*2,10+j*4,ch, curses.color_pair(b))
                                     win.addstr(3+i*2,11+j*4,ch, curses.color_pair(b))         
                             else: 
                                 b=b+8
                                 win.addstr(2+i*2,8+j*4,"    ", curses.color_pair(b)) 
                                 win.addstr(3+i*2,8+j*4,"    ", curses.color_pair(b))                
                         else:
                             if (St//10==1):
                                 win.addstr(2+i*2,8+j*4,"####", curses.color_pair(b)) 
                                 win.addstr(3+i*2,8+j*4,"####", curses.color_pair(b)) 
            win.addstr(43,10,"Если ты хочешь выйти нажми -- q ; если ты хочешь сделать паузу нажми -- p ;", curses.color_pair(7))
        win.refresh()

    def proec_figure(self, x, y, as0, N):
        N=0
        self.S=self.chg_down(as0,x,y)
        while (self.S!=0):
            y=y+1
            N=N+1
            self.S=self.chg_down(as0,x,y)
        for i in range(0, 4, 1):
            for j in range(0, 4, 1):
                k=as0[i][j]%10
                if (as0[i][j]//10==2):
                    self.array[y+i][x+j]=30+k
        return N

    def proec_figureN(self):
        for i in range(0, 26, 1):
            for j in range(0, 15, 1): 
                if (self.array[i][j]//10==3):
                    self.array[i][j]=0

    def old_fig(self,as0,x,y):
        for i in range(4):
            for j in range(4):
                k=as0[i][j]%10
                if (as0[i][j]//10==2): 
                    self.array[y+i][x+j]=10+k

    def Painter(self,as0,x,y):
        for i in range(4):
            for j in range(4):
                if (as0[i][j]//10==2):
                    self.array[y+i][x+j]=as0[i][j]
                    

class Game:
    start=0
    def Turning(win):
        win.addstr(4,  30, "                                                                                    ##   ##      ", curses.color_pair(1))
        win.addstr(5,  30, "                                                                                     #####       ", curses.color_pair(2))
        win.addstr(6,  30, "##      ##     #####      ##########    ##########    ##########     ########    ##        ###    ####   ###    ##         ### ", curses.color_pair(3))
        win.addstr(7,  30, "##      ##     ## ##      ##       #    #   ##   #    ##      ##    ##      ##   ##     ### ##    ##   ###      ##      ### ## ", curses.color_pair(4))
        win.addstr(8,  30, "##      ##    ##   ##     ##                ##        ##      ##    ##      ##   ##    ###  ##    ## ###        ##    ###   ## ", curses.color_pair(5))
        win.addstr(9,  30, "##########    #######     ##                ##        ##########    ##      ##   ##   ###   ##    ###           ##   ###    ## ", curses.color_pair(6))
        win.addstr(10, 30, "##      ##   ##     ##    ##                ##        ##            ##      ##   ##  ###    ##    ## ###        ##  ###     ## ", curses.color_pair(1))
        win.addstr(11, 30, "##      ##  ##       ##   ##       #        ##        ##            ##      ##   ## ###     ##    ##   ###      ## ###      ## ", curses.color_pair(2))
        win.addstr(12, 30, "##      ##  ##       ##   ##########       ####      ####            ########    ###        ##   ####   ###     ###         ## ", curses.color_pair(3))
        win.refresh()

    def Came_Title(win):
        win.addstr(6,  40, " ##########    ##########   ##########   ##########   ##        ###   ##########           ", curses.color_pair(1))
        win.addstr(7,  40, " #   ##   #    ##       #   #   ##   #   ##      ##   ##     ### ##   ##       #           ", curses.color_pair(2))
        win.addstr(8,  40, "     ##        ##               ##       ##      ##   ##    ###  ##   ##                   ", curses.color_pair(3))
        win.addstr(9,  40, "     ##        #########        ##       ##########   ##   ###   ##   ##                   ", curses.color_pair(4))
        win.addstr(10, 40, "     ##        ##               ##       ##           ##  ###    ##   ##                   ", curses.color_pair(5))
        win.addstr(11, 40, "     ##        ##       #       ##       ##           ## ###     ##   ##       #           ", curses.color_pair(6))
        win.addstr(12, 40, "    ####       ##########      ####     ####          ###        ##   ##########           ", curses.color_pair(7))
        win.refresh()

    def Hellow(win):
        win.addstr(6,  40, " ##########    #########    ##         ###  ########     #########    ##########   ", curses.color_pair(1))
        win.addstr(7,  40, " ##      ##    ##     ##    ##      ### ##  ##      #    ##      #    #   ##   #   ", curses.color_pair(2))
        win.addstr(8,  40, " ##      ##    ##     ##    ##    ###   ##  ##      #    ##               ##       ", curses.color_pair(3))
        win.addstr(9,  40, " ##      ##    #########    ##   ###    ##  ########     #######          ##       ", curses.color_pair(4))
        win.addstr(10, 40, " ##      ##    ##           ##  ###     ##  ##      #    ##               ##       ", curses.color_pair(5))
        win.addstr(11, 40, " ##      ##    ##           ## ###      ##  ##      #    ##      #        ##       ", curses.color_pair(6))
        win.addstr(12, 40, "####    ####  ####          ####        ##  ## #####     #########       ####      ", curses.color_pair(7))
        win.refresh()

    def Pause(win):
        win.addstr(6,  40," ##########       #####      ##    ##       ########         #####     ", curses.color_pair(1))
        win.addstr(7,  40," ##      ##       ## ##      ##    ##      ##                ## ##     ", curses.color_pair(2))
        win.addstr(8,  40," ##      ##      ##   ##      ##  ##       ##               ##   ##    ", curses.color_pair(3))
        win.addstr(9,  40," ##      ##      #######        ###         #########       #######    ", curses.color_pair(4))
        win.addstr(10, 40," ##      ##     ##     ##        ##        ##              ##     ##   ", curses.color_pair(5))
        win.addstr(11, 40," ##      ##    ##       ##       ##        ##             ##       ##  ", curses.color_pair(6))
        win.addstr(12, 40,"####    ####   ##       ##      ####       #######        ##       ##  ", curses.color_pair(7))
        win.refresh()

    def VIn(win):
        win.addstr(6,  40," ##########     #######     ########    #########        #######         #####     ", curses.color_pair(1))
        win.addstr(7,  40," ##      ##    ##     ##    ##    ##    ##      #        ##  ##          ## ##     ", curses.color_pair(2))
        win.addstr(8,  40," ##      ##    ##     ##    ##          ##              ##   ##         ##   ##    ", curses.color_pair(3))
        win.addstr(9,  40," ##      ##    ##     ##    #######     ########       ##    ##         #######    ", curses.color_pair(4))
        win.addstr(10, 40," ##      ##    ##     ##    ##   ##     ##            ##     ##        ##     ##   ", curses.color_pair(5))
        win.addstr(11, 40," ##      ##    ##     ##    ##   ##     ##     #     ###########      ##       ##  ", curses.color_pair(6))
        win.addstr(12, 40,"####    ####    #######     #######     ########     ##       ##      ##       ##  ", curses.color_pair(7))
        win.refresh()

    def LOOS(win):
        win.addstr(6,  40," ##########    ##########    #######    ##        ###   ##########  ##########  ##       ##   ##    ##    ##", curses.color_pair(1))
        win.addstr(7,  40," ##      ##    ##      ##   ##     ##   ##     ### ##   ##       # ##      ##   ##       ##   ##    ##    ##", curses.color_pair(2))
        win.addstr(8,  40," ##      ##    ##      ##   ##     ##   ##    ###  ##   ##         ##      ##   ##       ##   ##    ##    ##", curses.color_pair(3))
        win.addstr(9,  40," ##      ##    ##########   ##     ##   ##   ###   ##   ##         ##########   ######## ##   ##    ##    ##", curses.color_pair(4))
        win.addstr(10, 40," ##      ##    ##           ##     ##   ##  ###    ##   ##         ##           ##    ## ##   ##    ##    ##", curses.color_pair(5))
        win.addstr(11, 40," ##      ##    ##           ##     ##   ## ###     ##   ##         ##           ##    ## ##   ##    ##    ##", curses.color_pair(6))
        win.addstr(12, 40,"####    ####  ####           #######    ###        ##   ##        ####          ######## ##   ##############", curses.color_pair(7))
        win.refresh()

    def Came_Record(win):
        win.addstr(6,  40," ##########    ##########   ####   ###     ########    ##########    #######      ##       ##", curses.color_pair(1))
        win.addstr(7,  40," ##      ##    ##       #   ##   ###      ##      ##   ##      ##    ##  ##       ##       ##", curses.color_pair(2))
        win.addstr(8,  40," ##      ##    ##           ## ###        ##      ##   ##      ##    ##   ##      ##       ##", curses.color_pair(3))
        win.addstr(9,  40," ##########    #########    ###           ##      ##   ##########    ##    ##     ######## ##", curses.color_pair(4))
        win.addstr(10, 40," ##            ##           ## ###        ##      ##   ##            ##     ##    ##    ## ##", curses.color_pair(5))
        win.addstr(11, 40," ##            ##       #   ##   ###      ##      ##   ##           ###########   ##    ## ##", curses.color_pair(6))
        win.addstr(12, 40,"####           ##########  ####   ###      ########   ####          ##       ##   ######## ##", curses.color_pair(7))
        win.refresh()

    def Meny(p,win):
        if (p==1):  
            b=random.randint(1, 6)
            win.addstr(20,  40, "			           Играть!", curses.color_pair(b))
            win.addstr(22,  40, "			           Информация!", curses.color_pair(7))
            win.addstr(24,  40, "			           Рекорды!", curses.color_pair(7))
            win.addstr(26,  40, "			           Настройки!", curses.color_pair(7))
        if (p==2):  
            b=random.randint(1, 6)
            win.addstr(20,  40, "			           Играть!", curses.color_pair(7))
            win.addstr(22,  40, "			           Информация!", curses.color_pair(b))
            win.addstr(24,  40, "			           Рекорды!", curses.color_pair(7))
            win.addstr(26,  40, "			           Настройки!", curses.color_pair(7))
        if (p==3):  
            b=random.randint(1, 6)
            win.addstr(20,  40, "			           Играть!", curses.color_pair(7))
            win.addstr(22,  40, "			           Информация!", curses.color_pair(7))
            win.addstr(24,  40, "			           Рекорды!", curses.color_pair(b))
            win.addstr(26,  40, "			           Настройки!", curses.color_pair(7))
        if (p==4):  
            b=random.randint(1, 6)
            win.addstr(20,  40, "			           Играть!", curses.color_pair(7))
            win.addstr(22,  40, "			           Информация!", curses.color_pair(7))
            win.addstr(24,  40, "			           Рекорды!", curses.color_pair(7))
            win.addstr(26,  40, "			           Настройки!", curses.color_pair(b))
        win.addstr(35,  40,"     KEY_ENTER -- выбор ; KEY_W -- ↑ ; KEY_S -- ↓ ; KEY_q -- выход", curses.color_pair(7))
        win.refresh()
        time.sleep(.5)

    def nastr(p,win):
        win.addstr(20, 35, "Ты можешь выбрать уровень сложности игры:", curses.color_pair(7))
        if (p==1):
            b=random.randint(1, 6)
            win.addstr(25, 35, "	Новичок!", curses.color_pair(b))
            win.addstr(27, 35, "	Любитель!", curses.color_pair(7))
            win.addstr(29, 35, "	Профи!", curses.color_pair(7))
        if (p==2):
            b=random.randint(1, 6)
            win.addstr(25, 35, "	Новичок!", curses.color_pair(7))
            win.addstr(27, 35, "	Любитель!", curses.color_pair(b))
            win.addstr(29, 35, "	Профи!", curses.color_pair(7))
        if (p==3):
            b=random.randint(1, 6)
            win.addstr(25, 35, "	Новичок!", curses.color_pair(7))
            win.addstr(27, 35, "	Любитель!", curses.color_pair(7))
            win.addstr(29, 35, "	Профи!", curses.color_pair(b))
        win.addstr(25, 55, "Если вы плохо играете, мы считаем, что", curses.color_pair(7))
        win.addstr(27, 55, "вы переоценили свои возможности!", curses.color_pair(7))
        win.addstr(29, 55, "Ваш уровень будет изменен автоматически!", curses.color_pair(7))
        win.refresh()
        time.sleep(.5)

    def Size(p,win):
        win.addstr(20, 35, "Ты можешь выбрать уровень сложности игры:", curses.color_pair(7))
        if (p==1):
           b=random.randint(1, 6)
           win.addstr(25, 35, "		1:1", curses.color_pair(b))
           win.addstr(27, 35, "		1:2", curses.color_pair(7))
        if (p==2):
           b=random.randint(1, 6)
           win.addstr(25, 35, "		1:1", curses.color_pair(7))
           win.addstr(27, 35, "		1:2", curses.color_pair(b))
        win.refresh()
        time.sleep(.5)

 
    def Gamemenu(self):
        p=1
        win = curses.initscr()
        win.clear()
        curses.curs_set(0)
        curses.noecho()
        curses.cbreak()
        win.keypad(True)
        curses.start_color()
        curses.init_pair(1, curses.COLOR_RED, curses.COLOR_BLACK)
        curses.init_pair(2, curses.COLOR_GREEN, curses.COLOR_BLACK)
        curses.init_pair(3, curses.COLOR_YELLOW, curses.COLOR_BLACK)
        curses.init_pair(4, curses.COLOR_BLUE, curses.COLOR_BLACK)
        curses.init_pair(5, curses.COLOR_MAGENTA, curses.COLOR_BLACK)
        curses.init_pair(6, curses.COLOR_CYAN, curses.COLOR_BLACK)
        curses.init_pair(7, curses.COLOR_WHITE, curses.COLOR_BLACK)
        curses.init_pair(8, curses.COLOR_BLACK, curses.COLOR_WHITE)
        curses.init_pair(9, curses.COLOR_RED, curses.COLOR_RED)
        curses.init_pair(10, curses.COLOR_GREEN, curses.COLOR_GREEN)
        curses.init_pair(11, curses.COLOR_YELLOW,curses.COLOR_YELLOW)
        curses.init_pair(12, curses.COLOR_BLUE, curses.COLOR_BLUE)
        curses.init_pair(13, curses.COLOR_MAGENTA, curses.COLOR_MAGENTA)
        curses.init_pair(14, curses.COLOR_CYAN, curses.COLOR_CYAN)
        self.Came_Title(win)
        c=0
        Q=0
        self.Meny(p,win)
        z=1
        S=0
        while (z==1):
            c = win.getch()
            if (c==ord('w')):   
                if (p>1):
                    p=p-1
                    win.clear()
                    self.Came_Title(win)
                    self.Meny(p,win)
            if (c==ord('s')):   
                if (p<4):
                    p=p+1
                    win.clear()
                    self.Came_Title(win)
                    self.Meny(p,win)
            if (c==ord('q')): 
                end(win)   
                sys. exit()
            if (c==32): 
                z=0
                win.clear()
                if (p==1):
                    f = open('records.txt')
                    St=f.read()
                    f.close   
                    self.Hellow(win)     
                    win.addstr(20,40,"			 Как вас зовут?", curses.color_pair(7))
                    win.refresh()
                    curses.echo()
                    name=win.getstr(22,70)
                    curses.noecho()
                    win.addstr(24,67,"Хорошей игры! ", curses.color_pair(7))
                    win.refresh()
                    time.sleep(.9)  
                    glass = Glass()
                    for i in range(26):
                        glass.array[i] = [0] * 15
                    for j in range(4, 24, 1):
                        for i in range(0, 3, 1):
                            glass.array[j][i]=10
                    for j in range(4, 24, 1):
                        for i in range(13, 15, 1):
                            glass.array[j][i]=10
                    for j in range(24, 26, 1):
                        for i in range(0, 15, 1):
                            glass.array[j][i]=10
                    for i in range(26):
                        glass.array[i] = [0] * 15
                    for j in range(4, 24, 1):
                        for i in range(0, 3, 1):
                            glass.array[j][i]=10
                    for j in range(4, 24, 1):
                        for i in range(13, 15, 1):
                            glass.array[j][i]=10
                    for j in range(24, 26, 1):
                        for i in range(0, 15, 1):
                            glass.array[j][i]=10
                    win.clear() 
                    win.refresh()
                    St=int(St)
                    glass.V=St%10
                    R=1
                    d=0
                    while (R!=0):
                        if (d==0):
                            figure  = Figure()
                            figure1 = Figure()
                            if (St//10==1):
                                figure.speed=1
                            if (St//10==2): 
                                figure.speed=0.8
                            if (St//10==3): 
                                figure.speed=0.6
                        else:
                            figure.color=figure1.color
                            figure.form=figure1.form
                            figure.chg_fig ()
                            figure1 =Figure()
                        d=d+1
                        figure.x_pol=6
                        figure.y_pol=1
                        S=1
                        while (S!=0): 
                            glass.y1=0
                            glass.y2=0
                            glass.y3=0
                            glass.y4=0
                            glass.Pointer(0,St,'.',0,win,figure.speed)
                            Q=glass.proec_figure(figure.x_pol,figure.y_pol,figure.as0,Q)
                            glass.Clear()
                            figure.go_down()
                            glass.Painter(figure.as0, figure.x_pol,figure.y_pol)
                            time.sleep(figure.speed)
                            win.clear() 
                            win.refresh()
                            figure.Pointer2(glass.V,win)
                            figure1.Pointer(glass.V,St,win)
                            glass.Pointer(0,St,'.',0,win,figure.speed)
                            win.refresh()
                            win.nodelay(True)
                            c =win.getch()
                            if (c==ord('w')): 
                                figure.go_rotation()
                                figure.chg_fig ()
                                W=glass.chg_rotation(figure.as0, figure.x_pol,figure.y_pol)
                                figure.go_rotation2()
                                figure.chg_fig ()
                                if (W!=0): 
                                    glass.proec_figureN()
                                    glass.Clear()
                                    figure.go_rotation()
                                    figure.chg_fig ()
                                    Q=glass.proec_figure( figure.x_pol,figure.y_pol,figure.as0,Q)
                                    glass.Painter(figure.as0, figure.x_pol,figure.y_pol)
                                    time.sleep(figure.speed)
                                    win.clear() 
                                    win.refresh()
                                    figure.Pointer2(glass.V,win)
                                    figure1.Pointer(glass.V,St,win)
                                    glass.Pointer(0,St,'.',0,win,figure.speed)
                            if c==ord('d'):                           
                                W=glass.chg_right(figure.as0, figure.x_pol,figure.y_pol)
                                if (W!=0): 
                                    glass.proec_figureN()
                                    glass.Clear()
                                    figure.go_right()
                                    Q=glass.proec_figure( figure.x_pol,figure.y_pol,figure.as0,Q)
                                    glass.Painter(figure.as0, figure.x_pol,figure.y_pol)
                                    time.sleep (figure.speed)
                                    win.clear() 
                                    win.refresh()
                                    figure.Pointer2(glass.V,win)
                                    figure1.Pointer(glass.V,St,win)
                                    glass.Pointer(0,St,'.',0,win,figure.speed)
                            if c==ord('a'):
                                W=glass.chg_left(figure.as0, figure.x_pol,figure.y_pol)
                                if (W!=0): 
                                    glass.proec_figureN()
                                    glass.Clear()
                                    figure.go_left()
                                    Q=glass.proec_figure( figure.x_pol,figure.y_pol,figure.as0,Q)
                                    glass.Painter(figure.as0, figure.x_pol,figure.y_pol)
                                    time.sleep (figure.speed)
                                    win.clear() 
                                    win.refresh()
                                    figure.Pointer2(glass.V,win)
                                    figure1.Pointer(glass.V,St,win)
                                    glass.Pointer(0,St,'.',0,win,figure.speed) 
                            if c==ord('s'): 
                                glass.Clear()
                                figure.y_pol=glass.proec_figureN2(Q,figure.y_pol)
                                time.sleep(figure.speed)
                                win.clear() 
                                win.refresh()
                                figure.Pointer2(glass.V,win)
                                figure1.Pointer(glass.V,St,win)
                                glass.Painter(figure.as0, figure.x_pol,figure.y_pol)
                                glass.Pointer(0,St,'.',0,win,figure.speed)
                            if c==ord('q'):
                                end(win)
                                sys. exit()
                            if c==ord('p'):
                                win.clear() 
                                win.refresh()
                                game.Pause(win)
                                win.addstr(18,40,"Если хотите продолжить нажмите 'p'!", curses.color_pair(7))
                                booll=1
                                while booll==1:
                                    c=win.getch()
                                    if c==ord('p'):
                                        booll=0 
                                win.clear() 
                                win.refresh()
                            glass.proec_figureN() 
                            glass.Pointer(0,St,'.',0,win,figure.speed)
                            R=glass.new_figure() 
                            S=glass.chg_down(figure.as0, figure.x_pol,figure.y_pol)
                        figure.count[0]=figure.count[0]+1
                        for x in range(1, 8, 1):
                            if (figure.form==x):
                                win.refresh()
                                figure.count[x]=figure.count[x]+1
                        if (figure.count[0]==15 and glass.line==0):
                            if (St==3):
                                St=2
                            if (St==2):
                                St=1
                        glass.old_fig(figure.as0, figure.x_pol,figure.y_pol)
                        glass.chg_line()
                        if (glass.level==99999999):
                            win.clear() 
                            win.refresh()
                            VIn(win)
                            end(win)
                            sys. exit()
                        if (glass.y1!=0):
                            figure1.Pointer(glass.V,St,win)
                            glass.Pointer(1,St,'.',0,win,figure.speed)
                            figure.Pointer2(glass.V,win)
                            for fig in '.', '*', 'о', '0', 'O':
                                time.sleep(0.4)
                                win.clear() 
                                win.refresh()
                                figure.Pointer2(glass.V,win)
                                figure1.Pointer(glass.V,St,win)
                                glass.Pointer(1,St,fig,1,win,figure.speed)
                            time.sleep(0.4)
                            win.clear() 
                            win.refresh() 
                            figure.Pointer2(glass.V,win)
                            figure1.Pointer(glass.V,St,win)
                            glass.Pointer(0,St,'.',0,win,figure.speed)
                            glass.go_down_glass_1()
                            time.sleep(0.4)
                            win.clear() 
                            win.refresh() 
                            glass.go_down_glass_2()
                            figure1.Pointer(glass.V,St,win)
                            figure.Pointer2(glass.V,win)
                            glass.Pointer(0,St,'.',0,win,figure.speed)
                            figure.speed=glass.prize_line(figure.speed)
                            for j in range(0, 4, 1):
                                for i in range(3, 13, 1):
                                    glass.array[4+j][i]=0
                    f = open('records.txt','r')
                    cou=0
                    kol=[0,0,0]
                    strp = ['string1', 'string2', 'string3'] 
                    sc=0
                    st=0
                    r=0
                    if (os.stat('records.txt').st_size == 1):
                        cou=f.read(1)
                        for i in range(0,(cou+1), 1):
                            strp[i]=f.read(8)
                            kol[i]=f.read(7)
                    f.close()    
                    if (cou==1):
                        r=1
                        if (glass.level>kol[0]): 
                            kol[1]=kol[0]
                            strp [1]=strp [0]
                            kol[0]=glass.level
                        if(name!=strp [0]):
                            strp [0]=name
                        else:
                            kol[1]=glass.level
                            strp [1]=name
                    if (cou==2):
                        for i in range(0,2, 1):               
                            r=1
                            if (glass.level>kol[i]): 
                                if (i==0):
                                    kol[i+2]=kol[i+1]
                                    kol[i+1]=kol[i]
                                    strp [i+2]=strp [i+1]
                                    strp [i+2]=strp [i+1]
                                if (i==1):
                                    kol[i+1]=kol[i]
                                    strp [i+1]=strp [i]
                                    kol[i]=glass.level
                                if(name!=strp [i]):
                                    strp [i]=name
                            else:
                                kol[2]=glass.level
                                strp [2]=name
                    if (cou==3):
                        for i in range(0,3, 1):
                            if (glass.level>kol[i]): 
                                if (i==0):
                                    kol[i+2]=kol[i+1]
                                    kol[i+1]=kol[i]
                                    strp [i+2]=strp [i+1]
                                    strp [i+1]=strp [i]
                                if (i==1):
                                    kol[i+1]=kol[i]
                                    strp [i+1]=strp [i]
                                    kol[i]=glass.level
                                if(name!=strp [i]):
                                    strp [i]=name
                    if (cou==3):
                        f = open('text.txt', 'a')
                        cou=cou+1
                        f.write(str(cou))
                        f.write(str(name))
                        S=str(glass.level)
                        f.write(S)
                        f.close() 
                    else:
                        if (r==1):
                            cou=cou+1
                        f = open('text.txt', 'a') 
                        f.write(str(cou))
                        for i in range(0,cou, 1):
                            strp[i].ljust(8)
                            f.write(strp[i])
                            S=str(kol[i])
                            S.ljust(7)
                            f.write(S)
                        f.close()
                    win.clear() 
                    win.refresh()
                    self.LOOS(win)
                    time.sleep(2)
                    end(win)
                    sys. exit()
                if (p==3):
                    self.Came_Record(win)
                    i=0
                    my_string='str'
                    kol=0
                    f = open('text.txt', 'r') 
                    win.addstr(15,40,   "  ИМЯ                                       СЧЕТ", curses.color_pair(7))
                    cou=f.read(1)
                    cou=int(cou)
                    for i in range(0,cou, 2):   
                        b=random.randint(1, 6)
                        c=f.read(1)
                        my_string=f.read(10)
                        kol=f.read(3)
                        win.addstr(17+i*2,39,str(i+1), curses.color_pair(7))
                        win.addstr(17+i*2,40,".", curses.color_pair(7))
                        win.addstr(17+i*2,41,my_string, curses.color_pair(b))
                        win.addstr(17+i*2,85,kol, curses.color_pair(b))
                    win.addstr(30,50,"Если хотите продолжить нажмите 'p'!", curses.color_pair(7))
                    c = win.getch()
                    if (c==32):
                        Gamemenu()
                    else:
                        end(win)
                        sys. exit()
                if (p==2):
                    b=random.randint(1, 6)
                    win.addstr(1,40," **************************************************************************", curses.color_pair(7))
                    win.addstr(2,40,"*	          Nizhniy Novgorod Technical University		           *", curses.color_pair(7))
                    win.addstr(3,40,"*				Program Tetris		                   *", curses.color_pair(7))
                    win.addstr(4,40,"*	Performed student grupp 20-IVT-2. Zhalnina Ekaterina Evgenevna	   *", curses.color_pair(7))
                    win.addstr(5,40," **************************************************************************", curses.color_pair(7))
                    win.addstr(10,35,"Тетрис - компьютерная игра, изначально придуманная и разработанная советским программистом.", curses.color_pair(b))
                    win.addstr(12,35,"Игра реализована практически на всех современных компьютерах, мобильных телефонах, игровых консолях.", curses.color_pair(b))
                    win.addstr(14,35,"Суть игры в тетрис состоит в том, что случайные фигуры падают сверху вниз.", curses.color_pair(b))
                    win.addstr(16,35,"Во время полета каждой фигурки игрок может вращать ее вокруг своей оси и перемещаться влево и вправо по горизонтали.", curses.color_pair(b))
                    win.addstr(18,35,"Когда ряд из 10 ячеек заполняется по горизонтали, он исчезает. Очки начисляются за каждую исчезающую линию..", curses.color_pair(b))
                    win.addstr(20,35,"Скорость падения каждой последующей фигурки увеличивается.", curses.color_pair(b))
                    win.addstr(18,35,"Игра заканчивается, когда новая фигура больше не может падать, и затем подсчитывается общее количество очков за игру.", curses.color_pair(b))
                    win.addstr(35,35,"	Если ты хочешь выйти нажми -- q ; если ты хочешь войти в меню нажми -- 'p' ;", curses.color_pair(7))
                    c =win.getch()
                    booll=1
                    while booll==1:
                        if c==ord('q'):
                            end(win)
                            sys. exit()
                        if c==ord('p'):
                            booll=0 
                            self.Gamemenu(game)
                if (p==4):
                    d=1
                    s=0
                    self.Turning(win)
                    self.nastr(d,win)
                    while(s==0):
                        c =win.getch()
                        if (c==ord('w')):
                            if (d>1):
                                d=d-1    
                                self.Turning(win)                            
                                self.nastr(d,win)
                        if (c==ord('s')):
                            if (d<3):
                                d=d+1
                                self.Turning(win)
                                self.nastr(d,win)
                        if (c==ord('q')):
                            end(win)
                            sys. exit()
                        if (c==32):
                            s=d
                    x=1
                    a=0
                    win.clear() 
                    win.refresh()
                    self.Turning(win)
                    self.Size(x,win)
                    while(a==0):
                        c = win.getch()
                        if (c==ord('w')):
                            if (x>1):
                                x=x-1 
                                self.Turning(win)                               
                                self.Size(x,win)
                        if (c==ord('s')):
                            if (x<3):
                                x=x+1
                                self.Turning(win)
                                self.Size(x,win)
                        if (c==ord('q')):
                            end(win)
                            sys. exit()
                        if (c==32):
                            a=x
                    f = open('rec.txt', 'w')
                    f.write(str(s))
                    f.write(str(a))
                    f.close() 
                    self.Gamemenu(game)
                            








game=Game
game.Gamemenu(game) 
