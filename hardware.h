#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cctype>
#include <cstdio>
/*The reason this is all in a header and not part of the main, is that just calling the wmic command will cause it to run so by putting it here it will not show in the console.*/



std::string winCPUstuff(){ //used GPT and tabnine for assistance with the popen which i've never heard about
   std::string CPU;
   std::string cmd = "wmic cpu get name";

   FILE* pipe = popen(cmd.c_str(), "r");    //uses popen to pipe the output of the command into the file which is then fed into the string
      if (!pipe) return CPU;
      char buffer[128];
      while (!feof(pipe)) {
         if (fgets(buffer, 128, pipe)!= NULL)
            CPU += buffer;
      }
      pclose(pipe);

    std::string cleanCPU;
    for (int i = 0; i < CPU.length(); i++){  //use isalnum to remove non-alphanumeric characters from the string
        if(std::isalnum(CPU[i])) cleanCPU += CPU[i];
    }
    std::string CPUname;
    CPUname = cleanCPU.substr(4, cleanCPU.length() - 4);    //trims "Name" from the string

   return CPUname;
}

std::string winOS(){    //to turn these into a combined function since these are the same basic outlines
   std::string OS;
   std::string cmd = "wmic os get version";

   FILE* pipe = popen(cmd.c_str(), "r");
   if (!pipe) return OS;
   char buffer[128];
   while (!feof(pipe)){
      if (fgets(buffer, 128, pipe)!= NULL) //if i was being serious this has a buffer overflow vulnerability
         OS += buffer;
   }
   pclose(pipe);

   std::string cleanOS;
   for (int i = 0; i < OS.length(); i++){
      if(std::isalnum(OS[i]) || (std::ispunct(OS[i]))) cleanOS += OS[i];
   }
   
   std::string OSversion;
   OSversion = cleanOS.substr(7, cleanOS.length() - 7);
 
   return OSversion;
}

std::string winRAM(){
   std::string RAM;
   std::string cmd = "wmic memorychip get capacity";

   FILE* pipe = popen(cmd.c_str(), "r");
   if (!pipe) {
      return RAM;
   }
   char buffer[256];
   while (!feof(pipe)){
      if (fgets(buffer, 256, pipe)!= NULL) //if i was being serious this has a buffer overflow vulnerability
         RAM += buffer;
   }
   pclose(pipe);
   //instead of just getting rid of all non number characters, we can jsut bin the title and then add all numbers between spaces together? 
   std::string cleanRAM;
   for (int i = 0; i < RAM.length(); i++){
      if(std::isdigit(RAM[i])) cleanRAM += RAM[i];
   }
   return cleanRAM;
}
