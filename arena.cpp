#include <iostream>
#include <cstdlib>
#include <time.h>

// weapon level is important (especially S)
// might need a selector function to run a specific one of these functions based on game
// reaver weapons and light brand may make this weird
// need functions for getting the crit bool, weapon tri, and eff bonus

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

// ----------- SHARED FUNCTIONS -----------

// function used to produce a random number between 0 and 99
int randNum() {
    // the random number seed is generated based on the current time
    srand(time(0));
    
    // random number between 0 and 99 is picked and returned
    int number = rand() % 100;
    return number;
}

// --------- BINDING BLADE FUNCTIONS --------

// this function is used for binding blade attacks
int attack(int atk_stat, int wpn_might, int wpn_tri_bonus, bool eff_bonus, int supp_bonus) {
    int total_attack;
    
    // if statements for tri advantage and effective bonus
    // if both are true
    if(wpn_tri_bonus == 1 || eff_bonus == true){
        total_attack = atk_stat + ((wpn_might + 1) * 3) + supp_bonus;
    } 
    // if tri advantage is true and eff is false
    if(wpn_tri_bonus == 1 || eff_bonus == false){
        total_attack = atk_stat + ((wpn_might + 1) * 1) + supp_bonus;
    } 

    // if tri advantage is neutral and eff is true
    if(wpn_tri_bonus == 2 || eff_bonus == true){
        total_attack = atk_stat + ((wpn_might) * 3) + supp_bonus;
    } 
    // if tri advantage is neutral and eff is false
    if(wpn_tri_bonus == 2 || eff_bonus == false){
        total_attack = atk_stat + ((wpn_might) * 1) + supp_bonus;
    } 
    
    // if tri advantage is false and eff is true
    if(wpn_tri_bonus == 3 || eff_bonus == true){
        total_attack = atk_stat + ((wpn_might - 1) * 3) + supp_bonus;
    } 
    // if tri advantage is false and eff is false
    if(wpn_tri_bonus == 3 || eff_bonus == false){
        total_attack = atk_stat + ((wpn_might - 1) * 1) + supp_bonus;
    } 

    total_attack = atk_stat + ((wpn_might + wpn_tri_bonus) * eff_bonus) + supp_bonus;
    return total_attack;
}

// this function is used for binding blade defense
int defense(int def_res_stat, int supp_bonus, int terrain_bonus) {
    int total_defense;
    total_defense = def_res_stat + supp_bonus + terrain_bonus;
    return total_defense;
}

// this function is used for binding blade damage
int damage(bool critical, int total_attack, int total_defense){
    int total_damage;
    
    // if statement for passing or failing a critical hit
    if(critical){
        total_damage = (total_attack - total_defense) * 3;
    } else {
        total_damage =(total_attack - total_defense) * 1;
    }
    
    return total_damage;
}

// this function is used for binding blade crit chance
int critChance(int skl_stat, int class_bonus, int wpn_bonus, int supp_bonus) {
    int total_crit = (skl_stat / 2) + wpn_bonus + supp_bonus + class_bonus;
    return total_crit;
}

// this function is used for binding blade dodge chance
int dodgeChance(int lck_stat, int supp_bonus) {
    int total_dodge = (lck_stat / 2) + supp_bonus;
    return total_dodge;
}

// this function is used for binding blade accuracy

// this function is used for binding blade avoid

// this function is used for binding blade battle accuracy

// this function is used for binding blade action speed (used for determining double attacks)

// ---------- BLAZING SWORD FUNCTIONS ----------

// this function is used for blazing sword attacks
int attack(int atk_stat, int wpn_might, int wpn_tri_bonus, int eff_bonus, int supp_bonus) {
    int total_attack;
    total_attack = atk_stat + ((wpn_might + wpn_tri_bonus) * eff_bonus) + supp_bonus;
    return total_attack;
}

// this function is used for blazing sword crit chance
int critChance(int skl_stat, int class_bonus, int wpn_bonus, int supp_bonus, int s_level_bonus) {
    int total_crit = (skl_stat / 2) + wpn_bonus + supp_bonus + class_bonus + s_level_bonus;
    return total_crit;
}

// this function is used for blazing sword dodge chance
int dodgeChance(int lck_stat, int supp_bonus, int tactician_bonus) {
    int total_dodge = lck_stat + supp_bonus + tactician_bonus;
    return total_dodge;
}