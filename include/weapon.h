#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "entity.h"

typedef enum{
    revolver = 0,
    repeater,
    shotgun,
    dynamite,
    throwing_knife
}PlayerWeapon;

typedef struct WeaponData_S{
    //total ammo player is carrying (minus whatever is loaded into the gun)
    Uint32 revolverAmmo;
    Uint32 repeaterAmmo;
    Uint32 shotgunShells;
    Uint32 sticksDynamite;
    Uint32 throwingKnives;
    
    //maximum ammo a player can carry for a weapon
    Uint32 revolverMax;
    Uint32 repeaterMax;
    Uint32 shotgunMax;
    Uint32 dynamiteMax;
    Uint32 knivesMax;

    //ammo capacity of a weapon
    Uint32 revolverCap;
    Uint32 repeaterCap;
    Uint32 shotgunCap;
    Uint32 dynamiteCap;
    Uint32 knivesCap;

    //current ammo of a weapon
    Uint32 revolverCurrent;
    Uint32 repeaterCurrent;
    Uint32 shotgunCurrent;
    Uint32 dynamiteCurrent;
    Uint32 knivesCurrent;

    //weapon fire rates
    float revolverRate;
    float repeaterRate;
    float shotgunRate;
    float dynamiteRate;
    float knivesRate;

}WeaponData;

//need a hitscan fire and projectile fire as well as reload.

#endif