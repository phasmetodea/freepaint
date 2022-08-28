#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


char* loadpluginconfig(){
   FILE *fptr;

   if ((fptr = fopen("Data//plugin.config","r")) == NULL){
       printf("Error! opening config file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fscanf(fptr,"%d", &pluginconfig);

   printf("Value of n=%d", pluginconfig);
   fclose(fptr); 

return pluginconfig;
}



char* loadplugindll(){
   FILE *fptr;

   if ((fptr = fopen("Data//plugin.dll","r")) == NULL){
       printf("Error! opening dll file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fscanf(fptr,"%d", &plugindll);

   printf("Value of n=%d", plugindll);
   fclose(fptr); 

return plugindll;
}

int rgbloader(){
    hexColor = plugindll;
    std::sscanf(hexColor, "#%02x%02x%02x", &r, &g, &b);
    return 0;
}