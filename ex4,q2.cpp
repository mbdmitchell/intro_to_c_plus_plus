//
//  main.cpp
//  Ex 4, Q2
//  Created by Max Mitchell on 11/09/2022.
//
// This program outputs itself to the screen and to the file 'WithoutComments.cpp', but without multi-line comments.

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    ifstream in_stream;
    ofstream out_stream;
    
    in_stream.open(".../main.cpp");
    out_stream.open(".../WithoutComments.cpp");
    
    if (in_stream.fail() || out_stream.fail()) {
        cout << "Sorry, the file(s) couldn't be opened!\n";
        exit(1);
    }
    
    // Output test statement to the screen:
    cout << "Testing: " << 16/2 << " = " << 4*2 << ".\n\n";
    
    char character;
    in_stream.get(character);

    //comment check
    while (!in_stream.eof()) {
        
        //multi line comments
        if (character == '/' && in_stream.peek() == '*'){
            while (!(character == '*' && in_stream.peek() == '/') && !in_stream.eof()){
                in_stream.get(character);
            }
            in_stream.get(character); // nicer way to move the pointer and assign character???
            in_stream.get(character);
        }
        
        cout << character;
        out_stream.put(character);
        in_stream.get(character);
    }
      
    in_stream.close();
    out_stream.close();
}

