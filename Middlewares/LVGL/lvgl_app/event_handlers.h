#ifndef EVENT_HANDLERS_H
#define EVENT_HANDLERS_H

#include "lvgl.h"

void slider_event_cb(lv_event_t * e);
void scr_event_cb(lv_event_t * e);
void button_event_cb(lv_event_t * e);  // 添加button_event_cb函数的声明
void gesture_event_cb(lv_event_t * e);

#endif