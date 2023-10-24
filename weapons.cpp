#include <iostream>
#include <string>

#include "weapons.h"

// R = Swords and Tomes, B = Lances and Hidden Weapons, G = Axes and Bows (Fates) 

// options are 'W', 'T', 'F', 'L', 'D', 'A'
// W = Wind Tomes, T = Thunder Tomes, F = Fire Tomes (Jugdral and Tellius)
// W beats T, T beats F, F beats W, and L/D beat W/T/F (Jugdral)
// A = Anima Tomes, L = Light Tomes, and D = Dark Tomes (GBA and Radiant Dawn)
// A beats L, L beats D, and D beats A (GBA)

// declarations of Weapons functions

// function that sets the weapon name
// it takes in a string value
void Weapon::set_name(std::string y){
    weapon_name = y;
}
// function that returns the weapon name
// returns a string
std::string Weapon::get_name(){
    return weapon_name;
}

// function that sets how strong a weapon is
// values should be positive
// it takes in an unsigned int
void Weapon::set_weapon_might(unsigned int x){
    weapon_might = x;
}

// function that returns the weapon's strength
// returns an int
int Weapon::get_weapon_might(){
    return weapon_weight;
}

// function that sets how heavy a weapon is
// should normally be positive
// it takes in an unsigned int
void Weapon::set_weapon_weight(unsigned int x){
    weapon_weight = x;
}

// function that returns the weapon's weight
// returns an int
int Weapon::get_weapon_weight(){
    return weapon_weight;
}

// function that sets weapon range
// the first value should be smaller than the second value
// it takes in two unsigned ints
void Weapon::set_range(unsigned int x, unsigned int y){
    weapon_range[0] = x;
    weapon_range[1] = y; 
}

// function that returns weapon range
// returns an array
int* Weapon::get_range(){
    return weapon_range;
}

// function that sets the weapon's kill count (FEATURE ONLY USED IN FE4)
// default value should be zero;
// it takes in an unsigned int
void Weapon::set_weapon_kills(unsigned int x){
    weapon_kills = x;
}

// function that returns the weapon's kill count (FEATURE ONLY USED IN FE4)
// returns an int
int Weapon::get_weapon_kills(){
    return weapon_kills;
}

// function that sets the weapon's natural crit rate
// values should be positive (most cases)
// it takes in an unsigned int
void Weapon::set_weapon_crit(unsigned int x){
    weapon_crit = x;
}

// function that returns the weapon's natural crit rate
// returns an int
int Weapon::get_weapon_crit(){
    return weapon_crit;
}

// function that sets the weapon's accuracy
// values should be positive (most cases)
// it takes in an unsigned int
void Weapon::set_weapon_accuracy(unsigned int x){
    weapon_accuracy = x;
}

// function that returns the weapon's accuracy
// returns an int
int Weapon::get_weapon_accuracy(){
    return weapon_accuracy;
}

// function that sets the weapon's triangle position
// options are 'R' (Sword), 'B' (Lance), 'G' (Axe), 'A'(Anima), 'L'(Light), 'D' (Dark)
// [R > G > B > R] and [A > L > D > A]
// it takes in a char
void Weapon::set_weapon_triangle(char triangle){
    weapon_triangle = triangle;
}

// function that returns the weapon's triangle position
// returns a char value
char Weapon::get_weapon_triangle(){
    return weapon_triangle;
}

// function that sets the weapon's unit effectiveness
// [Flier, Armor, Infantry, Horse, Dragon, etc.]
// it takes in a string
void Weapon::set_weapon_effective(std::string effective){
    weapon_effective = effective;
}
// function that returns the weapon's unit effectiveness
// [Flier, Armor, Infantry, Horse, Dragon, etc.]
// returns a string value
std::string Weapon::get_weapon_effective(){
    return weapon_effective;
}

// function that sets any bonus stats a weapon has
// [HP, ATK/MAG, SKL, SPD, LCK, RES]
// it takes in an array and an unsigned int
void Weapon::set_bonus_stats(int *arr, unsigned int x){
    // iterates through arr to match up with the standard stat order
    for(int i = 0; i < x; i++){
        bonus_stats[i] = arr[i];
    }
}

// function that returns any bonus stats a weapon has
// [HP, ATK/MAG, SKL, SPD, LCK, RES]
// returns an array
int* Weapon::get_bonus_stats(){
    return bonus_stats;
}

// function that sets if weapon has brave effect or not
// brave effect makes a weapon attack twice instead of once
// it takes in a boolean
void Weapon::set_brave(bool hero){
    brave = hero;
}

// function that returns if weapon has brave effect or not
// returns a boolean
bool Weapon::get_brave(){
    return brave;
}

// testing function to display all information about a class
// displays all information from might to bonuses
// no parameters or return values
void Weapon::display(){
    std::cout << weapon_name << "\n";
    std::cout << "Might: " << weapon_might << "   Hit: " << weapon_accuracy << "\n";
    std::cout << "Crit: " << weapon_crit << "   Range: " << weapon_range[0] << "-" << weapon_range[1] << "\n";
    std::cout << "Triangle: " << weapon_triangle << "   Kills: " << weapon_kills << "\n";
    std::cout << "Eff: " << weapon_effective << "   Brave: " << brave << "\n";
    std::cout << "Bonuses: \nSTR/MAG - " << bonus_stats[1] << "   SKL/DEX - " << bonus_stats[2] << "\nSPD - " << bonus_stats[3] << "       LCK: " << bonus_stats[4] << "\nRES - " << bonus_stats[5] << "\n\n";
}