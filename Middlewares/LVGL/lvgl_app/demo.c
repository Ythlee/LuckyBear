#include "lvgl.h"
#include "screen.h"
#include "dropdown_menu.h"
#include "event_handlers.h"

void demo_create(void) {
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xFFFFFF), 0);
    create_dropdown_menu(lv_scr_act());
    
    // 确保在主界面创建时添加了正确的手势事件回调
    lv_obj_add_event_cb(lv_scr_act(), gesture_event_cb, LV_EVENT_GESTURE, NULL);
    lv_obj_add_event_cb(lv_scr_act(), gesture_event_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(lv_scr_act(), gesture_event_cb, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(lv_scr_act(), gesture_event_cb, LV_EVENT_RELEASED, NULL);
}