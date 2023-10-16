#include <iostream>
#include <string>
#pragma once

// defines the shared properties of all base classes found in the game
// growth rates, movement type, class race, and class name
// features the option to set or receive these values for combat and level ups
class BaseClass {
    int growths[7];
    std::string type;
    std::string race;
    std::string name;
    public: 
        void set_growths(int *arr, unsigned int x);
        void set_type(std::string y);
        void set_race(std::string y);
        void set_name(std::string y);
        void display();

        int* get_growths();
        std::string get_type();
        std::string get_race();
        std::string get_name();
};


// UNUSED FEATURE
// CLASS BONUSES ARE ALREADY CALCULATED IN ARENA
// the speed type swordsman class 
// features the bonuses it has in the games relevant to comparison
/*class Myrmidon : public BaseClass{
    private:
        // 30 for binding, 15 for blazing, 10 for fates
        static int BB_CRIT_BONUS;
        static int BS_CRIT_BONUS;
        static int FS_CRIT_BONUS;

    public:
        // used to set the crit bonus for a specific game
        void set_crit_bonus(unsigned int x);
        // used to return the crit bonus for a specific game
        int get_crit_bonus();

};*/

/*class Mercenary : public BaseClass{
    private:

    public:
        
};*/