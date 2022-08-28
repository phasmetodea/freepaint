#include <graphics.h>
#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <iostream>
#include "input.h"
#include "backspace.hpp"
char* plugindll;
char* pluginconfig;
char *hexColor;
int r, g, b;
#include "plugin.h"
POINT cursorPos;
int x; int y;
int* ptr;
int page = 0;
int toce;
int pencolor = BLACK;
int BAKROND = WHITE;
int pensize = 20;
int i;
int old_col;
int new_col;
int typepen = 1;
int typeim = 1;
int typeov = 2;
int back = 0;
int xsize = GetSystemMetrics(SM_CXSCREEN);
int ysize = GetSystemMetrics(SM_CYSCREEN);
int x1;
int y1;
int x2;
int y2;
int x3;
int y3;
int x4;
int y4;
char* plugdll = loadplugindll();
char* plugconfig = loadpluginconfig();
int fillst;
int stepmul = 1;
char charcon;
int step = 1;
int oversize = ysize/3;
char* thetext = "";
int bcol = DARKGRAY;
int bcol1 = DARKGRAY;
int bcol2 = DARKGRAY;
int bcol3 = DARKGRAY;
int height = GetSystemMetrics(SM_CYSCREEN);
int width = GetSystemMetrics(SM_CXSCREEN);
//GetSystemMetrics(SM_CYSCREEN)
//GetSystemMetrics(SM_CXSCREEN)



