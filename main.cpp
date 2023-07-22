#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

int main(void) {
    vector<char> letters =  { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    vector<char> selected;
    
    int seed = time(NULL);
    srand(seed);

    //for loop to select 6 random letters
    //what if two random letters are selected that are the same?
    for (int i = 0; i < 6; i++)
    {   
        selected.push_back(letters[rand() % letters.size()]); //explain this?
        cout << selected[i] << endl;
    }
    
    for (int i = 0; i <= selected.size(); i++){
        
    }
    return 0;
}