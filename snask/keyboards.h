#include"keyboards.c"
#ifndef KEYBOARDS_H
#define KEYBOARDS_H

void init_keyboard(void);
void close_keyboard(void);
int kbhit(void);
int readch(void);
int get_keys(void);
int get_key(int *key);
#endif
