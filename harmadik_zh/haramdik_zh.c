#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

typedef struct konyv{
    char cim[256];
    char szerzo[50];
    int ev;

} konyv;

void konyv_adatok(konyv *a)
{
printf("%s,%s,%d",a->cim,a->szerzo,a->ev);
}
int main()
{
 srand(time(NULL));
printf("Kerek egy cimet!");
konyv d;
scanf("%s", d.cim);
printf("Kerek egy szerzot");
scanf("%s", d.szerzo);
printf("Kerek szepen egy evet");
scanf("%d",&d.ev);
printf("%s %s %d",d.cim,d.szerzo,d.ev);
konyv_adatok(&d);
konyv polc[3];
for (size_t i = 0; i < 3; i++)
{
   polc[i].cim[0]= rand() % (90 - 65 +1) + 65;
   for (size_t j = 1; j < 11; j++)
   {
    polc[i].cim[j]= rand() % (122 - 97 +1) + 97;
   }
   polc[i].cim[10] = '\0';
   polc[i].szerzo[0] = rand() % (90 - 65 +1) + 65;
   for (size_t j = 1; j < 6; j++)
   {
    polc[i].szerzo[j]= rand() % (122 - 97 +1) + 97;
   }
    polc[i].szerzo[6]=' ';
   for (size_t j = 7; j < 13; j++)
   {
    polc[i].szerzo[j]= rand() % (122 - 97 +1) + 97;
   }
   polc[i].szerzo[13]='\0';
polc[i].ev = rand() % (2023 -1923 + 1) +1923;
}
for (size_t i = 0; i < 3; i++)
{
    printf("Köny polc \n");
    konyv_adatok(&polc[i]);
}
konyv *xd = (konyv*) malloc(sizeof(konyv));
int max = polc[0].ev;
int seged;
for (size_t i = 0; i < 3; i++)
{
if (max < polc[i].ev)
{
    max =polc[i].ev;
    seged=i;
}    
}
printf("\n");
printf("%s %s %d",polc[seged].cim,polc[seged].szerzo, polc[seged].ev);
strcpy(xd->cim,polc[seged].cim);
strcpy(xd->szerzo,polc[seged].szerzo);
xd->ev = polc[seged].ev;
konyv_adatok(xd);
free(xd);







}