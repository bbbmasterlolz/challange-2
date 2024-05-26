#include "header.h"

int main(int argc, char *argv[]) {
	int x, y, menu, die = -1;

	do{
		system("cls");
		system("color 0");
		showmenu();
		printf("\033[?25h");
		fflush(stdout);
		scanf("%d", &menu);
		switch(menu){
			case 1 :
				system("cls");
				die = rocket();
				if(die == 1){
					youwin(x, y);
				}else if(die == 2 || die == 3){
					youdie(x, y, die);	
				}
				do{
					menu = getch();
				}while(menu != 27);
				return 0;
			break;
			
			case 2 :
				printf("\033[?25l");
				fflush(stdout);
				howtoplay();
				do{
					menu = getch();
				}while(menu != 27);
			break;
			
			case 0 :
				printf("\n\033[1;31m                                       EXITING GAME. . . \033[0m");
				getch();
			break;			
			
			default :
				printf("\n\033[1;33m                                       MENU DO NOT EXIST !!! \033[0m");
				getch();
			break;
		}
	}while(menu != 0);
	
	return 0;
}

