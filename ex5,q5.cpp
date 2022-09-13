//
//  main.cpp
//  Ex 5, Q5
//  Write a program which prints a table listing the number of occurrences of the lower-case characters 'a' to 'z' in the file "Sheet5Ex5.cpp". (Save your program in a file of this name so that you can test it on itself.) Write your program as though your computer is short of memory - you should declare only one variable of type "ifstream", one variable of type "char", and two variables of type "int".
//
//  NB: Did an additional task where I wrote data to another file (Sheet5Ex5.txt)
//
//  Created by Max Mitchell on 13/09/2022.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    
    int charTally[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
    
    /* Open streams */
    ifstream in_stream;
    in_stream.open(".../main.cpp");
    
    ofstream out_stream;
    out_stream.open(".../Sheet5Ex5.txt");
    
    if (in_stream.fail() || out_stream.fail()) {
        cout << "Sorry, the file(s) couldn't be opened!\n";
        exit(1);
    }
    
    /* Add chars to tally*/
    char character;
    while(!(in_stream.eof())){
        in_stream.get(character);
        if ('a' <= character && character <= 'z'){
            int index = static_cast<int>(character)-97; // convert ascii to array index
            charTally[index] += 1;
        }
        /* CAN INCLUDE UPPER CASE LETTERS WITH: */
        // if ('A' <= character && character <= 'Z'){
        //     count[static_cast<int>(character)-65] += 1;
        // }
        
    }
    
    // Write data to Sheet5Ex5.txt in a table
    out_stream << left << setw(16) << "CHARACTER" << "OCCURRENCES\n\n";
    for (char i = 'a'; i <= 'z'; i++){
        out_stream << setw(16) << i << charTally[static_cast<int>(i)-97] << setw(16) << endl;
    }
    
    in_stream.close();
    out_stream.close();

    return 0;
}

