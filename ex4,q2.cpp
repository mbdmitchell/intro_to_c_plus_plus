//
//  main.cpp
//  Ex 4, Q2
//  Created by Max Mitchell on 11/09/2022.
//

// TODO: find nicer way to move the pointer and assign 'character'

// ---------------------------------- VERSION 1 ----------------------------------
#include <iostream>
#include <unistd.h>
#include <fstream>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    ifstream in_stream; 
    
    in_stream.open(".../main.cpp");
    
    if (in_stream.fail()) {
        cout << "Sorry, the file couldn't be opened!\n";
        exit(1);
    }
    
    char character;
    in_stream.get(character);
    
    //comment check
    while (!in_stream.eof()) {
        //single line comments
        if (character == '/' && in_stream.peek() == '/') {
            while ((character != '\n') && !in_stream.eof()){
                in_stream.get(character);
            }
        }
        //multi line comments
        if (character == '/' && in_stream.peek() == '*'){
            while (!(character == '*' && in_stream.peek() == '/') && !in_stream.eof()){
                in_stream.get(character);
            }
            in_stream.get(character);
            in_stream.get(character);
        }
        
        cout << character;
        in_stream.get(character);
    }
      
    in_stream.close();
}

