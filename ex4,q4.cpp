//
//  main.cpp
//  Ex 4, Q4
//  Without using an array, write a program that prints itself out backwards on the screen.
//  Created by Max Mitchell on 12/09/2022.
//

#include <iostream>
#include <fstream>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    ifstream in_stream (".../main.cpp", ios::ate); // set the initial file position to the end of the file
    streampos size = in_stream.tellg();
    
    char c;
    for(int i=1; i<=size; i++){
        in_stream.seekg(-i,ios::end); // read back with seekg
        in_stream.get(c);
        cout << c;
        }
    
    in_stream.close();
    
    return 0;
}

