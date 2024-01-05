#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){

//1. feladat
	char rajz[20][24];
int meres[24] = {0,0,0,1,1,2,5,11,14,16,17,19,17,17,16,14,11,5,2,1,1,0,0,0};
for (size_t i = 0; i < 20; i++)
{
    for (size_t j = 0; j < 24; j++)   /* code */
    {
        rajz[i][j]= ' ';
    }
}

for (size_t j = 0; j < 24; j++)
{
        rajz[19-meres[j]][j]='X';

}
for (size_t i = 0; i < 20; i++)
{
    for (size_t j = 0; j < 24; j++)
    {
        printf("%c",rajz[i][j]);
    }
    printf("\n");
    
}
}
