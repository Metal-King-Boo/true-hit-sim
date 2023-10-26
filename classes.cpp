#include <iostream>
#include <string>

#include "classes.h"

// declarations used in BaseClass

// function to set the growth rates for each stat
// growths represent the 8 stats found in Fire Emblem
// [HP, ATK/MAG, SKL, SPD, LCK, DEF, RES, CON]
// it takes in an array and an unsigned int
void BaseClass::set_growths(int *arr, unsigned int x){
   // iterates through arr to apply the growths
   for(int i = 0; i < x; i++){
      growths[i] = arr[i];
   } 
}

// function to get the growth rates of a class
// returns an array
int* BaseClass::get_growths(){
   return growths;
}

// function to set the movement type of a class
// [Horse, Flier, Infantry, Armor]
// it takes in a string value
void BaseClass::set_type(std::string y){
   type = y;
}

// function to return the movement type of a class
// [Horse, Flier, Infantry, Armor]
// returns a string
std::string BaseClass::get_type(){
   return type;
}

// function to set the race of a class
// [Human, Dragon]
// it takes in a string value
void BaseClass::set_race(std::string y){
   race = y;
}

// function used to return the race of a class
// [Human, Dragon]
// returns a string
std::string BaseClass::get_race(){
   return race;
}

// function to set the name of a class
// [Myrmidon, Mercenary, Manakete, etc.]
// it takes in a string value
void BaseClass::set_name(std::string y){
   name = y;
}

// function used to return the name of a class
// [Pegasus Knight, Cavalier, Thief, etc.]
// returns a string
std::string BaseClass::get_name(){
   return name;
}

// testing function to display all information about a class
// displays all information from growths to race
// no parameters or return values
void BaseClass::display(){
   // this is a test function to see if the information is correct
   std::cout << name << " Statistics: \n";
   std::cout << "HP - " << growths[0] << "%         SPD - " << growths[3] << "%\n";
   std::cout << "ATK/MAG - " << growths[1] << "%    LCK - " << growths[4] << "%\n";
   std::cout << "SKL/DEX - " << growths[2] << "%    DEF - " << growths[5] << "%\n\n";
   std::cout << "RES - " << growths[6] << "%        CON - " << growths[7] << "%\n\n";
   std::cout << "Type: " << type << "\t Race: " << race << "\n\n";
}

/*
// UNUSED FEATURES
// CLASS BONUSES ARE ALREADY CALCULATED IN ARENA
// declarations used in Myrmidon
// class bonuses for each game
int Myrmidon::BB_CRIT_BONUS = 30;
int Myrmidon::BS_CRIT_BONUS = 15;
int Myrmidon::FS_CRIT_BONUS = 10;

// function to set the correct crit bonus based on game
void Myrmidon::set_crit_bonus(unsigned int x){
   switch (x)
   {
   case 5:
      crit_bonus = BB_CRIT_BONUS;
      break;
   case 6:
      crit_bonus = BS_CRIT_BONUS;
      break;
   case 13:
      crit_bonus = FS_CRIT_BONUS;      
   default:
      crit_bonus = 0;
      break;
   }
}

// function to get the crit bonus
int Myrmidon::get_crit_bonus(){
   return crit_bonus;
}
*/

