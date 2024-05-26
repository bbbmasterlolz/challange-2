#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

typedef char str[128];
typedef char push[3000];

void showmenu();
void gotoxy(int x, int y);
void youdie(int x, int y, int die);
void youwin(int x, int y);
void howtoplay();
int rocket();

