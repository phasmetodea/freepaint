#include <graphics.h>
#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>

int saveim(){
writeimagefile("Data//saveim32.jpg",0,100,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
}

int loadback(){
readimagefile("Data//saveim32.jpg",0,100,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
}