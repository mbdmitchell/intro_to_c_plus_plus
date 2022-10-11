//
//  main.cpp
//  Ex 5, Q2
//  Write a function "print_pyramid()" which takes a single integer argument "height" and displays a "pyramid" of this height made up of of "*" characters on the screen. Test the function with a simple "driver" program
//  Created by Max Mitchell on 13/09/2022.
//

#include <iostream>

int get_valid_height();
void print_pyramid(int height);
void driver(int lower, int upper);

int main(int argc, const char * argv[]) {
    using namespace std;

    cout << "This program prints a 'pyramid' shape of a specified height on the screen.\n\n";
    
    int height = get_valid_height();
    print_pyramid(height);
    return 0;
}

int get_valid_height(){
    using namespace std;
    int height;
    cout << "How high would you like the pyramid?: ";
    cin >> height;
    
    while (!(1 <= height && height <= 30)){
        cout << "Pick another height (must be between 1 and 30): ";
        cin >> height;
    }
    cout << endl;
    return height;
}

void print_pyramid(int height){
    using namespace std;
    for (int i = 1; i <= height; i++){
        for (int j = 1; j <= height - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2*i-1; j++){ // to get a pyramid with two stars on top (as seen in the question's example output), 2*i-1 --> 2*i 
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

void driver(int lower, int upper){
    for (int i = lower; i <= upper; i++){
        print_pyramid(i);
    }
}

