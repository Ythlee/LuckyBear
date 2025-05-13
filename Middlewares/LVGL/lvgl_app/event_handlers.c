#include "lvgl.h"
#include <stdio.h>
#include <string.h>  // 添加string.h头文件，声明strcmp函数
#include "event_handlers.h"
#include "screen.h"  // 添加screen.h头文件，声明create_main_screen函数
#include "dropdown_menu.h"  // 添加dropdown_menu.h头文件，声明create_dropdown_menu函数和dropdown_menu变量

void slider_event_cb(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);
    int32_t value = lv_slider_get_value(slider);
    printf("Brightness adjusted to: %d\n", value);
}

void scr_event_cb(lv_event_t * e) {
    lv_indev_t * indev = lv_indev_get_act();
    lv_point_t point;
    lv_indev_get_vect(indev, &point);

    if (point.y < -50) {
        lv_obj_del(lv_scr_act());
        lv_obj_t * main_scr = create_main_screen();
        create_dropdown_menu(main_scr);
        lv_obj_add_event_cb(main_scr, scr_event_cb, LV_EVENT_GESTURE, NULL);
        lv_obj_add_event_cb(main_scr, scr_event_cb, LV_EVENT_PRESSED, NULL);
        lv_obj_add_event_cb(main_scr, scr_event_cb, LV_EVENT_PRESSING, NULL);
        lv_obj_add_event_cb(main_scr, scr_event_cb, LV_EVENT_RELEASED, NULL);
        lv_scr_load(main_scr);
        printf("Returned to main screen\n");
    }
}

void button_event_cb(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_target(e);

    if (btn == btn4) {
        lv_obj_del(dropdown_menu);  // 删除当前界面
        lv_obj_t * brightness_scr = create_brightness_screen();  // 创建亮度调节界面
        lv_scr_load(brightness_scr);  // 加载亮度调节界面
        printf("Switched to brightness adjustment screen\n");
    }
}

void gesture_event_cb(lv_event_t * e) {
    static bool is_menu_open = false;  // 添加一个静态变量来记录菜单的当前状态
    lv_indev_t * indev = lv_indev_get_act();
    lv_point_t point;
    lv_indev_get_vect(indev, &point);

    if (point.y > 50 && !is_menu_open) {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, dropdown_menu);
        lv_anim_set_values(&a, -150, 0);
        lv_anim_set_time(&a, 300);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)dropdown_menu_anim);
        lv_anim_start(&a);
        is_menu_open = true;  // 更新菜单状态为打开
        printf("Dropdown menu opened\n");
    } else if (point.y < -50 && is_menu_open) {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, dropdown_menu);
        lv_anim_set_values(&a, 0, -150);
        lv_anim_set_time(&a, 300);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)dropdown_menu_anim);
        lv_anim_start(&a);
        is_menu_open = false;  // 更新菜单状态为关闭
        printf("Dropdown menu closed\n");
    }
}