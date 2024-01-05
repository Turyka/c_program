#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

int main()
{
int v[10],i;
	/*
	// 10 elem� vektor feltoltese billentyuzetrol
	for (i = 0; i < 10; i++)
		scanf("%d", &v[i]);
	// kiiras
	for (i = 0; i < 10; i++)
		printf("%d ", v[i]);
	*/

	// 10 elem� vektor feltoltese veletlen szamokkal 1-9 tartomanybol es atlag szamitas
	printf("\n");
	srand((unsigned)time(NULL));
	double atlag=0;
	for (i = 0; i < 10; i++)
	{
		v[i] = rand() % 9 + 1;
		atlag += v[i];
		printf("%d ", v[i]);
	}
	printf("\natlag: %lf\n",atlag/10);

	// minimum kivalasztasa a vektorbol
	int min=v[0];
	for (i = 1; i < 10; i++)
		if (v[i] < min)
			min = v[i];
	printf("min: %d\n",min);

	// minimum kivalasztasos rendezes
	int hely,j,k;
	for (j = 0; j < 9; j++)
	{
		min = v[j];
		hely = j;
		for(i=j+1;i<10;i++)
			if (v[i] < min)
			{
				min = v[i];
				hely = i;
			}
		k = v[j];
		v[j] = v[hely];
		v[hely] = k;
	}

	for (i = 0; i < 10; i++)
		printf("%d ", v[i]);

	// 2x3-as matrix feltoltese veletlen szamokkal
	printf("\n");
	int M[2][3];
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			M[i][j] = rand() % 9 + 1;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
printf("\n");
	// minimum kivalasztasa matrixbol
	min = M[0][0];
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			if (M[i][j] < min)
				min = M[i][j];
	printf("\nmin: %d\n",min);

	// minimum kivalasztasos rendezes matrixban segedvektorral
	int seged[6];
		//1. Adatok masolasa a segedvektorba
			// 1.1 valtozat: for ciklusos masolas
	k = 0;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
		{
			seged[k] = M[i][j];
			k++;
		}

	for (i = 0; i < 6; i++)
		printf("%d ",seged[i]);
			// 1.2 valtozat: memcpy masolas
	
	//memcpy(seged, M, sizeof(int) * 6);
	printf("\n");
	for (i = 0; i < 6; i++)
		printf("%d ", seged[i]);

		//2. Adatok rendezese a segedvektorban
	for (j = 0; j < 5; j++)
	{
		min = seged[j];
		hely = j;
		for (i = j + 1; i < 6; i++)
			if (seged[i] < min)
			{
				min = seged[i];
				hely = i;
			}
		k = seged[j];
		seged[j] = seged[hely];
		seged[hely] = k;
	}

	printf("\n");
	for (i = 0; i < 6; i++)
		printf("%d ", seged[i]);
		//3. adatok vissza masolasa a matrixba
        int z=0;
    for (size_t i = 0; i < 2 ;i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
           M[i][j]=seged[z];
           z++;
        }
        
    }
    

	printf("\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
}