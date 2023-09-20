#include <iostream>
#include <string>

// defines shared properties of base classes
// growth rates, critical/accuracy bonuses, movement
// the option to set or receive these values for level ups and specific classes
class BaseClass {
    int growths[6];
    bool crit_bonus;
    bool acc_bonus;

    public: 
        void set_growths(int *arr, unsigned int);
        int* get_growths();
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
        // used to change the crit bonus boolean to on/off
        void turn_crit_bonus();
        int get_crit_bonus(unsigned int);

};

class Mercenary : private BaseClass{
    private:

    public:
        
};