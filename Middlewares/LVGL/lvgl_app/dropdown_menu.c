#include "lvgl.h"
#include <stdio.h>
#include "dropdown_menu.h"
#include "event_handlers.h"

lv_obj_t * dropdown_menu;
lv_obj_t * btn4;
void create_dropdown_menu(lv_obj_t * parent) {
    // 创建下拉菜单
    dropdown_menu = lv_obj_create(parent);
    lv_obj_set_size(dropdown_menu, 240, 150); // 适配 240x380 分辨率，增加菜单高度
    lv_obj_align(dropdown_menu, LV_ALIGN_TOP_MID, 0, -150); // 初始位置在屏幕顶部之外
    lv_obj_set_style_bg_color(dropdown_menu, lv_color_hex(0x1E1E1E), 0); // 背景颜色改为深灰色
    lv_obj_set_style_border_width(dropdown_menu, 0, 0);
    lv_obj_set_style_radius(dropdown_menu, 10, 0); // 设置圆角

    // 添加按钮，每行排列四个
    int btn_size = 40; // 按钮大小调整为40x40
    int btn_margin = 10; // 按钮间距
    int btn_x = (240 - (btn_size * 4 + btn_margin * 3)) / 2; // 计算按钮起始位置
    int btn_y = 10; // 按钮与顶部边缘的间隔调整为10，以便为第二排按钮留出空间

    lv_obj_t * btn1 = lv_btn_create(dropdown_menu);
    lv_obj_set_size(btn1, btn_size, btn_size); // 设置按钮大小
    lv_obj_align(btn1, LV_ALIGN_TOP_MID, - (btn_size + btn_margin) * 1.5, btn_y); // 调整按钮位置
    lv_obj_add_event_cb(btn1, button_event_cb, LV_EVENT_CLICKED, NULL); // 修改为button_event_cb
    lv_obj_set_style_bg_color(btn1, lv_color_hex(0x2E2E2E), 0); // 设置按钮背景颜色
    lv_obj_set_style_radius(btn1, 15, 0); // 设置按钮圆角
    lv_obj_t * label1 = lv_label_create(btn1);
    lv_label_set_text(label1, LV_SYMBOL_HOME);
    lv_obj_set_style_text_color(label1, lv_color_hex(0xFFFFFF), 0); // 设置图标颜色为白色
    lv_obj_center(label1); // 标签居中

    lv_obj_t * btn2 = lv_btn_create(dropdown_menu);
    lv_obj_set_size(btn2, btn_size, btn_size);
    lv_obj_align(btn2, LV_ALIGN_TOP_MID, - (btn_size + btn_margin) * 0.5, btn_y); // 调整按钮位置
    lv_obj_add_event_cb(btn2, button_event_cb, LV_EVENT_CLICKED, NULL); // 修改为button_event_cb
    lv_obj_set_style_bg_color(btn2, lv_color_hex(0x2E2E2E), 0);
    lv_obj_set_style_radius(btn2, 15, 0);
    lv_obj_t * label2 = lv_label_create(btn2);
    lv_label_set_text(label2, LV_SYMBOL_SETTINGS);
    lv_obj_set_style_text_color(label2, lv_color_hex(0xFFFFFF), 0);
    lv_obj_center(label2); // 标签居中

    lv_obj_t * btn3 = lv_btn_create(dropdown_menu);
    lv_obj_set_size(btn3, btn_size, btn_size);
    lv_obj_align(btn3, LV_ALIGN_TOP_MID, (btn_size + btn_margin) * 0.5, btn_y); // 调整按钮位置
    lv_obj_add_event_cb(btn3, button_event_cb, LV_EVENT_CLICKED, NULL); // 修改为button_event_cb
    lv_obj_set_style_bg_color(btn3, lv_color_hex(0x2E2E2E), 0);
    lv_obj_set_style_radius(btn3, 15, 0);
    lv_obj_t * label3 = lv_label_create(btn3);
    lv_label_set_text(label3, LV_SYMBOL_POWER);
    lv_obj_set_style_text_color(label3, lv_color_hex(0xFFFFFF), 0);
    lv_obj_center(label3); // 标签居中

    btn4 = lv_btn_create(dropdown_menu);
    lv_obj_set_size(btn4, btn_size, btn_size);
    lv_obj_align(btn4, LV_ALIGN_TOP_MID, (btn_size + btn_margin) * 1.5, btn_y); // 调整按钮位置
    lv_obj_add_event_cb(btn4, button_event_cb, LV_EVENT_CLICKED, NULL);  // 修改为button_event_cb
    lv_obj_set_style_bg_color(btn4, lv_color_hex(0x2E2E2E), 0);
    lv_obj_set_style_radius(btn4, 15, 0);
    lv_obj_t * label4 = lv_label_create(btn4);
    lv_label_set_text(label4, LV_SYMBOL_MINUS);  // 修改为已定义的亮度调节图标
    lv_obj_set_style_text_color(label4, lv_color_hex(0xFFFFFF), 0);
    lv_obj_center(label4); // 标签居中

    // 确保下拉菜单不超出屏幕宽度
    lv_obj_set_scrollbar_mode(dropdown_menu, LV_SCROLLBAR_MODE_OFF);
}

void dropdown_menu_anim(lv_obj_t * obj, int32_t y) {
    lv_obj_set_y(obj, y);
}
