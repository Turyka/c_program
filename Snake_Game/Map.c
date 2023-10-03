#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h> // bool true false meghivása
#include <stdlib.h>
#include <windows.h> // sleep-hez
#include <conio.h> // Getch-hez 
#define sor 25
#define oszlop 15
int kukac_szama = 1;
void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
#endif
}
void snake(int x, int y, int kukac_szama) {
    for (int i = 0; i < kukac_szama; i++) {
        if (i == 0) {
            printf("o");
        } else {
            printf("\n");
            for (int j = 0; j < x - 1; j++) {
                printf(" ");
            }
            if (i == kukac_szama - 1) {
                printf("o");
            } else {
                printf("\n");
            }
        }
    }
}

void GameOver()
{
ClearScreen();
printf("Sajnalom de vesztett \n");
printf("Elért pontszáma: %d ",kukac_szama-1);
exit(0);
}

void Map(int x, int y, int rng_sor, int rng_oszlop) {
    ClearScreen();
    for (int i = 0; i < oszlop; i++) {
        for (int j = 0; j < sor; j++) {
            if (i == 0 || i == oszlop - 1 || j == 0 || j == sor - 1) {
                printf("x");
            } else if (i == y && j == x) {
                  printf("o");
                
            } else if (i == y && j == x + kukac_szama - 1) {
                printf("o");
                
            }else if (i == rng_oszlop && j == rng_sor) {
                printf("@");
            }else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    
    int x = 12;
    int y = 7;
    bool jobbra,balra,fel,le=false;
    srand(time(NULL));
        
    printf("Kezdes \n W-A-S-D Iranyitas: Nyomjon 4 kozul egy gombot");

        fel = true; 
         int rng_sor= rand() % (sor -2 )+2;
         int rng_oszlop = rand() % (oszlop -2 )+1;
    while (1)
    {
    
        while(jobbra)
        {
            x++;
            if (y == rng_oszlop && x == rng_sor) {
            rng_sor = rand() % (sor - 2) + 2;
            rng_oszlop = rand() % (oszlop - 2) + 1;
            kukac_szama++;
            }
            Map(x, y, rng_sor, rng_oszlop);
            Sleep(1000);
                if (_kbhit())
                {
                    balra = false;
                    char innerCh = _getch();
                    if (innerCh == 'w') {
                        jobbra = false;
                        fel = true;
                        break;
                    } else if (innerCh == 's') {
                        jobbra = false;
                        le = true;
                        break;
                    }else if(innerCh == 'd'){
                        while (_kbhit()) {
                            _getch(); 
                        }
                    }
                }
            if (x>=23) 
            {
                GameOver();
            }
        }
        while (fel) 
        {
            le = false;
            y--;
            if (y<= 0) 
            {
                GameOver();
            }
            if (y == rng_oszlop && x == rng_sor) {
            rng_sor = rand() % (sor - 2) + 2;
            rng_oszlop = rand() % (oszlop - 2) + 1;
            kukac_szama++;
            }
            Map(x, y, rng_sor, rng_oszlop);
             Sleep(1000);
                if (_kbhit()) 
                {
                    char innerCh = _getch();
                    if (innerCh == 'a') {
                        fel = false;
                        jobbra = false;
                        balra = true;
                        break;
                    } else if (innerCh == 'd') {
                        balra = false;
                        fel = false;
                        jobbra = true;
                        break;
                    }else if (innerCh == 'w') {
                        while (_kbhit()) {
                            _getch(); 
                        }
                    }
                }
            
        }
        while (balra) 
        {
            jobbra = false;
            x--;
            if (y == rng_oszlop && x == rng_sor) {
            rng_sor = rand() % (sor - 2) + 2;
            rng_oszlop = rand() % (oszlop - 2) + 1;
            kukac_szama++;
            }
            Map(x, y, rng_sor, rng_oszlop);
            Sleep(1000);
                if (_kbhit()) 
                {
                    char innerCh = _getch();
                    if (innerCh == 'w') {
                        balra = false;
                        fel = true;
                        break;
                    } else if (innerCh == 's') {
                        balra = false;
                        le = true;
                        break;
                    }else if(innerCh == 'a'){
                        while (_kbhit()) {
                            _getch(); 
                        }
                    }
                }
            if (x<=1) 
            {
                GameOver();
            }
        }
        while (le) 
        {
            fel = false;
            y++;
            if (y == rng_oszlop && x == rng_sor) {
            rng_sor = rand() % (sor - 2) + 2;
            rng_oszlop = rand() % (oszlop - 2) + 1;
            kukac_szama++;
            }
            Map(x, y, rng_sor, rng_oszlop);
            Sleep(1000);
                if (_kbhit()) 
                {
                    char innerCh = _getch();
                    if (innerCh == 'a') {
                        le = false;
                        balra = true;
                        break;
                    } else if (innerCh == 'd') {
                        le = false;
                        jobbra = true;
                        break;
                    }else if(innerCh == 's'){
                        while (_kbhit()) {
                            _getch(); 
                        }
                    }
                }
                if (y>=13) 
            {
                GameOver();
            }
        }
    }
} 