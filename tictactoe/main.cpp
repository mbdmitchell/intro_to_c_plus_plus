//
//  main.cpp
//  tictactoe
//
//  Created by Max Mitchell on 18/08/2022.
//

#include <iostream>
#include "header.h"

int main(){
    using namespace std;
    
    introduction();
    
    while (wantGame() == true)
    {
        startGame();
    }

    ending();
    
    return 0;
}

