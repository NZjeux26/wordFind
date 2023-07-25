#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cctype>
#include <cstdio>

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
