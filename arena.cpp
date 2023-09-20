#include <iostream>
#include <cstdlib>
#include <time.h>

// weapon level is important

// function used to produce a random number
int randNum() {
    // the random number seed is generated based on the current time
    srand(time(0));
    
    // random number between 0 and 99 is picked and returned
    int number = rand() % 100;
    return number;
}
