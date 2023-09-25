#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define sor 15
#define oszlop 25
void Map(int rng_sor, int rng_oszlop)
{
for (int i = 0; i < sor; i++) {
        for (int j = 0; j < oszlop; j++) {
            if (i == 0 || i == sor - 1 || j == 0 || j == oszlop - 1) {
                printf("x");
            }else if(i == rng_sor && j == rng_oszlop) {
                printf("o");

            }
            else {
                printf(" ");
            }

            for (size_t lepes = 0; lepes < j; lepes++)
            {
            sleep(5);
            printf("0");
            }
                
            
        }
        
        printf("\n");

    }
}
int main() {

char kezdes[] = "ok";
char beker[3];
srand(time(NULL));
    int rng_sor = rand() % (sor -2 )+2;
    int rng_oszlop = rand() % (oszlop -2 )+1;
    printf("%i" , rng_sor);
printf("Kezdéshez irj 'ok'-ot \n");
scanf("%s", beker);
    if (strcmp(kezdes, beker) == 0)
    {
    Map(rng_sor,rng_oszlop);
    }else
    {
        printf("fwfefew");
    }
} 