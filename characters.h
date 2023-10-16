#include <iostream>
#include <string>
#include "classes.h"

// defines the shared properties of all characters found in the game
// stats, growth rates, and level
// features the option to set or receive these values for combat and level ups
class Character {
    int stats[7];
    int growths[7];
    int level;
    public:
        void set_stats(int* arr, unsigned int x);
        void set_growths(int* arr, unsigned int x);
        void set_level(unsigned int x);
        void display();

        int* get_stats();
        int* get_growths();
        int get_level();

};