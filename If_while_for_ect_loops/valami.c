#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
float terulet(float a, float b)
{
	float terulet_eredmeny = a * b;
	return terulet_eredmeny;
}
float kerulet(float a, float b)
{
	float kerulet_eredmeny = 2*(a + b);
	return kerulet_eredmeny;

}
int main()
{
	/*
	srand(time(NULL));
	
	for (size_t i = 0; i < 9; i++)
	{
		float rng = rand() % 10;
		printf("%.2f \n", rng);
	}
	*/


	/*
	int hanyszor;
	while (true)
	{
		int xd = rand() % 101;
		for (size_t i = 0; i < sizeof(xd); i++)
		{
			hanyszor = i;
			
			if (xd == 100)
			{
				break;
			}
		}
	}
	printf("%i", hanyszor);
	*/
	/*
	int i=1, rnd;
	do
	{
		rnd = rand() % 101;
		
		printf("%-3d %3d \n",i, rnd);
		i++;
	} while (rnd!=100);
	*/
	srand(time(NULL));
	int j = 1;

	bool sajt = false;
		while (j <= 50)
		{
			int rnd = rand() % 101;
			j++;
			printf("%i \n", rnd);
			if (rnd == 100)
			{
				printf("Pog találtunk");
				sajt = true;
				break;
			} 
		}
		if (sajt == false)
		{
			printf("Nem talaltunk olyan szamot amely 100 lenne");
		}
		
		
	/*
	srand(time(NULL));
	int gondolat;

	int rng = rand() % 10 + 1;

	int h = 1;
	printf("%i \n", rng);

	 while (h <= 3) {
        printf("lehetosegek szama:%i. Gondoltam egy szamra 1-10 ig: ", h);
        scanf("%i", &gondolat);
        h++;

        if (gondolat < rng) {
            printf("A gondolt szám nagyobb a szam \n");
			continue;
        } else if (gondolat > rng) {
            printf("A gondolt szám kisebb a szam \n");
			continue;
        } else {
            printf("Nyertel");
            break;
        }
    }
*/


	
	
	/*
	float a, b;
	char muv;
	printf("kérem a a ertkekt: ");
	scanf_s("%f", &a);
	printf("kérem a b ertkekt: ");
	scanf_s("%f", &b);
	printf("T / K: ");
	scanf_s(" %c", &muv);
	switch (muv)
	{
	case 'T':
		printf("%f Terulet: ", terulet(a, b));
		break;
	case 'K':
		printf("%f, Kerulet:", kerulet(a, b));
		break;
	}
	*/
	
		

	/*
	int a;
	printf("Kerek be a:");
	scanf_s("%i",&a);
	int fakt = 1;
	for (size_t i = 1; i <=a; i++)
	{
		fakt *= i;
		printf("%i",fakt);
	}
	*/
	
	/*
	float a, b,eredmeny;
	char muv;
	printf("A erteke: ");
	scanf_s("%f", &a);

	printf("B erteke: ");
	scanf_s("%f", &b);

	printf(" müvelet: ");
	scanf_s(" %c", &muv);
	switch(muv)
	{
	case '+':
		eredmeny = a + b;
	break;
	case '-':
		eredmeny = a - b;
	break;
	case '*':
		eredmeny = a * b;
	break;
			case '/':
				eredmeny = a / b;
	}
	printf("%f", eredmeny);
	*/
	/*
	for (size_t i = 1; i <=10 ; i++)
	{
		printf("%i \n", i );
	}

	int d = 1;
	while (d <= 10)
	{
		printf("%i ", d);
		d++;
	}
	printf("\n");
	int s = 1;
	do
	{
		s++;
	printf("%i ", s);
	} while (s <= 10);
	*/
}
