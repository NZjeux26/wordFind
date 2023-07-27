#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "hardware.h"

#if defined __WIN32__
    #include <windows.h>
#elif defined __unix__ || defined __APPLE__
    #include <unistd.h>
#endif
#include <sys/stat.h>
#include <sys/types.h>
/*
Notes
Add run time display
Multiples of the same letter
Performance stats
Question, if i allow words with multiables of same letter to be counted, what about words larger than six letters but only contain the selected letters?
*/
void printLetters(std::vector<char> selected, std::vector<std::string> words);
void printHardware();
void printTime(double time);

int main(void) {
    std::vector<char> letters =  { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    std::vector<char> selected = { 'a', 'e', 'd', 'o', 'g', 'y'};
    std::vector<std::string> words;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    int seed = time(NULL);
    srand(seed);

    //for loop to select 6 random letters
    //what if two random letters are selected that are the same? - That is fine
    //what about words with two or more of the same letter? - No one letter once
    // for (int i = 0; i < 6; i++)
    // {   
    //     selected.push_back(letters[rand() % letters.size()]); //explain this?
    //     cout << selected[i] << " ";
    // }
    
    std::fstream file("words_alpha.txt");

    if(!file.is_open()){
        std::cout << "Error opening file";
        return 1;
    }

    
    start = std::chrono::high_resolution_clock::now();

    std::string line;
    short match = 0;
    while(getline (file, line)){//this is O(n^2) complexity, change to hash table later?
        match = 0;
        for(int i = 0; i <= line.length(); i++){//word
          //  if(line.length() > selected.size()) break; //if the word is longer than the total amount of letters avaliable, break the loop. 
          //  ^**Removed for now, if i'm allowing words with multiables of same letters to be counted, then ones > the letters should be allowed.
            //for each letter in line, check to see if the letter is in the selected vector, if it is
            for(int j = 0; j < selected.size(); j++){//checks letter in word matches current selected letter from vector
                if(line[i] == selected[j]){
                    match++;
                    break; //break out of the if loop, letter found move up the word list size.
                }
            }
        }
        if(match == line.size()) words.push_back(line); //if the word has all the letters in the selected vector, add it to the words vector
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    
    printHardware();
    printTime(elapsed_seconds.count());
    printLetters(selected, words);

   return 0;
}
/* TO ADD */
/*
printing to static file containing, system CPU information, memory, letters, selected letters, and words.

*/

void printLetters(std::vector<char> selected, std::vector<std::string> words) {

    if (words.size() == 0) std::cout << "No words found" << std::endl;    //if no words, print nothing
    else{
        std::cout << "Letters: ";                                    //print the letters selected
        for (int i = 0; i < selected.size(); i++){
            std::cout << selected[i] << " ";
        }
        std::cout << "\nWords Found: " << words.size() << std::endl;      //print the number of words found then the words ** Might add printing to a file, or adding to keep a scoreboard
        // for(int i = 0; i < words.size(); i++){
        // std::cout << words[i] << std::endl;
        // }
    }
}

void printHardware() {
    #ifdef __WIN32__
    std::string cpu = winCPUstuff();
    std::string OS = winOS();
    std::string RAM = winRAM();

    std::cout << "CPU: " << cpu << std::endl;
    std::cout << "Windows: " << OS << std::endl;
    std::cout << "RAM: " << RAM << std::endl;
    
    #elif __unix__ 
    #elif __apple__
    #elif _AMIGA
    std::cout << "Amiga" << std::endl;
    std::cout << "Ha your old, get a modern OS nerd" << std::endl;
    #else
        std::cout << "Unknown OS" << std::endl;
    #endif
}

void printTime(double time) {
    std::cout << std::setprecision(7) << std::fixed;
    std::cout << "Time Elapsed: " << time << " seconds" << std::endl;
}











/* if(line[i] == selected[0] || line[i] == selected[1] || line[i] == selected[2] || line[i] == selected[3] || line[i] == selected[4] || line[i] == selected[5]){
                words.push_back(line);
            }*/