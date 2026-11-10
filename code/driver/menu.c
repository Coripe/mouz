#include "zf_common_headfile.h"
#include "menu.h"

int ROW = 0;
int PAGE = 0;
int run_flag = 0;
int Pointer[PAGE_MAX][ROW_MAX] = {
        {1, 2},
};
int Pointer_Point[7][2] = {
        {230,22},
        {230,38},
        {230,54},
        {230,70},
        {230,86},
        {230,102},
        {230,118}
};
int PAGE_COUNT[4] = {2, 3, 0, 0};

void menu_head(const char title[])
{
    ips114_show_string(0, 0, title);
    ips114_draw_line(0, 16, ips114_width_max - 1, 16, RGB565_BLUE);
}

void menu_pointer(int row, uint16 color)
{
    for(uint8 i = 0; i < 8; i++)
    {
        ips114_draw_line(Pointer_Point[row][0] + i, Pointer_Point[row][1] + i,
                         Pointer_Point[row][0] + i, Pointer_Point[row][1] + 15 - i,
                         color);
    }
}

void Page0()
{
    menu_head("MENU");
    ips114_show_string(0, Pointer_Point[0][1], "GO");
    ips114_show_string(0, Pointer_Point[1][1], "WATCH");
    menu_pointer(ROW, RGB565_WHITE);
}

void Page1()
{
    menu_head("GO");
    ips114_show_string(0, Pointer_Point[0][1], "START");
    ips114_show_string(0, Pointer_Point[1][1], "STOP");
    ips114_show_string(0, Pointer_Point[2][1], "BACK");
    menu_pointer(ROW, RGB565_WHITE);
}

void Page2()
{
    menu_head("WATCH");
}

void menu_init()
{
    key_init(5);
    ips114_set_font(IPS114_8X16_FONT);
    ips114_set_color(RGB565_WHITE, RGB565_BLACK);
    ips114_clear();
}

void menu_key_state()
{
    key_scanner();

    if(PAGE_COUNT[PAGE] > 0)
    {
        if(key_get_state(KEY_1) == KEY_SHORT_PRESS)
        {
            if(ROW >= PAGE_COUNT[PAGE] - 1)
            {
                ROW = 0;
            }
            else
            {
                ROW++;
            }
            key_clear_state(KEY_1);
        }
        if(key_get_state(KEY_2) == KEY_SHORT_PRESS)
        {
            if(ROW <= 0)
            {
                ROW = PAGE_COUNT[PAGE] - 1;
            }
            else
            {
                ROW--;
            }
            key_clear_state(KEY_2);
        }
    }

    if(key_get_state(KEY_3) == KEY_SHORT_PRESS)
    {
        switch(PAGE)
        {
            case 0:
            {
                PAGE = Pointer[0][ROW];
                ROW = 0;
            }break;
            case 1:
            {
                if(ROW == 0)
                {
                    run_flag = 1;
                }
                else if(ROW == 1)
                {
                    run_flag = 0;
                }
                else if(ROW == 2)
                {
                    PAGE = 0;
                    ROW = 0;
                }
            }break;
        }
        key_clear_state(KEY_3);
    }

    if(key_get_state(KEY_4) == KEY_SHORT_PRESS)
    {
        PAGE = 0;
        ROW = 0;
        key_clear_state(KEY_4);
    }

    system_delay_ms(5);
}

void menu_update()
{
    static int page_last = -1;
    static int row_last = -1;
    menu_key_state();
    if(PAGE != page_last)
    {
        page_last = PAGE;
        row_last = ROW;
        ips114_clear();
        switch(PAGE)
        {
            case 0:  Page0(); break;
            case 1:  Page1(); break;
            case 2:  Page2(); break;
        }
        return;
    }

    if(ROW != row_last)
    {
        if(PAGE_COUNT[PAGE] > 0)
        {
            menu_pointer(row_last, RGB565_BLACK);
            menu_pointer(ROW, RGB565_WHITE);
        }
        row_last = ROW;
    }
}
