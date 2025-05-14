#ifndef __DEMO_H_
#define __DEMO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

/**
 * @brief Creates the pull-down panel UI.
 *
 * This function sets up a panel that can be pulled down from the top of the screen
 * by a swipe gesture and closed by swiping it up.
 *
 * @param parent_screen The screen object on which to create the panel.
 *                      If NULL, lv_scr_act() will be used.
 */
void demo_create(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif


#endif
