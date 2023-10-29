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

    //need to display two numbers: current ammo and carried ammo
    char revCurr[3];
    char revAmmo[3];

    char repCurr[3];
    char repAmmo[3];

    char shotCurr[3];
    char shotAmmo[3];
    
    char dynCurr[2];
    char dynAmmo[2];

    char knivesCurr[2];
    char knives[2];

    sprintf(revCurr, "%d", player->weaponData.revolverCurrent);
    sprintf(revAmmo, "%d", player->weaponData.revolverAmmo);
    sprintf(repCurr, "%d", player->weaponData.repeaterCurrent);
    sprintf(repAmmo, "%d", player->weaponData.repeaterAmmo);
    sprintf(shotCurr, "%d", player->weaponData.shotgunCurrent);
    sprintf(shotAmmo, "%d", player->weaponData.shotgunShells);
    sprintf(dynCurr, "%d", player->weaponData.dynamiteCurrent);
    sprintf(dynAmmo, "%d", player->weaponData.sticksDynamite);
    sprintf(knivesCurr, "%d", player->weaponData.knivesCurrent);
    sprintf(knives, "%d", player->weaponData.throwingKnives);

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
            gf2d_font_draw_line_tag(revCurr,FT_Normal,gfc_color(1,1,1,1), vector2d(225,60));
            gf2d_font_draw_line_tag(revAmmo,FT_H1,gfc_color(1,1,1,1), vector2d(250,120));
            break;
        case repeater:
            gf2d_font_draw_line_tag("Repeater:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            gf2d_font_draw_line_tag(repCurr,FT_Normal,gfc_color(1,1,1,1), vector2d(225,60));
            gf2d_font_draw_line_tag(repAmmo,FT_H1,gfc_color(1,1,1,1), vector2d(250,120));
            break;
        case shotgun:
            gf2d_font_draw_line_tag("Shotgun:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            gf2d_font_draw_line_tag(shotCurr,FT_Normal,gfc_color(1,1,1,1), vector2d(225,60));
            gf2d_font_draw_line_tag(shotAmmo,FT_H1,gfc_color(1,1,1,1), vector2d(250,120));
            break;
        case dynamite:
            gf2d_font_draw_line_tag("Dynamite:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            gf2d_font_draw_line_tag(dynCurr,FT_Normal,gfc_color(1,1,1,1), vector2d(240,60));
            gf2d_font_draw_line_tag(dynAmmo,FT_H1,gfc_color(1,1,1,1), vector2d(270,120));
            break;
        case throwing_knife:
            gf2d_font_draw_line_tag("Throwing knives:",FT_Normal,gfc_color(1,1,1,1), vector2d(10,60));
            gf2d_font_draw_line_tag(knivesCurr,FT_Normal,gfc_color(1,1,1,1), vector2d(400,60));
            gf2d_font_draw_line_tag(knives,FT_H1,gfc_color(1,1,1,1), vector2d(420,120));
            break;
    }
}