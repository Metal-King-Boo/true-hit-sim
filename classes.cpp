#include <iostream>

class Myrmidon {
    public:
        int hp_growth;
        int atk_growth;
        int skl_growth;
        int spd_growth;
        int lck_growth;
        int res_growth;

        int crit_bonus;
        int acc_bonus;
};

class Mercenary {
    public:
        int hp_growth;
        int atk_growth;
        int skl_growth;
        int spd_growth;
        int lck_growth;
        int res_growth;

        int crit_bonus;
        int acc_bonus;
};

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

Myrmidon Ayra;
Mercenary Scathach;

/* 
   crit formula for binding blade
   (skl/2) + (wpn_crit) + (supp_bonus) + (class_bonus)

   dodge formula for binding blade
   (lck/2) + (supp_bonus)

   skl = skl stat
   wpn_crit = weapon's natural crit rate e.g. Killing Edge +30 
   supp_bonus = bonus from being near support partner
   class_bonus = bonus from being a specific class i.e. Myrmidon
*/

Myrmidon Rutger;
Mercenary Echidna;

/*
   crit formula for blazing blade

*/

Myrmidon Guy;
Mercenary Raven;

/*

*/

Myrmidon Hana;
//using Nyx mother for growths
Mercenary Soleil;
