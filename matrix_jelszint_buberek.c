
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void matrix_bevetel_kiadad() {
	srand(time(NULL));
	int matrix[12][2];
	for (size_t i = 0; i < 12; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			int rng = rand() % 51 + 50;
			matrix[i][j] = rng;
printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	int haszon[12];
	for (size_t i = 0; i < 12; i++)
	{
		haszon[i] = matrix[i][0] - matrix[i][1];
		printf("%d ", haszon[i]);
	}
	int osszbevetel = 0;
	int osszkiadas = 0;
	for (size_t d = 0; d < 12; d++)
	{
		osszbevetel += matrix[d][0];
		osszkiadas += matrix[d][1];
	}
	printf("Osszbevetel: %d ", osszbevetel);
	printf("\n");
	int ossz;
	ossz = osszbevetel - osszkiadas;
	printf("Ossz: %d ", ossz);
	printf("Tablazat: \n");
	for (size_t i = 0; i < 12; i++)
	{

		printf("%3d %3d %4d \n", matrix[i][0], matrix[i][1], haszon[i]);

	}
}

void idojaras() {
	char matrix[10][24];
	int meres[24];
	for (size_t i = 0; i < 24; i++)
	{
		int rng = rand() % 19 + 1;
		meres[i] = rng;
	}
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 24; j++)
		{
			i = meres[i];
			int eretek = i;

			int ido = j;
			j++;

			matrix[i][0] = eretek;
			matrix[0][j] = ido;
			
			printf("%d", matrix[i][0]);
		}
		printf("\n");
	}


}
void idjaras_2()
{
	char matrix[20][24];
	int meres[24] = {0,0,0,1,1,2,5,11,14,16,17,18,17,16,14,11,5,2,1,1,0,0,0};

	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j= 0; j < 24; j++)
		{
			matrix[i][j] = ' ';
		}
	}
	for (size_t i = 0; i < 24; i++)
	{
		matrix[19 - meres[i]][i] = 'X';
	}
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 24; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
	//jelszint
	int szures[24]; //adatvesztés
	int N = 1, M = 1, L = 23; // ablak adathossz
	int szum = 0;
	szures[0] = meres[0];
	szures[23] = meres[23];
	for (size_t i = M; i < L-M; i++)
	{
		for (size_t k = i-N; k <= i+M; k++)
		{
			szum = 0;
			szum += meres[k];
		}
		szures[i] = szum / (N + M + 1);
	}
	//7.feladat szurt jel

	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 24; j++)
		{
			matrix[i][j] = ' ';
		}
	}
	for (size_t i = 0; i < 24; i++)
	{
		matrix[19 - szures[i]][i] = 'O';
	}

	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 24; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}


}
void buberek() {
	int v[5] = { 5,2,3,8,4 };
	int k;
	for (size_t j = 4; j >= 2; j--)
	{
		for (size_t i = 0; i <= j-1; i++)
		{
			if (v[i]>v[i+1])
			{
				k = v[i];
				v[i] = v[i + 1];
				v[i + 1] = k;
				

			}
		}
	}
	for (size_t z = 0; z < 5; z++)
	{
		printf("%d", v[z]);
	}
}
int main()
{
	//matrix_bevetel_kiadad();
	//idojaras();
	//idjaras_2();
	buberek();

}