int main()
{
initwindow(width,height,"",-3,-3);
setfillstyle(1,WHITE);
floodfill(0,0,DARKGRAY);
setfillstyle(1,DARKGRAY);
bar(0,0,GetSystemMetrics(SM_CXSCREEN),100); 
setfillstyle(1,BLACK);
bar(520,30,540,50); 
setfillstyle(1,WHITE);
bar(550,30,570,50); 
setfillstyle(1,RED);
bar(580,30,600,50); 
setfillstyle(1,BLUE);
bar(610,30,630,50); 

setbkcolor(DARKGRAY);
settextstyle(1, 0, 2);
setcolor(BLACK);
outtextxy(215,5,"Pen");
outtextxy(5,5,"Save");
outtextxy(5,53,"Open");
outtextxy(xsize-120,5,"window");
outtextxy(xsize-250,5,"square");
outtextxy(xsize-500,25,"image settings:");
outtextxy(xsize-250,50,"normal");
setbkcolor(WHITE);

while (1)
{
    //setactivepage(page);
	//setvisualpage(1-page);
    


    GetCursorPos(&cursorPos);
    x = cursorPos.x; y = cursorPos.y;
    if(GetAsyncKeyState(VK_LBUTTON) and not(getpixel(x,y)==DARKGRAY) and y-pensize > 100 and typepen == 1) {
        saveim();
        while (TRUE)
        {       
        GetCursorPos(&cursorPos);
        x = cursorPos.x; y = cursorPos.y;
        setcolor(pencolor);
        setfillstyle(1,pencolor);
        fillellipse(x,y,pensize,pensize);
        if(not(GetAsyncKeyState(VK_LBUTTON)) or y-pensize < 101){
        break;
        }
        }
    }
    

    if(GetAsyncKeyState(VK_LBUTTON) and not(getpixel(x,y)==DARKGRAY) and y-pensize > 100 and typepen == 7) {
        saveim();
        while (TRUE)
        {       
        GetCursorPos(&cursorPos);
        x = cursorPos.x; y = cursorPos.y;
        setcolor(BAKROND);
        setfillstyle(1,BAKROND);
        fillellipse(x,y,pensize,pensize);
        if(not(GetAsyncKeyState(VK_LBUTTON)) or y-pensize < 101){
        break;
        }}

    }

    if(GetAsyncKeyState(VK_LBUTTON) and not(getpixel(x,y)==DARKGRAY) and y > 100 and getpixel(x,y)==BAKROND and typepen == 3) {
        setcolor(pencolor);
        setfillstyle(1,pencolor);
        floodfill(x,y,DARKGRAY);
        BAKROND = pencolor;

    }
    if(GetAsyncKeyState(VK_LBUTTON) and not(getpixel(x,y)==DARKGRAY) and y > 100 and typepen == 2) {
        saveim();
        setcolor(pencolor);
        setfillstyle(1,pencolor);
        bcol = getpixel(x,y);
        x1=x;
        y1=y;
        //flood(x1,y1,pencolor,getpixel(x1,y1));
        
        for (i = x; i <  GetSystemMetrics(SM_CXSCREEN); ++i)
        {
        bcol = DARKGRAY;
        if(not(getpixel(i,y)==getpixel(x,y))){
        bcol = getpixel(i,y);
        break;
        }
        }
        setfillstyle(1,bcol);
        bar(0,99,xsize,100);
        setfillstyle(fillst,pencolor);
        floodfill(x,y,bcol);
        setfillstyle(1,DARKGRAY);
        bar(0,99,xsize,100);

    }
    if(GetAsyncKeyState(VK_LBUTTON) and not(getpixel(x,y)==DARKGRAY) and y > 100 and typepen == 4) {
    pencolor = getpixel(x,y);

    }
    if(GetAsyncKeyState(VK_LBUTTON) and not(getpixel(x,y)==DARKGRAY) and y > 100 and typepen == 5) {
    saveim();
    setlinestyle(1,1,pensize);
    x1 = x;
    y1 = y;
    setcolor(pencolor);
    setfillstyle(1,pencolor);
    while (TRUE)
    {
    GetCursorPos(&cursorPos);
    x = cursorPos.x; y = cursorPos.y;
    if(not(GetAsyncKeyState(VK_LBUTTON)) or y-pensize < 101 or getpixel(x,y)==DARKGRAY){
    rectangle(x1,y1,x,y);
    break;
    }
    }}

    if(GetAsyncKeyState(VK_LBUTTON) and not(getpixel(x,y)==DARKGRAY) and y-pensize > 100 and typepen == 6) {
    saveim();
    setlinestyle(1,1,pensize);
    x1 = x;
    y1 = y;
    setcolor(pencolor);
    setfillstyle(1,pencolor);
    settextstyle(1,HORIZ_DIR,pensize);
    setbkcolor(BAKROND);
    while (TRUE)
    {
    getch();
    thetext = getinput();
    outtextxy(x1,y1,thetext);
    if(GetAsyncKeyState(VK_RETURN)){
    break;
    }
    }
    }

    if(GetAsyncKeyState(VK_LBUTTON) and not(getpixel(x,y)==DARKGRAY) and y > 100 and typepen == 8) {
    saveim();
    setlinestyle(1,1,pensize);
    x1 = x;
    y1 = y;
    setcolor(pencolor);
    setfillstyle(1,pencolor);
    while (TRUE)
    {
    GetCursorPos(&cursorPos);
    x = cursorPos.x; y = cursorPos.y;
    if(not(GetAsyncKeyState(VK_LBUTTON)) or y-pensize < 101 or getpixel(x,y)==DARKGRAY){
    line(x1,y1,x,y);
    break;
    }
    }}
    
    if(GetAsyncKeyState('P')) {
        typepen = 1;
    }
    if(GetAsyncKeyState('F')) {
        typepen = 2;
        fillst = 1;
    }
    if(GetAsyncKeyState('B')) {
        typepen = 3;
    } 
    if(GetAsyncKeyState('C')) {
        typepen = 4;
    }
    if(GetAsyncKeyState('R')) {
        typepen = 5;
    }
    if(GetAsyncKeyState('T')) {
        typepen = 6;
    }
    if(GetAsyncKeyState('E')) {
        typepen = 7;
    }
    if(GetAsyncKeyState('L')) {
        typepen = 8;
    }

    if(GetAsyncKeyState('W')) {
        typeim = 1;
    }
    if(GetAsyncKeyState('O')) {
        typeim = 2;
    }
    if(GetAsyncKeyState('S')) {
        typeov = 1;
    }
    if(GetAsyncKeyState('N')) {
        typeov = 2;
    }
    if(GetAsyncKeyState(VK_NUMPAD0)) {
        pensize = 1;
        oversize = ysize/5;
        if (typepen == 2)
        {
        fillst = 1;
        }
        

    }
    if(GetAsyncKeyState(VK_NUMPAD1)) {
        pensize = 5;
        oversize = ysize/4;
        if (typepen == 2)
        {
        fillst = 2;
        }
        


    }   
    if(GetAsyncKeyState(VK_NUMPAD2)) {
        pensize = 10;
        oversize = ysize/4;
        if (typepen == 2)
        {
        fillst = 3;
        }


    }
    if(GetAsyncKeyState(VK_NUMPAD3)) {
        pensize = 20;
        oversize = ysize/4;
        if (typepen == 2)
        {
        fillst = 4;
        }


    }
    if(GetAsyncKeyState(VK_NUMPAD4)) {
        pensize = 30;
        oversize = ysize/3;
        if (typepen == 2)
        {
        fillst = 5;
        }


    }
    if(GetAsyncKeyState(VK_NUMPAD5)) {
        pensize = 40;
        oversize = ysize/3;
        if (typepen == 2)
        {
        fillst = 6;
        }


    }
    if(GetAsyncKeyState(VK_NUMPAD6)) {
        pensize = 50;
        oversize = ysize/3;
        if (typepen == 2)
        {
        fillst = 7;
        }

    }
    if(GetAsyncKeyState(VK_NUMPAD7)) {
        pensize = 60;
        oversize = ysize/2;
        if (typepen == 2)
        {
        fillst = 8;
        }


    }
    if(GetAsyncKeyState(VK_NUMPAD8)) {
        pensize = 70;
        oversize = ysize/2;
        if (typepen == 2)
        {
        fillst = 9;
        }


    }
    if(GetAsyncKeyState(VK_NUMPAD9)) {
        pensize = 80;
        oversize = ysize/2;
        if (typepen == 2)
        {
        fillst = 10;
        }


    }
        if(GetAsyncKeyState(VK_DELETE)) {
        setfillstyle(1,WHITE);
        bar(0,100,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));

    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 30 and x < 70) {
        writeimagefile(NULL,0,100,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
        //outtextxy(5,5,"Save");
        //outtextxy(5,53,"Open");

    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 90 and y > 50 and x < 70) {
        //saveim();
        if(typeim == 1 and typeov == 2){
        readimagefile(NULL,0,100,xsize,ysize);}

        if(typeim == 1 and typeov == 1){
        readimagefile(NULL,xsize/5,100,xsize-(xsize/5),ysize);}

        if(typeim == 2){
        x2 = x;
        y2 = y;
        while (TRUE)
        {
        GetCursorPos(&cursorPos);
        x2 = cursorPos.x;
        y2 = cursorPos.y;
        if(GetAsyncKeyState(VK_LBUTTON) and y2 > 100+oversize/2 and typeov == 1){
        readimagefile(NULL,x2-(oversize/2),y2-(oversize/2),x2+(oversize/2),y2+(oversize/2));
        break;
        }

        if(GetAsyncKeyState(VK_LBUTTON) and y2 > 100+oversize/2 and typeov == 2){
        readimagefile(NULL,x2-(oversize),y2-(oversize/2),x2+(oversize),y2+(oversize/2));
        break;
        }
        }
        
        }
        //outtextxy(5,5,"Save");
        //outtextxy(5,53,"Open");

    }


    if(GetAsyncKeyState(VK_LBUTTON) and y < 50 and getpixel(x,y)==BLACK) {
        pencolor = BLACK;


    }
    if(GetAsyncKeyState(VK_LBUTTON) and y < 50 and getpixel(x,y)==WHITE) {
        pencolor = WHITE;
        //setlinestyle(1,0,5);
        //setcolor(CYAN);
        //rectangle(549,29,569,49);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 50 and getpixel(x,y)==COLOR(255,0,0)) {
        pencolor = COLOR(255,0,0);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 50 and getpixel(x,y)==COLOR(0,0,255)) {
        pencolor = COLOR(0,0,255);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 50 and getpixel(x,y)==COLOR(0,255,0)) {
        pencolor = COLOR(0,255,0);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 50 and getpixel(x,y)==YELLOW) {
        pencolor = YELLOW;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 50 and getpixel(x,y)==COLOR(255,0,255)) {
        pencolor = COLOR(255,0,255);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 50 and getpixel(x,y)==COLOR(255,165,0)) {
        pencolor = COLOR(255,165,0);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y > 30 and y < 50 and x > 759 and x < 781 and getpixel(x,y)==CYAN) {
        pencolor = CYAN;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==LIGHTRED) {
        pencolor = LIGHTRED;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==LIGHTBLUE) {
        pencolor = LIGHTBLUE;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==LIGHTGREEN) {
        pencolor = LIGHTGREEN;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==COLOR(153,153,0)) {
        pencolor = COLOR(153,153,0);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==COLOR(254,216,177)) {
        pencolor = COLOR(254,216,177);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==LIGHTMAGENTA) {
        pencolor = LIGHTMAGENTA;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==LIGHTCYAN) {
        pencolor = LIGHTCYAN;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==LIGHTGRAY) {
        pencolor = LIGHTGRAY;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==RED) {
        pencolor = RED;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==BLUE) {
        pencolor = BLUE;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==GREEN) {
        pencolor = GREEN;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==COLOR(179,98,0)) {
        pencolor = COLOR(179,98,0);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==COLOR(78,53,36)) {
        pencolor = COLOR(78,53,36);


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==MAGENTA) {
        pencolor = MAGENTA;


    }

    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==COLOR(75,0,130)) {
        pencolor = COLOR(75,0,130);


    }


    if(GetAsyncKeyState(VK_ESCAPE)) {
        break;
    }

    if( pencolor == BLACK) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(520,30,539,49);


    } else {
        setfillstyle(1,BLACK);
        bar(520,30,540,50); 

    }

    if( pencolor == WHITE) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(550,30,569,49);


    } else {
        setfillstyle(1,WHITE);
        bar(550,30,570,50); 

    }

    if( pencolor == COLOR(255,0,0)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(580,30,599,49);


    } else {
        setfillstyle(1,COLOR(255,0,0));
        bar(580,30,600,50); 


    }

