#include "lv_mainstart.h"
#include "lvgl.h"
#include <stdio.h>  // 添加 stdio.h 头文件以使用 printf 函数


// 添加函数声明
static void icon_event_cb(lv_event_t * e);
static void scr_event_cb(lv_event_t * e);
static void create_dropdown_menu();

static lv_obj_t * dropdown_menu;

static void slider_event_cb(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);  // 使用 lv_event_get_target 获取目标对象
    int32_t value = lv_slider_get_value(slider);
    // 在这里实现亮度调节的逻辑
    printf("Brightness adjusted to: %d\n", value);
}

static void brightness_adjust_cb(lv_event_t * e) {
    // 删除主界面
    lv_obj_del(lv_scr_act());

    lv_obj_t * scr = lv_obj_create(NULL);  // 创建一个新屏幕
    lv_obj_set_size(scr, 240, 380);  // 设置屏幕大小为 240x380
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x1E1E1E), 0);  // 背景颜色为深灰色

    // 创建亮度调节滑动条
    lv_obj_t * slider = lv_slider_create(scr);
    lv_obj_set_size(slider, 40, 200);  // 设置滑动条为竖直方向，宽度增加为40
    lv_obj_align(slider, LV_ALIGN_CENTER, 0, 0);
    lv_slider_set_range(slider, 0, 100);  // 设置滑动条范围
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);  // 设置默认值为50

    // 设置滑动条样式
    lv_obj_set_style_bg_color(slider, lv_color_hex(0x808080), LV_PART_MAIN);  // 背景颜色为灰色
    lv_obj_set_style_bg_color(slider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);  // 滑过的区域为白色
    lv_obj_set_style_pad_all(slider, 5, LV_PART_MAIN);  // 加粗滑动条

    // 添加滑动条事件
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    // 添加手势检测，向上滑动返回主界面
    lv_obj_add_event_cb(scr, scr_event_cb, LV_EVENT_GESTURE, NULL);
    lv_obj_add_event_cb(scr, scr_event_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(scr, scr_event_cb, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(scr, scr_event_cb, LV_EVENT_RELEASED, NULL);

    lv_scr_load(scr);  // 加载新屏幕
}

static void scr_event_cb(lv_event_t * e) {
    lv_indev_t * indev = lv_indev_get_act();
    lv_point_t point;
    lv_indev_get_vect(indev, &point);

    if (point.y < -50) {  // 检测到向上滑动
        lv_obj_del(lv_scr_act());  // 删除当前屏幕
        lv_obj_t * main_scr = lv_obj_create(NULL);  // 创建主界面
        lv_obj_set_style_bg_color(main_scr, lv_color_hex(0xFFFFFF), 0);  // 设置主界面背景颜色为白色
        create_dropdown_menu();  // 重新创建下拉菜单
        lv_scr_load(main_scr);  // 加载主界面
        printf("Returned to main screen\n");
    }
}

static void create_dropdown_menu() {
    // 创建下拉菜单
    dropdown_menu = lv_obj_create(lv_scr_act());
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
    lv_obj_add_event_cb(btn1, icon_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_bg_color(btn1, lv_color_hex(0x2E2E2E), 0); // 设置按钮背景颜色
    lv_obj_set_style_radius(btn1, 15, 0); // 设置按钮圆角
    lv_obj_t * label1 = lv_label_create(btn1);
    lv_label_set_text(label1, LV_SYMBOL_HOME);
    lv_obj_set_style_text_color(label1, lv_color_hex(0xFFFFFF), 0); // 设置图标颜色为白色
    lv_obj_center(label1); // 标签居中

    lv_obj_t * btn2 = lv_btn_create(dropdown_menu);
    lv_obj_set_size(btn2, btn_size, btn_size);
    lv_obj_align(btn2, LV_ALIGN_TOP_MID, - (btn_size + btn_margin) * 0.5, btn_y); // 调整按钮位置
    lv_obj_add_event_cb(btn2, icon_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_bg_color(btn2, lv_color_hex(0x2E2E2E), 0);
    lv_obj_set_style_radius(btn2, 15, 0);
    lv_obj_t * label2 = lv_label_create(btn2);
    lv_label_set_text(label2, LV_SYMBOL_SETTINGS);
    lv_obj_set_style_text_color(label2, lv_color_hex(0xFFFFFF), 0);
    lv_obj_center(label2); // 标签居中

    lv_obj_t * btn3 = lv_btn_create(dropdown_menu);
    lv_obj_set_size(btn3, btn_size, btn_size);
    lv_obj_align(btn3, LV_ALIGN_TOP_MID, (btn_size + btn_margin) * 0.5, btn_y); // 调整按钮位置
    lv_obj_add_event_cb(btn3, icon_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_bg_color(btn3, lv_color_hex(0x2E2E2E), 0);
    lv_obj_set_style_radius(btn3, 15, 0);
    lv_obj_t * label3 = lv_label_create(btn3);
    lv_label_set_text(label3, LV_SYMBOL_POWER);
    lv_obj_set_style_text_color(label3, lv_color_hex(0xFFFFFF), 0);
    lv_obj_center(label3); // 标签居中

    lv_obj_t * btn4 = lv_btn_create(dropdown_menu);
    lv_obj_set_size(btn4, btn_size, btn_size);
    lv_obj_align(btn4, LV_ALIGN_TOP_MID, (btn_size + btn_margin) * 1.5, btn_y); // 调整按钮位置
    lv_obj_add_event_cb(btn4, brightness_adjust_cb, LV_EVENT_CLICKED, NULL);  // 修改回调函数
    lv_obj_set_style_bg_color(btn4, lv_color_hex(0x2E2E2E), 0);
    lv_obj_set_style_radius(btn4, 15, 0);
    lv_obj_t * label4 = lv_label_create(btn4);
    lv_label_set_text(label4, LV_SYMBOL_MINUS);  // 修改为已定义的亮度调节图标
    lv_obj_set_style_text_color(label4, lv_color_hex(0xFFFFFF), 0);
    lv_obj_center(label4); // 标签居中

    // 确保下拉菜单不超出屏幕宽度
    lv_obj_set_scrollbar_mode(dropdown_menu, LV_SCROLLBAR_MODE_OFF);
}

static void icon_event_cb(lv_event_t * e) {
    lv_obj_t * obj = lv_event_get_target(e);
    printf("Icon clicked\n");
}

static void dropdown_menu_anim(lv_obj_t * obj, int32_t y) {
    lv_obj_set_y(obj, y);
}

static void gesture_event_cb(lv_event_t * e) {
    lv_indev_t * indev = lv_indev_get_act();
    lv_point_t point;
    lv_indev_get_vect(indev, &point);

    // 检测到向下滑动（触摸屏或鼠标）
    if (point.y > 50) {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, dropdown_menu);
        lv_anim_set_values(&a, -150, 0); // 确保菜单从屏幕外滑入
        lv_anim_set_time(&a, 300);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)dropdown_menu_anim);
        lv_anim_start(&a);
        printf("Dropdown menu opened\n");
    }
    // 检测到向上滑动（触摸屏或鼠标）
    else if (point.y < -50) {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, dropdown_menu);
        lv_anim_set_values(&a, 0, -150); // 确保菜单完全滑出屏幕
        lv_anim_set_time(&a, 300);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)dropdown_menu_anim);
        lv_anim_start(&a);
        printf("Dropdown menu closed\n");
    }
}

//void demo_create() {
//    // 设置主界面背景颜色为白色
//    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xFFFFFF), 0);

//    create_dropdown_menu();

//    // 添加手势检测，同时支持触摸屏和鼠标
//    lv_obj_add_event_cb(lv_scr_act(), gesture_event_cb, LV_EVENT_GESTURE, NULL);
//    lv_obj_add_event_cb(lv_scr_act(), gesture_event_cb, LV_EVENT_PRESSED, NULL);
//    lv_obj_add_event_cb(lv_scr_act(), gesture_event_cb, LV_EVENT_PRESSING, NULL);
//    lv_obj_add_event_cb(lv_scr_act(), gesture_event_cb, LV_EVENT_RELEASED, NULL);
//}

extern void demo_create(void);
/**
 * @brief  LVGL演示
 * @param  无
 * @return 无
 */
void lv_mainstart(void)
{
	demo_create();
}
