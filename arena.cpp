#include <iostream>
#include <cstdlib>
#include <time.h>

// weapon level is important (especially S)
// might need a selector function to run a specific one of these functions based on game

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

/*
   crit formula for fates
   (wpn_bonus) + [(skl - 4) / 2] + (dual_pair_bonus) + (skl_bonus) + (class_bonus)

   dodge formula for fates
   (lck/2) + (dual_pair_bonus) + (wpn_bonus) + (class_bonus)
*/

//Myrmidon Hana;
//using Nyx mother for growths
//Mercenary Soleil;


// function used to produce a random number between 0 and 99
int randNum() {
    // the random number seed is generated based on the current time
    srand(time(0));
    
    // random number between 0 and 99 is picked and returned
    int number = rand() % 100;
    return number;
}

// functions used to calculate critical chance based on game

// this function is used for binding blade crit chance
int critChance(int skl_stat, int class_bonus, int wpn_bonus, int supp_bonus) {
    int total_crit = (skl_stat / 2) + wpn_bonus + supp_bonus + class_bonus;
    return total_crit;
}

// this function is used for blazing sword crit chance
int critChance(int skl_stat, int class_bonus, int wpn_bonus, int supp_bonus, int s_level_bonus) {
    int total_crit = (skl_stat / 2) + wpn_bonus + supp_bonus + class_bonus + s_level_bonus;
    return total_crit;
}

// functions used to calculate the dodge chance based on game
// remember this is not for evading an attack but for lowering the opponent's critical chance

// this function is used for binding blade dodge chance
int dodgeChance(int lck_stat, int supp_bonus) {
    int total_dodge = (lck_stat / 2) + supp_bonus;
    return total_dodge;
}

// this function is used for blazing sword dodge chance
int dodgeChance(int lck_stat, int supp_bonus, int tactician_bonus) {
    int total_dodge = lck_stat + supp_bonus + tactician_bonus;
    return total_dodge;
}