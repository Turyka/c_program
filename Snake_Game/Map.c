#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h> // bool true false meghivása
#include <stdlib.h>
#include <windows.h> // sleep-hez
#include <conio.h> // Getch-hez 
#define sor 25
#define oszlop 15

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
#endif
}
void GameOver()
{
ClearScreen();
printf("Sajnalom de vesztett");
exit(0);
}
void Map(int x, int y,int rng_sor, int rng_oszlop)
{
    ClearScreen();
for (int i = 0; i < oszlop; i++) {  //oszlop
        for (int j = 0; j < sor; j++) {     // sor
            if (i == 0 || i == oszlop - 1 || j == 0 || j == sor - 1) {  // az elso oszlop, sor és utso oszlop,sor marad
                printf("x");
            }else if(i == y && j == x) { // Kezdő pozicio
                printf("o");
            }
            else {          // ha maga a üres pálya
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
int x = 12;
int y = 7;
bool jobbra = false;
bool balra = false;
bool fel = false;
bool le = false;
srand(time(NULL));
    int rng_sor = rand() % (sor -2 )+2;
    int rng_oszlop = rand() % (oszlop -2 )+1;
printf("Kezdes \n");
        char ch = _getch();
        if(ch == 'd'){
            jobbra = true;
        }else if (ch == 'a')
        {
            balra = true;
        }else if (ch == 'w')
        {
            fel = true;
        }else if (ch == 's')
        {
            le = true;
        }
    while (1)
    {
        Map(x,y,rng_sor,rng_oszlop);
        while (jobbra) {
        x++;
        Map(x, y, rng_sor, rng_oszlop);
        Sleep(1000);
            if (_kbhit())
            {
                char innerCh = _getch();
                if (innerCh == 'w') {
                    jobbra = false;
                    fel = true;
                    break;
                } else if (innerCh == 's') {
                    jobbra = false;
                    le = true;
                    break;
                }
            }
        }
        while (fel) 
        {
        y--;
        Map(x, y, rng_sor, rng_oszlop);
        Sleep(1000);
        bool wPressed = false;
            if (_kbhit()) 
            {
                char innerCh = _getch();
                if (innerCh == 'a') {
                    fel = false;
                    balra = true;
                    break;
                } else if (innerCh == 'd') {
                    fel = false;
                    jobbra = true;
                    break;
                }else if (innerCh == 'w') {
                }
            }
        }
        while (balra) 
        {
        x--;
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
                }
            }
        }
         while (le) 
        {
        y++;
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
                }
            }
        }
    }
    printf("Vesztettél!!!!");
} 