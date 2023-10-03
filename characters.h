#include <iostream>
#include <string>
#include "classes.h"

class Character {
    int stats[6];
    int growths[6];
    int level;
    public:
        void set_stats(int* arr, unsigned int x);
        void set_growths(int* arr, unsigned int x);
        void set_level(unsigned int x);

        int* get_stats();
        int* get_growths();
        int get_level();

};