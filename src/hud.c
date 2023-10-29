#include "simple_logger.h"
#include "hud.h"

    static const float hpBarX = 10;
    static const float hpBarY = 10;
    static const float hpBarW = 1010;
    static const float hpBarH = 110;

void draw_hud(Entity* player){
    if(!player){
        slog("Player not provided, cannot draw HUD");
        return;
    }

    char health[4];
    sprintf(health, "%d", player->health); 
    float barLength = ((float)player->health)/100.0 * (hpBarW-20.0);

    gf2d_draw_rect_filled(gfc_rect(hpBarX,hpBarY, hpBarW, hpBarH),gfc_color8(1,1,1,255));
    gf2d_draw_rect_filled(gfc_rect(hpBarX + 5, hpBarY + 5, barLength, hpBarH - 20),gfc_color8(128,1,1,255));
    gf2d_font_draw_line_tag("Health",FT_Normal,gfc_color(1,1,1,1), vector2d(10,6));
    gf2d_font_draw_line_tag(health,FT_Normal,gfc_color(1,1,1,1), vector2d(200,6));

    //draw currently equipped weapon
    switch(player->weapon){
        case revolver:
            gf2d_font_draw_line_tag("Revolver:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            break;
        case repeater:
            gf2d_font_draw_line_tag("Repeater:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            break;
        case shotgun:
            gf2d_font_draw_line_tag("Shotgun:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            break;
        case dynamite:
            gf2d_font_draw_line_tag("Dynamite:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            break;
        case throwing_knife:
            gf2d_font_draw_line_tag("Throwing knives:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            break;
    }
}