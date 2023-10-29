#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "entity.h"

/**
 * @brief Create a new player entity
 * @param position where to spawn the aguman at
 * @return NULL on error, or an player entity pointer on success
 */
Entity *player_new(Vector3D position);

/**
 * @brief Initializes weapon data (ammo, fire rate, etc)
 * @param self is the player
*/
void init_weapon_data(Entity *self);


#endif
