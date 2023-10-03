#include <iostream>
#include <string>

// defines shared properties of base classes
// growth rates, critical/accuracy bonuses, movement
// the option to set or receive these values for level ups and specific classes
class BaseClass {
    // growths represents the 6 stats found in ALL Fire Emblem games
    // hp, atk/mag, skl, spd, lck, res
    int growths[6];
    // this describes unit type (armor, horse, flier, infantry, etc.)
    std::string type;

    public: 
        int crit_bonus;
        bool acc_bonus;

        void set_growths(int *arr, unsigned int x);
        int* get_growths();
        void set_type(std::string y);
        std::string get_type();
        void display();
};

// the speed type swordsman class 
// features the bonuses it has in the games relevant to comparison
class Myrmidon : private BaseClass{
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

};

class Mercenary : private BaseClass{
    private:

    public:
        
};