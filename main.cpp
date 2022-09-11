//
//  main.cpp
//  Ex 4, Q2
//  Created by Max Mitchell on 11/09/2022.
//

#include <iostream>
#include <unistd.h>
#include <fstream>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    ifstream in_stream; //takes values from files / provides input operation on files / read data from files
    
    in_stream.open("/Users/maxmitchell/Documents/Edu/CS/msc-imperial/modules/intro-to-c-plus-plus/Ex 4, Q2/Ex 4, Q2/main.cpp");
    
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
                in_stream.get(character);// nicer way to move the pointer???
            }
        }
        //multi line comments
        if (character == '/' && in_stream.peek() == '*'){
            while (!(character == '*' && in_stream.peek() == '/') && !in_stream.eof()){
                in_stream.get(character);
            }
            in_stream.get(character); // nicer way to move the pointer and assign character??? put()?? something like that?
            in_stream.get(character);
        }
        
        cout << character;
        in_stream.get(character);
    }
      
    in_stream.close();

}

