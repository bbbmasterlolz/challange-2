#include "header.h"

void howtoplay(){
	system("cls");
	system("color 8F");
	printf("\033[1m"
		"\n                --=== How To Play ===--"
		"\n\n        [W]        : Move Up"
		"\n        [S]        : Move Down"
		"\n        [A]        : Move Left"
		"\n        [D]        : Move Right"
		"\n\n        %c --> Minyak"
		"\n        %c --> Barang"
		"\n        * --> Meteor"
		"\n\n        Tips to play :"
		"\n         - Don't get hit by the meteor or you will lose!"
		"\n         - If your Fuel is low take the fuel to increase your fuel by 250!"
		"\n         - If you ran out of Fuel, you will lose!"
		"\n         - If you have 3 barang, you can go to the top of the map to win the game!"
		"\n         - Becareful because meteor can destroy the fuel and barang and then they will dissapear and respawn elsewhere!"
		"\n\n\n\n                                          [!] PRESS ESC TO BACK TO MENU [!]\033[0m",
		219, 225
	);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void youdie(int x, int y, int die){
	system("cls");
	gotoxy(15,6);
	printf("\033[1;31m");
    printf("o\033[sooooo   oooo   .oooooo.   ooooo     ooo  oooooooooo.   ooooo oooooooooooo oooooooooo.\033[u\033[B");
    printf("`\033[s888.   .8'   d8P'  `Y8b  `888'     `8'  `888'   `Y8b  `888' `888'     `8 `888'   `Y8b\033[u\033[B");
    printf("`\033[s888. .8'   888      888  888       8    888      888  888   888          888      888\033[u\033[B");
    printf("`\033[s888.8'    888      888  888       8    888      888  888   888oooo8     888      888\033[u\033[B");
    printf("\033[s`888'     888      888  888       8    888      888  888   888    '     888      888\033[u\033[B");
    printf("\033[s 888      `88b    d88'  `88.    .8'    888     d88'  888   888       o  888     d88'\033[u\033[B");
    printf("o888o      `Y8bood8P'  \033[s   `YbodP'     o888bood8P'   o888o o888ooooood8 o888bood8P'\033[u\033[B\033[B\033[B");
	printf("\033[s  [!] PRESS ESC TO EXIT [!]\033[u\033[B\033[B");
    printf("\033[0m");
    printf("\033[1;33m");
    if(die == 2){
   		printf("[!] ROKET ANDA KENA METEOR [!]\n");	
	}else if(die == 3){
   		printf("    [!] MINYAK HABIS [!]\n");
	}
	printf("\033[0m");
}

void youwin(int x, int y){
	system("cls");
	gotoxy(15,6);
	printf("\033[1;32m");
    printf("o\033[sooooo   oooo   .oooooo.   ooooo     ooo  oooooo   oooooo     oooo ooooo ooooo      ooo\033[u\033[B");
    printf("`\033[s888.   .8'   d8P'  `Y8b  `888'     `8'   `888.    `888.     .8'  `888' `888b.     `8'\033[u\033[B");
    printf("`\033[s888. .8'   888      888  888       8     `888.   .8888.   .8'    888   8 `88b.    8\033[u\033[B");
    printf("`\033[s888.8'    888      888  888       8      `888  .8'`888. .8'     888   8   `88b.  8\033[u\033[B");
    printf("\033[s`888'     888      888  888       8       `888.8'  `888.8'      888   8     `88b.8\033[u\033[B");
    printf("\033[s 888      `88b    d88'  `88.    .8'        `888'    `888'       888   8       `888\033[u\033[B");
    printf("o888o      `Y8bood8P'  \033[s   `YbodP'           `8'      `8'       o888o o8o        `8\033[u\033[B\033[B\033[B");
    printf("\033[s   [!] PRESS ESC TO EXIT [!]\033[u\033[B\033[B");
    printf("\033[0m");
    printf("\033[1;33m\033[3D");
    printf("[!] ANDA BERHASIL MEMBAWA 3 BARANG [!]\n");
    printf("\033[0m");
}

void showmenu(){
	printf("\033[37m"
		"\n                                       ---=== [ ROCKET MASTER ] ===---"
		"\n                                       [1] Play The Game!"
		"\n                                       [2] How To Play?"
		"\n                                       [0] Exit Game"
		"\n                                       >>> "
		"\033[0m"
	);
}

int rocket(){
	const int xbb=102, ybb=21, jml_M=3;
	int x, y, key, now, p;
	push out;
	str temp;
	int bx, by, mx, my, tempx;
	int ax = 51, ay = 18;
	int arr[xbb][ybb];
	int meteor[jml_M][2];
	int barang = 0, minyak = 600;
	int end = 0;
	srand(time(NULL));
	printf("\033[?25l");
    fflush(stdout);
    	
	for(x=0;x<jml_M;x++){
		meteor[x][0] = (rand()%(xbb-2))+1;
		meteor[x][1] = (rand()%(5))+1;
	}
	
	
	do{
		bx = (rand()%(xbb-2))+1;
		by = (rand()%(ybb-2)/2)+3;
	}while(bx>=ax-2&&by>=ay-2&&bx<=ax+2&&by<=ay+2);
	
	do{
		mx = (rand()%(xbb-2))+1;
		my = (rand()%(ybb-2)/2)+3;
	}while (bx==mx&&by==my);
	
    do{
        Sleep(200);
        if(kbhit()!=0){
            key = getch();
        }else{
            key = 0;
        }
        switch(key){
            case 97: //a
                if(ax>3){ax--;minyak-=5;}
                break;
            case 100: // d
                if(ax<xbb-4){ax++;minyak-=5;}
                break;
            case 115: // s
                if(ay<ybb-3){ay++;minyak-=5;}
                break;
            case 119: // w
                if(ay==3&&barang>=3){
                    return 1; // menang
                }
                if(ay>2){ay--;minyak-=5;}
                break;
            default:
                break;
        }
        
        if(minyak <= 0){
            minyak = 0;
            return 3; // minyak habis
        }
        
        
        if(bx>=ax-2&&by>=ay-1&&bx<=ax+2&&by<=ay+1){
            do{
                bx = (rand()%(xbb-2))+1;
                by = (rand()%(ybb-2)/2)+3;
            }while(bx>=ax-2&&by>=ay-1&&bx<=ax+2&&by<=ay+1||(bx==mx&&by==my));
            barang++;
        }
        if(mx>=ax-2&&my>=ay-1&&mx<=ax+2&&my<=ay+1){
            do{
                mx = (rand()%(xbb-2))+1;
                my = (rand()%(ybb-2)/2)+3;
            }while(mx>=ax-2&&my>=ay-1&&mx<=ax+2&&my<=ay+1||(bx==mx&&by==my));
            minyak+=250;
        }
        
        for(y=0;y<ybb;y++){
            for(x=0;x<xbb;x++){
                if(x==ax&&y==ay){
                    arr[x][y]=1;
                }else if(x==ax&&y==ay-1){
                    arr[x][y]=2;
                }else if(x==ax-1&&y==ay){
                    arr[x][y]=3;
                }else if(x==ax+1&&y==ay){
                    arr[x][y]=4;
                }else if(x<=ax+1&&x>=ax-1&&y==ay+1){
                    arr[x][y]=5;
                }else if((x==ax+2||x==ax-2)&&y==ay+1){
                    arr[x][y]=6;
                }else if(x==bx&&y==by){
                    arr[x][y]=7;
                }else if(x==mx&&y==my){
                    arr[x][y]=8;
                }else if(x==0&&y==0){
                    arr[x][y]=9;
                }else if(x==0&&y==ybb-1){
                    arr[x][y]=10;
                }else if(x==xbb-1&&y==0){
                    arr[x][y]=11;
                }else if(x==xbb-1&&y==ybb-1){
                    arr[x][y]=12;
                }else if(x==0||x==xbb-1){
                    arr[x][y]=13;
                }else if(y==0||y==ybb-1){
                    arr[x][y]=14;
                }else{
                    arr[x][y]=-1;
                }
            }
        } 
        
        for(x=0;x<jml_M;x++){
        arr[meteor[x][0]][meteor[x][1]] = 0;
        }
        
        for(x=0;x<jml_M;x++){
            if(meteor[x][1]==ybb-2){
                meteor[x][0] = (rand()%(xbb-2))+1;
                meteor[x][1] = (rand()%(5))+1;
            }else if(meteor[x][0] == mx && meteor[x][1] == my){
                arr[meteor[x][0]][meteor[x][1]] = 15;
                arr[meteor[x][0]-1][meteor[x][1]] = 16;
                arr[meteor[x][0]+1][meteor[x][1]] = 16;
                arr[meteor[x][0]][meteor[x][1]-1] = 17;
                arr[meteor[x][0]][meteor[x][1]+1] = 17;
                meteor[x][1]++;
                do{
                    mx = (rand()%(xbb-2))+1;
                    my = (rand()%(ybb-2)/2)+3;
                }while (bx==mx&&by==my);
            }else if(meteor[x][0] == bx && meteor[x][1] == by){
                arr[meteor[x][0]][meteor[x][1]] = 15;
                arr[meteor[x][0]-1][meteor[x][1]] = 16;
                arr[meteor[x][0]+1][meteor[x][1]] = 16;
                arr[meteor[x][0]][meteor[x][1]-1] = 17;
                arr[meteor[x][0]][meteor[x][1]+1] = 17;
                meteor[x][1]++;
                do{
                    bx = (rand()%(xbb-2))+1;
                    by = (rand()%(ybb-2)/2)+3;
                }while(bx>=ax-2&&by>=ay-1&&bx<=ax+2&&by<=ay+1||(bx==mx&&by==my));
            }else if(meteor[x][0]>=ax-2&&meteor[x][1]>=ay-1&&meteor[x][0]<=ax+2&&meteor[x][1]<=ay+1){
                return 2; // meteor 
            }else{
                meteor[x][1]++;
            }	
        }
        
        
        p=0;
        for(y=0;y<ybb;y++){
            for(x=0;x<xbb;x++){
                now = arr[x][y];
                switch(now){
                    case 0: sprintf(out+p, "*"); break;
                    case 1: sprintf(out+p, " "); break;
                    case 2: sprintf(out+p, "^"); break;
                    case 3: sprintf(out+p, "/"); break;
                    case 4: sprintf(out+p, "\\"); break;
                    case 5: sprintf(out+p, "_"); break;
                    case 6: sprintf(out+p, "%c", 179); break;
                    case 7: sprintf(out+p, "\033[33m%c\033[0m", 225); p+= 9; break;
                    case 8: sprintf(out+p, "\033[31m%c\033[0m", 219); p+= 9; break;
                    case 9: sprintf(out+p, "%c", 201); break;
                    case 10: sprintf(out+p, "%c", 200); break;
                    case 11: sprintf(out+p, "%c", 187); break;
                    case 12: sprintf(out+p, "%c", 188); break;
                    case 13: sprintf(out+p, "%c", 186); break;
                    case 14: sprintf(out+p, "%c", 205); break;
                    case 15: sprintf(out+p, "\033[31m%c\033[0m", 177); p+= 9; break;
                    case 16: sprintf(out+p, "\033[33m%c\033[0m", 177); p+= 9; break;
                    case 17: sprintf(out+p, "\033[35m%c\033[0m", 177); p+= 9; break;
                    case -1: sprintf(out+p, " "); break;
                    default: sprintf(out+p, "x"); break;
                }
                p++;
            }
            sprintf(out+p, "\n");
            p++;
        } 
        
        sprintf(temp, "\n\t\t--===[ ROCKET MASTER ]===--");
        tempx=strlen(temp);
        sprintf(out+p, "\n\t\t--===[ ROCKET MASTER ]===--");
        p+=tempx;
        
        sprintf(temp, "\n\n\t\t   W                \033[33m%c Merupakan Barang\033[0m", 225);
        tempx=strlen(temp);
        sprintf(out+p, "\n\n\t\t   W                \033[33m%c Merupakan Barang\033[0m", 225);
        p+=tempx;
        
        sprintf(temp, "\n\t\t A S D              \033[31m%c Merupakan Minyak\033[0m", 219);
        tempx=strlen(temp);
        sprintf(out+p, "\n\t\t A S D              \033[31m%c Merupakan Minyak\033[0m", 219);
        p+=tempx;
        
        sprintf(temp, "\n\t\tMovement");
        tempx=strlen(temp);
        sprintf(out+p, "\n\t\tMovement");
        p+=tempx;
        
        sprintf(temp, "\n\t\t\t\t\033[K Sisa Minyak = %d", minyak);
        tempx=strlen(temp);
        sprintf(out+p, "\n\t\t\t\t\033[K Sisa Minyak = %d", minyak);
        p+=tempx;
        
        sprintf(temp, "\n\t\t\t\t\033[K Jumlah barang yang sudah Diambil = %d", barang);
        tempx=strlen(temp);
        sprintf(out+p, "\n\t\t\t\t\033[K Jumlah barang yang sudah Diambil = %d", barang);
        p+=tempx;
        
        if(barang >= 3){
	        sprintf(temp, "\n\t\t\t\t\033[K Pergi Keujung atas untuk menyelesaikan game!");
	        tempx=strlen(temp);
	        sprintf(out+p, "\n\t\t\t\t\033[K Pergi Keujung atas untuk menyelesaikan game!");
	        p+=tempx;	
		}
        
        printf(out);
        printf("\033[H");
    }while(1);
}