if( pencolor == COLOR(0,0,255)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(610,30,629,49);


    } else {
        setfillstyle(1,COLOR(0,0,255));
        bar(610,30,630,50); 


    }
if( pencolor == COLOR(0,255,0)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(640,30,659,49);

    } else {
        setfillstyle(1,COLOR(0,255,0));
        bar(640,30,660,50); 


    }

    if( pencolor == YELLOW) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(670,30,689,49);


    } else {
        setfillstyle(1,YELLOW);
        bar(670,30,690,50); 


    }

    if( pencolor == COLOR(255,165,0)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(700,30,719,49);


    } else {
        setfillstyle(1,COLOR(255,165,0));
        bar(700,30,720,50); 


    }

    if( pencolor == COLOR(255,0,255)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(730,30,749,49);


    } else {
        setfillstyle(1,COLOR(255,0,255));
        bar(730,30,750,50); 


    }

    if( pencolor == CYAN) {
        setlinestyle(0,0,1);
        setcolor(DARKGRAY);
        rectangle(760,30,779,49);


    } else {
        setfillstyle(1,CYAN);
        bar(760,30,780,50); 


    }




    if( pencolor == LIGHTRED) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(580,60,599,79);


    } else {
        setfillstyle(1,LIGHTRED);
        bar(580,60,600,80); 


    }

    if( pencolor == LIGHTBLUE) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(610,60,629,79);


    } else {
        setfillstyle(1,LIGHTBLUE);
        bar(610,60,630,80); 


    }

    if( pencolor == LIGHTGREEN) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(640,60,659,79);


    } else {
        setfillstyle(1,LIGHTGREEN);
        bar(640,60,660,80); 


    }

    if( pencolor == COLOR(153,153,0)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(670,60,689,79);


    } else {
        setfillstyle(1,COLOR(153,153,0));
        bar(670,60,690,80); 


    }

    if( pencolor == COLOR(254,216,177)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(700,60,719,79);


    } else {
        setfillstyle(1,COLOR(254,216,177));
        bar(700,60,720,80); 


    }

    if( pencolor == LIGHTMAGENTA) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(730,60,749,79);


    } else {
        setfillstyle(1,LIGHTMAGENTA);
        bar(730,60,750,80); 


    }

    if( pencolor == LIGHTCYAN) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(760,60,779,79);


    } else {
        setfillstyle(1,LIGHTCYAN);
        bar(760,60,780,80); 


    }
