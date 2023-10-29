#ifndef __HUD_H__
#define __HUD_H__

#include <SDL.h>
#include "entity.h"
#include "gf2d_sprite.h"
#include "gf2d_font.h"
#include "gf2d_draw.h"

/**
 * @brief Draws the heads up display for the player including the ammo of their currently
 * selected weapon and their current health
 * @param player is the player entity
*/
void draw_hud(Entity* player);

#endif
