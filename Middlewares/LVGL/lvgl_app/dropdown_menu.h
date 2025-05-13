#ifndef DROPDOWN_MENU_H
#define DROPDOWN_MENU_H

#include "lvgl.h"

extern lv_obj_t * dropdown_menu;
extern lv_obj_t * btn4;

void create_dropdown_menu(lv_obj_t * parent);
void dropdown_menu_anim(lv_obj_t * obj, int32_t y);

#endif // DROPDOWN_MENU_H
