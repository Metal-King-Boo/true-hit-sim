#include <iostream>

class Weapon {
    int weapon_might;
    int weapon_weight;
    int weapon_kills;
    int weapon_crit;
    int weapon_accuracy;

    // sometimes weapons apply bonus stats when wielded
    // this is seen a lot in FE14 but other weapons like the holy weapons in FE4 have them
    // Array Elements:  0 = HP, 1 = STR/MAG, 2 = SKL, 3 = SPD, 4 = LCK, 5 = RES 
    int bonus_stats[6];

    public:
        void set_weapon_might(unsigned int x);
        void set_weapon_weight(unsigned int x);
        void set_weapon_kills(unsigned int x);
        void set_weapon_crit(unsigned int x);
        void set_weapon_accuracy(unsigned int x);
        void set_bonus_stats(int *arr, unsigned int x);
        
        int get_weapon_might();
        int get_weapon_weight();
        int get_weapon_kills();
        int get_weapon_crit();
        int get_weapon_accuracy();
        int* get_bonus_stats();
};