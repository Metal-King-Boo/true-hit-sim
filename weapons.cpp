#include <iostream>
#include <string>

#include "weapons.h"


// options are 'R', 'B', and 'G'
    // R loses to B, B loses to G, and G loses to R
    // R = Swords and Tomes, B = Lances and Hidden Weapons, G = Axes and Bows (Fates) 
    // options are 'W', 'T', 'F', 'L', 'D', 'A'
    // W beats T, T beats F, F beats W, and L/D beat W/T/F (Jugdral)
    // W = Wind Tomes, T = Thunder Tomes, F = Fire Tomes (Jugdral and Tellius)
    // A = Anima Tomes, L = Light Tomes, and D = Dark Tomes (GBA and Radiant Dawn)
    // A beats L, L beats D, and D beats A (GBA)


// sometimes weapons apply bonus stats when wielded
    // this is seen a lot in FE14 but other weapons like the holy weapons in FE4 have them
    // Array Elements:  0 = HP, 1 = STR/MAG, 2 = SKL, 3 = SPD, 4 = LCK, 5 = RES 


// declarations of Weapons functions

// function that sets the weapon name
void Weapon::set_name(std::string y){
    weapon_name = y;
}
// function that returns the weapon name
std::string Weapon::get_name(){
    return weapon_name;
}

// function that sets how strong a weapon is
void Weapon::set_weapon_might(unsigned int x){
    weapon_might = x;
}

// function that returns the weapon's strength
int Weapon::get_weapon_might(){
    return weapon_weight;
}

// function that sets how heavy a weapon is
void Weapon::set_weapon_weight(unsigned int x){
    weapon_weight = x;
}

// function that returns the weapon's weight
int Weapon::get_weapon_weight(){
    return weapon_weight;
}

// function that sets weapon range
void Weapon::set_range(unsigned int x, unsigned int y){
    weapon_range[0] = x;
    weapon_range[1] = y; 
}

// function that returns weapon range
int* Weapon::get_range(){
    return weapon_range;
}

// function that sets the weapon's kill count (FEATURE ONLY USED IN FE4)
// DEFAULT VALUE SHOULD BE ZERO;
void Weapon::set_weapon_kills(unsigned int x){
    weapon_kills = x;
}

// function that returns the weapon's kill count
int Weapon::get_weapon_kills(){
    return weapon_kills;
}

// function that sets the weapon's natural crit rate
void Weapon::set_weapon_crit(unsigned int x){
    weapon_crit = x;
}

// function that returns the weapon's natural crit rate
int Weapon::get_weapon_crit(){
    return weapon_crit;
}

// function that sets the weapon's accuracy
void Weapon::set_weapon_accuracy(unsigned int x){
    weapon_accuracy = x;
}

// function that returns the weapon's accuracy
int Weapon::get_weapon_accuracy(){
    return weapon_accuracy;
}

// function that sets the weapon's triangle position
void Weapon::set_weapon_triangle(char triangle){
    weapon_triangle = triangle;
}

// function that returns the weapon's triangle position
char Weapon::get_weapon_triangle(){
    return weapon_triangle;
}

// function that sets the weapon's unit effectiveness
void Weapon::set_weapon_effective(std::string effective){
    weapon_effective = effective;
}
// function that returns the weapon's unit effectiveness
std::string Weapon::get_weapon_effective(){
    return weapon_effective;
}

// function that sets any bonus stats a weapon has
void Weapon::set_bonus_stats(int *arr, unsigned int x){
    // iterates through arr to match up with the standard stat order
    for(int i = 0; i < x; i++){
        bonus_stats[i] = arr[i];
    }
}

// function that returns any bonus stats a weapon has
int* Weapon::get_bonus_stats(){
    return bonus_stats;
}

// function that sets if weapon has brave effect or not
void Weapon::set_brave(bool hero){
    brave = hero;
}

// function that returns if weapon has brave effect or not
bool Weapon::get_brave(){
    return brave;
}

void Weapon::display(){
    std::cout << weapon_name << "\n";
    std::cout << "Might: " << weapon_might << "   Hit: " << weapon_accuracy << "\n";
    std::cout << "Crit: " << weapon_crit << "   Range: " << weapon_range[0] << "-" << weapon_range[1] << "\n";
    std::cout << "Triangle: " << weapon_triangle << "   Kills: " << weapon_kills << "\n";
    std::cout << "Eff: " << weapon_effective << "   Brave: " << brave << "\n";
    std::cout << "Bonuses: \nSTR/MAG - " << bonus_stats[1] << "   SKL/DEX - " << bonus_stats[2] << "\nSPD - " << bonus_stats[3] << "       LCK: " << bonus_stats[4] << "\nRES - " << bonus_stats[5] << "\n\n";
}