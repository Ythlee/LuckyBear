/**
 ****************************************************************************************************
 * @file        lv_mainstart.h
 * @author      ??????(ALIENTEK)
 * @version     V1.0
 * @date        2022-03-23
 * @brief       LVGL ?????? ??
 * @license     Copyright (c) 2020-2032, ?????????????
 ****************************************************************************************************
 * @attention
 *
 * ????:???? STM32F103???
 * ????:www.yuanzige.com
 * ????:www.openedv.com
 * ????:www.alientek.com
 * ????:openedv.taobao.com
 *
 ****************************************************************************************************
 */
 
#ifndef __LV_MAINSTART_H
#define __LV_MAINSTART_H
#include "lvgl.h"
#include "exfuns.h"


#define LIST_SIZE    100   /* ???????????,???? */
#define FILE_SEZE    1992  /* ???????????,???? */

typedef struct
{
    lv_obj_t * list;          /* ???? */
    lv_obj_t *lv_page_obj;    /* ??????? */
    lv_obj_t * list_btn[LIST_SIZE]; /* ???????? */
    uint8_t list_flie_nuber;  /* ??????????? */
    FRESULT fr;               /* ?????? */
    DIR lv_dir;      /* ????? */
    FILINFO SD_fno;                    /* ??????? */
    char *pname;              /* ??????? */
    char *lv_pname;           /* ????? */
    char *lv_pname_shift;     /* ????????? */
    const char* lv_pash;      /* ???? */
    int lv_suffix_flag;       /* ??????? */
    int lv_prev_file_flag;    /* ?????????? */
    char *lv_prev_file[LIST_SIZE];  /* ?????? */
    const void *image_scr;    /* ???????????? */
    lv_obj_t * lv_back_obj;   /* ????/????? */
    lv_obj_t * lv_prev_btn;   /* ???? */
    lv_obj_t * lv_back_btn;   /* ???? */
    lv_obj_t *lv_page_cont;   /* ??????? */
    char rbuf[FILE_SEZE];     /* ????????? */
    lv_obj_t *lv_return_page; /* ??????? */
    lv_obj_t *lv_image_read;  /* ?????? */
}lv_file_struct;

/* ????:????????term?1?,????,?term?0????????? */
#define FILE_ASSERT(term)                                                                                   \
do                                                                                                          \
{                                                                                                           \
    if (!(term))                                                                                            \
    {                                                                                                       \
        printf("Assert failed. Condition(%s). [%s][%d]\r\n", term, __FUNCTION__, __LINE__);                 \
        while(1)                                                                                            \
        {                                                                                                   \
            ;                                                                                               \
        }                                                                                                   \
    }                                                                                                       \
} while (0)

void lv_mainstart(void);

#endif
