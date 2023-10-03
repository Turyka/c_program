// veletlen szamok generalasa
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

int main()
{
	srand(time(NULL));
    /*
	//10 db veletlen szam 0 es 100 kozt
	for (int i = 1; i <= 10; i++)
		printf("%d\n", rand()%101);
        */
       /*
	//Addig generalja a szamokat, amig 100-at nem dob
	int i = 1,rnd;
	do
	{
		rnd = rand() % 101;
		printf("%-3d %3d\n",i,rnd);
		i++;
	} while (rnd!=100);
    */

	float xd = 32.8984358567485;
	printf("%6.3f",xd);

    
	//Legfeljebb 50 probalkozasbol kell 100-at generalnia. Ha nem sikerul, akkor errol tajekoztat
    /*
	int i = 1;
    int rnd;
	do
	{
		rnd = rand() % 101;
		printf("%-3d %3d\n", i, rnd);
		i++;
	} while (rnd != 100 && i<=50);
	if (rnd != 100)
		printf("Nem talaltam 100-at.");
	else
		printf("Van 100.");
        */
}
