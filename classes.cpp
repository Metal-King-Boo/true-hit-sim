#include <iostream>
#include <string>
#include "classes.h"

// declarations used in BaseClass
// function to set the growth rates for each stat
void BaseClass::set_growths(int *arr, unsigned int){

}

// function to get the growth rates of a class
int* BaseClass::get_growths(){

}

// testing function to display all information about a class
void BaseClass::display(){

}

// declarations used in Myrmidon
// class bonuses for each game
int Myrmidon::BB_CRIT_BONUS = 30;
int Myrmidon::BS_CRIT_BONUS = 15;
int Myrmidon::FS_CRIT_BONUS = 10;

// toggle to turn on crit bonus for this class
void Myrmidon::turn_crit_bonus(){

}

// function to get the correct crit bonus based on game
int Myrmidon::get_crit_bonus(unsigned int){

}

// declarations used in Mercenary



/*
   term index

   skl = skill stat
   wpn_bonus = weapon's bonus to crit or dodge rate e.g. Killing Edge +30 
   supp_bonus = bonus from being near support partner
   class_bonus = bonus from being a specific class i.e. Myrmidon
   kill_bonus = the amount times a weapon has killed someone is stored in the weapon (used ONLY in FE4)
   s_level_bonus = unit gets bonus crit if they have s rank in the equipped weapon
   dual_pair_bonus = bonus to stats based on the dual strike/pair up mechanic found in FE13 and FE14 these replace/work in conjunction with support bonuses
   skl_bonus = skills that increase the chance of critical hits
   tactician_bonus = boost to hit rate and avoid for matching mark's affinity, and a set boost to dodge regardless of affinity. +1 for every star (used ONLY in FE7) 
*/

/*
   crit formula for genealogy of the holy war
   without crit skill:
   (combo_bonus)
   with crit skill:
   (skill) + (kill_bonus - 50) + (combo_bonus)
   wrath:
   100%

   dodge formula for genealogy of the holy war
   ABSENT
*/

//Myrmidon Ayra;
//Mercenary Scathach;

/* 
   crit formula for binding blade
   (skl/2) + (wpn_bonus) + (supp_bonus) + (class_bonus)

   dodge formula for binding blade
   (lck/2) + (supp_bonus)
*/

//Myrmidon Rutger;
//Mercenary Echidna;

/*
   crit formula for blazing blade
   (skl/2) + (wpn_bonus) + (supp_bonus) + (class_bonus) + (s_level_bonus)

   dodge formula for blazing blade
   (lck) + (supp_bonus) + (tactician_bonus)
*/

//Myrmidon Guy;
//Mercenary Raven;

/*
   crit formula for fates
   (wpn_bonus) + [(skl - 4) / 2] + (dual_pair_bonus) + (skl_bonus) + (class_bonus)

   dodge formula for fates
   (lck/2) + (dual_pair_bonus) + (wpn_bonus) + (class_bonus)
*/

//Myrmidon Hana;
//using Nyx mother for growths
//Mercenary Soleil;
