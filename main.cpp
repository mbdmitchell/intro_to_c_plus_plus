//
//  main.cpp
//  Ex 4, Q1
//  Created by Max Mitchell on 10/09/2022.
//

#include <iostream>
#include <unistd.h>
#include <fstream>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    ifstream in_stream; //takes values from files / provides input operation on files / read data from files
    
    in_stream.open("/Users/maxmitchell/Documents/Edu/CS/msc-imperial/modules/intro-to-c-plus-plus/Ex 4, Q1/Ex 4, Q1/main.cpp");
   
    if (in_stream.fail()){
        cout << "Sorry, the file couldn't be opened!\n";
        exit(1);
    }

    char character;
    in_stream.get(character);
    while (!in_stream.eof())
    {
        cout << character;
        in_stream.get(character);
    }
    
    in_stream.close();
}