if(plugconfig == "RGB"){
    rgbloader();
    if(GetAsyncKeyState(VK_LBUTTON) and y < 80 and getpixel(x,y)==COLOR(r,g,b)) {
    pencolor = COLOR(r,g,b);
    }
    if( pencolor == COLOR(r,g,b)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(550,60,579,79);
    


    } else {
        setfillstyle(1,COLOR(r,g,b));
        bar(550,60,580,80); 


    }}



    if( pencolor == LIGHTGRAY) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(550,3,569,22);


    } else {
        setfillstyle(1,LIGHTGRAY);
        bar(550,3,570,23); 

    }


    if( pencolor == RED) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(580,3,599,22);


    } else {
        setfillstyle(1,RED);
        bar(580,3,600,23); 

    }

    if( pencolor == BLUE) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(610,3,629,22);


    } else {
        setfillstyle(1,BLUE);
        bar(610,3,630,23); 

    }

    if( pencolor == GREEN) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(640,3,659,22);


    } else {
        setfillstyle(1,GREEN);
        bar(640,3,660,23); 

    }

    if( pencolor == COLOR(179,98,0)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(670,3,689,22);


    } else {
        setfillstyle(1,COLOR(179,98,0));
        bar(670,3,690,23); 

    }

    if( pencolor == COLOR(78,53,36)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(700,3,719,22);


    } else {
        setfillstyle(1,COLOR(78,53,36));
        bar(700,3,720,23); 

    }

    if( pencolor == MAGENTA) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(730,3,749,22);


    } else {
        setfillstyle(1,MAGENTA);
        bar(730,3,750,23); 

    }

    if( pencolor == COLOR(75,0,130)) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(760,3,779,22);


    } else {
        setfillstyle(1,COLOR(75,0,130));
        bar(760,3,780,23); 

    }




