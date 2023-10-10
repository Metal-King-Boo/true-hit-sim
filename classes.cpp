#include <iostream>
#include <string>

#include "classes.h"

// declarations used in BaseClass
// function to set the growth rates for each stat
void BaseClass::set_growths(int *arr, unsigned int x){
   // loop to set the growth rates starts from the first element of arr
   // x represents the arr length
   for(int i = 0; i < x; i++){
      growths[i] = arr[i];
   } 
}

// function to get the growth rates of a class
int* BaseClass::get_growths(){
   // simply just return the array
   return growths;
}

// function to set the unit type of a class
void BaseClass::set_type(std::string y){
   // simply sets the value to a string name
   type = y;
}

// function to return the type of a class
std::string BaseClass::get_type(){
   return type;
}

// function to set the race of a class
void BaseClass::set_race(std::string y){
   race = y;
}

// function used to return the race of a class
std::string BaseClass::get_race(){
   return race;
}

// function to set the name of a class
void BaseClass::set_name(std::string y){
   name = y;
}

// function used to return the name of a class
std::string BaseClass::get_name(){
   return name;
}

// testing function to display all information about a class
void BaseClass::display(){
   // this is a test function to see if the information is correct
   std::cout << name << " Statistics: \n";
   std::cout << "HP - " << growths[0] << "%         SPD - " << growths[3] << "%\n";
   std::cout << "ATK/MAG - " << growths[1] << "%    LCK - " << growths[4] << "%\n";
   std::cout << "SKL/DEX - " << growths[2] << "%    RES - " << growths[5] << "%\n\n";
   std::cout << "CON - " << growths[6] << "%\n\n";
   std::cout << "Type: " << type << "\t Race: " << race << "\n\n";
}

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

// declarations used in Mercenary
