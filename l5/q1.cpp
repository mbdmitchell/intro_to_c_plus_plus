//
//  main.cpp
//  Ex 5, Q1
//  Write a function which takes a single integer parameter, and returns "True" if and only if the integer is a prime number between 1 and 1000
//  Test your function by calling it from an appropriate "driver" program with different inputs.
//
//  NB: For this question we couldn't use the bool data type. 
//  I have added comments on how I would rewrite this with bool (beginning with -->)
//
//  Created by Max Mitchell on 13/09/2022.
//

#include <iostream>
#include <math.h> // sqrt

const int LOWER = 1;
const int UPPER = 1000;

enum logical {False, True}; // --> remove

logical isValidPrime(int num); // --> bool isValidPrime(int num). 
// If it were allowed by the question, I would also rewrite this to include two more parameters: the smallest and largest valid numbers (here 1 and 1000) and remove the global consts 

void driver(int lower, int upper);
    
int main(int argc, const char * argv[]) {
    
    driver(LOWER, UPPER);
    
    return 0;
}


logical isValidPrime(int num){ // --> bool isValidPrime(int num)
  
    // Check in range
    if (!(LOWER <= num && num <= UPPER)) return False; // --> "... return false"
  
    // Check is prime
    if (num == 1) return False; // --> "... return false"
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return False; // --> "... return false"
    }
    return True;
}

void driver(int lower, int upper){
    using namespace std;
    for (int i = lower; i <= upper; i++) {
        if (isValidPrime(i) == True){ // --> if (isValidPrime(i)){
            cout << i << endl;
        }
    }
}

