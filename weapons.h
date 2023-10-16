#include <iostream>
#include <string>

// defines the shared properties of all weapons found in the game
// might, weight, range, kills, crit rate, accuracy, triangle position, effectiveness, bonus stats, and brave effect
// features the option to set or receive these values for combat
class Weapon {
    std::string weapon_name;
    int weapon_might;
    int weapon_weight;
    int weapon_range[2];
    int weapon_kills;
    int weapon_crit;
    int weapon_accuracy;
    char weapon_triangle;
    std::string weapon_effective;
    int bonus_stats[6];
    bool brave;
    public:
        void set_name(std::string y);
        void set_weapon_might(unsigned int x);
        void set_weapon_weight(unsigned int x);
        void set_range(unsigned int x, unsigned int y);
        void set_weapon_kills(unsigned int x);
        void set_weapon_crit(unsigned int x);
        void set_weapon_accuracy(unsigned int x);
        void set_weapon_triangle(char triangle);
        void set_weapon_effective(std::string effective);
        void set_bonus_stats(int *arr, unsigned int x);
        void set_brave(bool hero);
        void display();
        
        std::string get_name();
        int get_weapon_might();
        int get_weapon_weight();
        int* get_range();
        int get_weapon_kills();
        int get_weapon_crit();
        int get_weapon_accuracy();
        char get_weapon_triangle();
        std::string get_weapon_effective();
        int* get_bonus_stats();
        bool get_brave();
};