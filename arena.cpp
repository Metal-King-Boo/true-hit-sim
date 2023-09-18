#include <iostream>
#include <cstdlib>
#include <time.h>


// function used to produce a random number
int randNum() {
    // the random number seed is generated based on the current time
    srand(time(0));

    int number = rand() % 100;
    return number;
}

int main() {
    
    
    return 0;    
}