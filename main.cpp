#include <iostream>
#include <string>
#include "classes.h"
#include "characters.h"
#include "weapons.h"
#include "arena.cpp"

struct Myrmid {
    Character character;
    Myrmidon myrmidon;
    Weapon weapon;
};

struct Merc {
    Character character;
    Mercenary mercenary;
    Weapon weapon;
};

int main() {
    Myrmid rutger;
    Merc echidna;
    int rng = randNum();
    
    return 0;
}