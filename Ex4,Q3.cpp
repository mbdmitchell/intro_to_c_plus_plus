//
//  main.cpp
//  Ex4,Q3
//  Write a program which counts and displays the number of characters (including blanks) in its own source code file.
//
//  Created by Max Mitchell on 11/09/2022.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    ifstream in_stream;
    in_stream.open(".../main.cpp");
    
    if (in_stream.fail()){
        cout << "Sorry, the file couldn't be opened!\n";
        exit(1);
    }
    
    char character;
    int charCount = 0;
    
    in_stream.get(character);
    
    while (!in_stream.eof()){
        charCount++;
        in_stream.get(character);
    }
    in_stream.close();
    
    cout << charCount << endl;
    
    return 0;
}