setbkcolor(DARKGRAY);
settextstyle(1, 0, 2);
setcolor(BLACK);
if( typepen == 1) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(215,5,267,25);
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(215,5,"Pen");
        setfillstyle(1,DARKGRAY);
        bar(215,25,267,26);


    }

if( typepen == 2) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(215,30,263,50);
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(215,30,"Fill");
        setfillstyle(1,DARKGRAY);
        bar(215,50,305,51);


    }
if( typepen == 3) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(215,53,335,73);
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(215,53,"Bkround");
        setfillstyle(1,DARKGRAY);
        bar(215,73,336,74);


    }
if( typepen == 4) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(215,75,347,95);  
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(215,75,"colorpick");
        setfillstyle(1,DARKGRAY);
        bar(215,95,347,96);


    }

if( typepen == 5) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(355,5,480,25);
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(355,5,"rectangle");
        setfillstyle(1,DARKGRAY);
        bar(355,25,481,26);


    }

if( typepen == 6) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(355,30,407,50);
        //outtextxy(355,5,"rectangle");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(355,30,"text");
        setfillstyle(1,DARKGRAY);
        bar(355,50,407,51);


    }

if( typepen == 7) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(355,58,438,73);
        //outtextxy(355,5,"rectangle");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(355,53,"eraser");
        setfillstyle(1,DARKGRAY);
        bar(355,74,439,73);


    }

if( typepen == 8) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(355,75,407,95);  
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(355,75,"line");
        setfillstyle(1,DARKGRAY);
        bar(355,95,410,96);


    }



if( typeim == 1) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(xsize-120,5,xsize-10,25);
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(xsize-120,5,"window");
        setfillstyle(1,DARKGRAY);
        bar(xsize-120,25,xsize-10,26);


    }

if( typeim == 2) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(xsize-110,50,xsize-8,70);
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(xsize-110,50,"overlay");
        setfillstyle(1,DARKGRAY);
        bar(xsize-110,70,xsize-8,71);


    }

if( typeov == 1) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(xsize-250,5,xsize-160,25);
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(xsize-250,5,"square");
        setfillstyle(1,DARKGRAY);
        bar(xsize-250,25,xsize-160,26);


    }

if( typeov == 2) {
        setlinestyle(0,0,1);
        setcolor(CYAN);
        rectangle(xsize-250,50,xsize-153,70);
        //outtextxy(215,40,"pen");

    } else {
        setcolor(BLACK);
        setbkcolor(DARKGRAY);
        outtextxy(xsize-250,50,"normal");
        setfillstyle(1,DARKGRAY);
        bar(xsize-250,70,xsize-153,71);


    }


if(GetAsyncKeyState(VK_BACK)){
    loadback();
}

if (plugconfig == "SYSTEM"){
system(plugdll);
}
    //swapbuffers();
    //page = 1 - page;



}
}