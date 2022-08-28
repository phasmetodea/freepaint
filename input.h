#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>


char* getinput(){

if(GetAsyncKeyState('Q')) {
return "q";
}

if(GetAsyncKeyState('W')) {
return "w";
}

if(GetAsyncKeyState('E')) {
return "e";
}

if(GetAsyncKeyState('R')) {
return "r";
}

if(GetAsyncKeyState('T')) {
return "t";
}

if(GetAsyncKeyState('Y')) {
return "y";
}

if(GetAsyncKeyState('U')) {
return "u";
}

if(GetAsyncKeyState('I')) {
return "i";
}

if(GetAsyncKeyState('O')) {
return "o";
}

if(GetAsyncKeyState('P')) {
return "p";
}

if(GetAsyncKeyState('Å')) {
return "å";
}

if(GetAsyncKeyState('A')) {
return "a";
}

if(GetAsyncKeyState('S')) {
return "s";
}

if(GetAsyncKeyState('D')) {
return "d";
}

if(GetAsyncKeyState('F')) {
return "f";
}

if(GetAsyncKeyState('G')) {
return "g";
}

if(GetAsyncKeyState('H')) {
return "h";
}

if(GetAsyncKeyState('J')) {
return "j";
}

if(GetAsyncKeyState('K')) {
return "k";
}

if(GetAsyncKeyState('L')) {
return "l";
}

if(GetAsyncKeyState('Ö')) {
return "ö";
}

if(GetAsyncKeyState('Ä')) {
return "ä";
}

if(GetAsyncKeyState('Z')) {
return "z";
}

if(GetAsyncKeyState('X')) {
return "x";
}

if(GetAsyncKeyState('C')) {
return "c";
}

if(GetAsyncKeyState('V')) {
return "v";
}

if(GetAsyncKeyState('B')) {
return "b";
}

if(GetAsyncKeyState('N')) {
return "n";
}

if(GetAsyncKeyState('M')) {
return "m";
}

if(GetAsyncKeyState('.')) {
return ".";
}

if(GetAsyncKeyState(',')) {
return ",";
}

if(GetAsyncKeyState('1')) {
return "1";
}

if(GetAsyncKeyState('2')) {
return "2";
}

if(GetAsyncKeyState('3')) {
return "3";
}

if(GetAsyncKeyState('4')) {
return "4";
}

if(GetAsyncKeyState('5')) {
return "5";
}

if(GetAsyncKeyState('6')) {
return "6";
}

if(GetAsyncKeyState('7')) {
return "7";
}

if(GetAsyncKeyState('8')) {
return "8";
}

if(GetAsyncKeyState('9')) {
return "9";
}

if(GetAsyncKeyState('0')) {
return "0";
}

if(GetAsyncKeyState('-')) {
return "-";
}

return "";
}