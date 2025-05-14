#include "lvgl.h"
#include <stdio.h>
#include "screen.h"
#include "event_handlers.h"

lv_obj_t * create_main_screen() {
    lv_obj_t * main_scr = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(main_scr, lv_color_hex(0xFFFFFF), 0);
    lv_obj_add_event_cb(main_scr, gesture_event_cb, LV_EVENT_GESTURE, NULL);
    lv_obj_add_event_cb(main_scr, gesture_event_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(main_scr, gesture_event_cb, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(main_scr, gesture_event_cb, LV_EVENT_RELEASED, NULL);
    return main_scr;
}

lv_obj_t * create_brightness_screen() {
    lv_obj_t * scr = lv_obj_create(NULL);
    lv_obj_set_size(scr, 240, 380);
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x1E1E1E), 0);

    lv_obj_t * slider = lv_slider_create(scr);
    lv_obj_set_size(slider, 40, 200);
    lv_obj_align(slider, LV_ALIGN_CENTER, 0, 0);
    lv_slider_set_range(slider, 0, 100);
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);

    lv_obj_set_style_bg_color(slider, lv_color_hex(0x808080), LV_PART_MAIN);
    lv_obj_set_style_bg_color(slider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);
    lv_obj_set_style_pad_all(slider, 5, LV_PART_MAIN);

    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(scr, scr_event_cb, LV_EVENT_GESTURE, NULL);
    lv_obj_add_event_cb(scr, scr_event_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(scr, scr_event_cb, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(scr, scr_event_cb, LV_EVENT_RELEASED, NULL);

    return scr;
}
