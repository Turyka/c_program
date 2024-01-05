#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

int vektor[5] = {5,4,8,2,3};
int k;
for (size_t j= 5; j > 0; j--)
{
    for (size_t i = 0; i<j-1; i++)
    {
        if (vektor[i]>vektor[i+1])
        {
            k = vektor[i];
            vektor[i]= vektor[i+1];
            vektor[i+1] = k;
        }
        
    }
    printf("\n");
}
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d",vektor[i]);
    }


}