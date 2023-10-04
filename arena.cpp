#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

// weapon level is important (especially S)
// might need a selector function to run a specific one of these functions based on game
// reaver weapons and light brand may make this weird

/*
   term index

   skl = skill stat
   con = constitution stat
   lck = luck stat
   eff_bonus = bonus when hitting a target especially weak to the weapon e.g. Bows + Fliers
   wpn_hit = weapon's innate hit rate
   wpn_weight = weapon's weight
   wpn_bonus = weapon's bonus to crit or dodge rate e.g. Killing Edge +30 
   wpn_tri_bonus = weapon triangle bonus found in various games (works like RPS)
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

// -------------------- SHARED FUNCTIONS --------------------

// function used to produce a random number between 0 and 99
int randNum() {
    // the random number seed is generated based on the current time
    srand(time(0));
    
    // random number between 0 and 99 is picked and returned
    int number = rand() % 100;
    return number;
}

// functions used to check if the attack will connect
// this one is used for games with the true hit system
bool trueHitCheck(int battle_hit_rate) {
    int seed;

    seed = (randNum() + randNum()) / 2;

    // from 0-99 it checks if the value is larger than the battle_hit_rate
    // if it is then the attack did not connect, if not then it did 
    if(seed > battle_hit_rate) {
        return false;
    } else {
        return true;
    }
    
}

// this one is used for games with the old accuracy system
bool hitCheck(int battle_hit_rate) {
    int seed;

    seed = randNum();

    // from 0-99 it checks if the value is larger than the battle_hit_rate
    // if it is then the attack did not connect, if not then it did 
    if(seed > battle_hit_rate) {
        return false;
    } else {
        return true;
    }
    
}

// function used to check if the attack will be a critical hit
bool criticalCheck(int crit_rate) {
    int seed;
    seed = randNum();

    // from 0-99 it checks if the value is larger than the crit_rate
    // if it is then the attack did not crit, if not then it did
    if(seed > crit_rate){
        return false;
    } else {
        return true;
    }
}

// function used to check the weapon triangle
int weaponTriangle(char weapon_one, char weapon_two) {
    // use case if the weapon is R(Red) in the triangle
    if(weapon_one == 'R'){
        // R beat G, but loses to B
        if(weapon_two == 'G'){
            return 1;
        } else if(weapon_two == 'B'){
            return 3;
        } else {
            return 2;
        }
    }

    // use case if weapon is G(Green) in the triangle
    if(weapon_one == 'G'){
        // G beats B, but loses to R
        if(weapon_two == 'B'){
            return 1;
        } else if(weapon_two == 'R'){
            return 3;
        } else {
            return 2;
        }
    }

    // use case if weapon is B(Blue) in the triangle
    if(weapon_one == 'B'){
        // B beats R, but loses to G
        if(weapon_two == 'R'){
            return 1;
        } else if(weapon_two == 'G'){
            return 3;
        } else {
            return 2;
        }
    }

    // use case if weapon is A(Anima) in the triangle
    if(weapon_one == 'A'){
        // A beats L, but loses to D
        if(weapon_two == 'L'){
            return 1;
        } else if(weapon_two == 'D'){
            return 3;
        } else {
            return 2;
        }
    }

    // use case if weapon is L(Light) in the triangle
    if(weapon_one == 'L'){
        // L beats D, but loses to A
        if(weapon_two == 'D'){
            return 1;
        } else if(weapon_two == 'A'){
            return 3;
        } else {
            return 2;
        }
    }

    // use case if weapon is D(Dark) in the triangle
    if(weapon_one == 'D'){
        // D beats A but loses to L
        if(weapon_two == 'A'){
            return 1;
        } else if(weapon_two == 'L'){
            return 3;
        } else {
            return 2;
        }
    }

}

// function used to check the weapon effectiveness
bool weaponEffectiveness(std::string wpn_type, std::string unit_type, std::string unit_race){
    // checks for things like fliers, horses, armor, etc. 
    if(wpn_type == unit_type) {
        return true;
    }

    // checks for things like laguz and dragons
    if(wpn_type == unit_race) {
        return true;
    }

    // returns false if no effectiveness
    return false;
}

// -------------------- BINDING BLADE FUNCTIONS --------------------

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
    
    total_damage = (total_attack - total_defense);

    // prevention of negative numbers
    if(total_damage <= 0){
        total_damage = 0;
    }
    
    // if statement for passing or failing a critical hit
    if(critical){
        total_damage = total_damage * 3;
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
int accuracy(int wpn_hit, int skl_stat, int lck_stat, int wpn_tri_bonus, int supp_bonus) {
    int total_accuracy;

    total_accuracy = wpn_hit + (skl_stat / 2) + (lck_stat / 2) + supp_bonus;

    // if triangle advantage
    if(wpn_tri_bonus == 1){
        total_accuracy = total_accuracy + 10;
    } 
    // if triangle disadvantage
    if(wpn_tri_bonus == 3){
        total_accuracy = total_accuracy - 10;
    }

    return total_accuracy;
}

// this function is used for binding blade avoid
int avoid(int total_attack_speed, int lck_stat, int supp_bonus, int terrain_bonus) {
    int total_avoid;
    total_avoid = (total_attack_speed * 2) + lck_stat + supp_bonus + terrain_bonus;
    return total_avoid;
}
// this function is used for binding blade battle accuracy
int battleAccuracy(int total_accuracy, int total_avoid) {
    int battle_accuracy;
    battle_accuracy = total_accuracy - total_avoid;
    
    // prevention of getting negative numbers
    if(battle_accuracy <= 0){
        battle_accuracy = 0;
    }
    return battle_accuracy;
}
// this function is used for binding blade action speed (used for determining double attacks and avoid)
int attackSpeed(int spd_stat, int wpn_weight, int con_stat) {
    int attack_speed;
    int muscle;
    muscle = wpn_weight - con_stat;

    // prevention of getting negative numbers
    if(muscle <= 0){
        muscle = 0;
    }

    attack_speed = spd_stat - muscle;

    // prevention of getting negative numbers
    if(attack_speed <= 0){
        attack_speed = 0;
    }

    return attack_speed;
}

// -------------------- BLAZING SWORD FUNCTIONS --------------------

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