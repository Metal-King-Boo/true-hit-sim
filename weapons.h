#include <iostream>

class Weapon {
    int weapon_might;
    int weapon_weight;
    int weapon_kills;
    int weapon_crit;
    int weapon_accuracy;
    // options are 'R', 'B', and 'G'
    // R loses to B, B loses to G, and G loses to R
    // R = Swords and Tomes, B = Lances and Hidden Weapons, G = Axes and Bows (Fates) 
    // options are 'W', 'T', 'F', 'L', 'D', 'A'
    // W beats T, T beats F, F beats W, and L/D beat W/T/F (Jugdral)
    // W = Wind Tomes, T = Thunder Tomes, F = Fire Tomes (Jugdral and Tellius)
    // A = Anima Tomes, L = Light Tomes, and D = Dark Tomes (GBA and Radiant Dawn)
    // A beats L, L beats D, and D beats (GBA)
    char weapon_triangle;
    std::string weapon_effective;

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
        void set_weapon_triangle(char triangle);
        void set_weapon_effective(std::string effective);
        void set_bonus_stats(int *arr, unsigned int x);
        
        int get_weapon_might();
        int get_weapon_weight();
        int get_weapon_kills();
        int get_weapon_crit();
        int get_weapon_accuracy();
        char get_weapon_triangle();
        std::string get_weapon_effective();
        int* get_bonus_stats();
};