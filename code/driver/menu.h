#ifndef __MENU_H_
#define __MENU_H_

#define PAGE_MAX             (3)
#define ROW_MAX              (4)

extern int ROW;
extern int PAGE;
extern int run_flag;
extern int Pointer[PAGE_MAX][ROW_MAX];
extern int Pointer_Point[7][2];
extern int PAGE_COUNT[4];

void menu_init(void);
void menu_key_state(void);
void menu_update(void);

#endif
