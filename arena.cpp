#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

// weapon level is important (especially S) [FE5]
// might need a selector function to run a specific one of these functions based on game
// reaver weapons and light brand may make this weird [next update ver]

/*
   TERM INDEX

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

// -------------------- SHARED FUNCTIONS --------------------

// function used to produce a random number between 0 and 99
int randNum() {
    // random number between 0 and 99 is picked and returned
    int number = rand() % 100;
    return number;
}

// hit confirm function used for games with the true hit system
// [(rand1 + rand2) / 2]
// it takes in the battle hit rate as an int
// returns true or false
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

// hit confirm function used for games with the old accuracy system
// [rand]
// it takes in the battle hit rate as an int
// returns true or false
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
// it takes in the battle crit rate(crit_rate - dodge_rate) as an int
// returns true or false
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
// it takes in the char triangle of both weapons
// [1 = advantage, 2 = neutral, 3 = disadvantage]
// returns 1, 2, or 3 as an int
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

    return 2;
}

// function used to check the weapon effectiveness
// [Horse, Flier, Infantry, Dragon, Armor, etc.]
// it takes in unit type, unit race
// returns true or false
bool weaponEffectiveness(std::string wpn_type, std::string unit_type, std::string unit_race){
    // checks for things like fliers, horses, armor, etc. 
    if(wpn_type == unit_type) {
        return true;
    }

    // checks for things like laguz, dragons, or monsters/terrors
    if(wpn_type == unit_race) {
        return true;
    }

    // returns false if no effectiveness
    return false;
}

// -------------------- BINDING BLADE FUNCTIONS --------------------

// function used for binding blade attack calculation
// different branches of damage based on triangle advantage, support bonus, and weapon effectiveness
// returns an int
int attack(int atk_stat, int wpn_might, int wpn_tri_bonus, bool eff_bonus, int supp_bonus) {
    int total_attack;
    
    // if statements for tri advantage and effective bonus
    // if both are true
    if(wpn_tri_bonus == 1 && eff_bonus == true){
        total_attack = atk_stat + ((wpn_might + 1) * 3) + supp_bonus;
    } 
    // if tri advantage is true and eff is false
    if(wpn_tri_bonus == 1 && eff_bonus == false){
        total_attack = atk_stat + ((wpn_might + 1) * 1) + supp_bonus;
    } 
    // if tri advantage is neutral and eff is true
    if(wpn_tri_bonus == 2 && eff_bonus == true){
        total_attack = atk_stat + ((wpn_might) * 3) + supp_bonus;
    } 
    // if tri advantage is neutral and eff is false
    if(wpn_tri_bonus == 2 && eff_bonus == false){
        total_attack = atk_stat + ((wpn_might) * 1) + supp_bonus;
    } 
    // if tri advantage is false and eff is true
    if(wpn_tri_bonus == 3 && eff_bonus == true){
        total_attack = atk_stat + ((wpn_might - 1) * 3) + supp_bonus;
    } 
    // if tri advantage is false and eff is false
    if(wpn_tri_bonus == 3 && eff_bonus == false){
        total_attack = atk_stat + ((wpn_might - 1) * 1) + supp_bonus;
    } 

    //total_attack = atk_stat + ((wpn_might + wpn_tri_bonus) * eff_bonus) + supp_bonus;
    return total_attack;
}

// function used for binding blade defense calculation
// damage reduction based on the defensive stat, support bonus, and terrain bonus
// returns an int
int defense(int def_res_stat, int supp_bonus, int terrain_bonus) {
    int total_defense;
    total_defense = def_res_stat + supp_bonus + terrain_bonus;
    return total_defense;
}

// function used for binding blade damage calculation
// takes the values from attack() and defense() and critical boolean
// returns an int
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

// function used for binding blade crit chance
// takes the skill stat, weapon crit, support bonus, and class name to get a unit's crit chance
// returns an int
int critChance(int skl_stat, int wpn_bonus, int supp_bonus, std::string class_name) {
    int total_crit;

    // class bonus for critical hits
    if(class_name == "Berserker" || class_name == "Swordmaster"){
        // this calculation rounds down
        total_crit = (skl_stat / 2) + wpn_bonus + supp_bonus + 30;
    } else{
        total_crit = (skl_stat / 2) + wpn_bonus + supp_bonus;
    }
    
    return total_crit;
}

// function used for binding blade dodge chance
// takes luck stat and support bonus to calculate unit's total dodge chance
// used for reducing/dodging crit hits (not to be confused with avoid)
// returns an int
int dodgeChance(int lck_stat, int supp_bonus) {
    // this calculation rounds down
    int total_dodge = (lck_stat / 2) + supp_bonus;
    return total_dodge;
}

// function used for binding blade battle crit chance
// the actual crit chance used in combat when confirming critical hits
// takes attacker's total crit and defender's total dodge (not to be confused with avoid)
// returns an int
int battleCritChance(int total_crit, int total_dodge) {
    int battle_crit_rate;
    
    battle_crit_rate = total_crit - total_dodge;

    // prevention of getting negative numbers
    if(battle_crit_rate <= 0){
        battle_crit_rate = 0;
    }
    return battle_crit_rate;
}

// function used for binding blade accuracy
// takes weapon accuracy, skill stat, luck stat, weapon triangle and support bonus
// returns an int
int accuracy(int wpn_hit, int skl_stat, int lck_stat, int wpn_tri_bonus, int supp_bonus) {
    int total_accuracy;

    // this calculation rounds down
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

// function used for binding blade avoid
// takes attack speed, luck stat, support bonus, and terrain bonus
// used for avoiding damage
// returns an int
int avoid(int total_attack_speed, int lck_stat, int supp_bonus, int terrain_bonus) {
    int total_avoid;

    total_avoid = (total_attack_speed * 2) + lck_stat + supp_bonus + terrain_bonus;

    return total_avoid;
}

// function used for binding blade battle accuracy
// the actual accuracy used when confirming hits
// takes attacker's accuracy and defender's avoid
// returns an int
int battleAccuracy(int total_accuracy, int total_avoid) {
    int battle_accuracy;
    
    battle_accuracy = total_accuracy - total_avoid;
    
    // prevention of getting negative numbers
    if(battle_accuracy <= 0){
        battle_accuracy = 0;
    }
    return battle_accuracy;
}
// function used for binding blade action speed
// used for determining double attacks and avoid
// takes speed stat, weapon weight, and constitution stat
// returns an int
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
/*
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
}*/