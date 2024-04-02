#include <iostream>
#include<string>
#include<conio.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <windows.h>
#pragma warning(disable:4996)

using namespace std;
class karakterek {
	int sor;
	int oszlop;
	char alakzat;
public:
	void setSor(int s)
	{
		sor = s;
	};
	int getsor()
	{
		return sor;
	};
	void setOszlop(int o)
	{
		oszlop = o;
	}
	int getOszlop()
	{
		return oszlop;
	}
	void setAlakzat(char a)
	{
		alakzat = a;
	}
	char getAlakzat()
	{
		return alakzat;
	}
	int pontszam = 0;
};
void setBackgroundBlue() {
	cout << "\033[44m"; 
}
void setBackgroundRed() {
	cout << "\033[41m"; 
}
void resetBackground() {
	cout << "\033[0m"; 
}
void rajzol(char** palya, int ps, int po, karakterek jatekos1, karakterek jatekos2, karakterek labda)
{
	palya[jatekos1.getsor()][jatekos1.getOszlop()] = jatekos1.getAlakzat();
	palya[jatekos2.getsor()][jatekos2.getOszlop()] = jatekos2.getAlakzat();
	palya[labda.getsor()][labda.getOszlop()] = labda.getAlakzat();
	setBackgroundRed();
	for (size_t j = 0; j < po; j++)
	{
		cout << '-';
	}
	resetBackground();
	printf("\n");

	for (size_t i = 0; i < ps; i++)
	{
		for (size_t j = 0; j < po; j++)
		{
			if (j != 0 && j != ps - 1)
				setBackgroundBlue();
			else
				resetBackground();
			cout << palya[i][j];
		}
		printf("\n");
	}

	setBackgroundRed();
	for (size_t j = 0; j < po; j++)
	{
		cout << '-';
	}
	resetBackground();
	cout << endl << "Labda sor: " << labda.getsor() << " | " << " labda oszlop: " << labda.getOszlop() << endl;// tesztként

}

void clearBuffer() {
	while (_kbhit()) {
		_getch();
	}
}
int main()
{
	srand((unsigned)time(NULL));
	char** palya;
	char c = 'w';
	int seged;
	bool irany_x_tengely = true; // True = balra megy | False = jobbra megy
	int irany_y_tengely = 0; // 1 = fel | 2 = le | 3 = nem lesz
	int ps = 20, po = 20;
	// Karakterek megadása
	karakterek jatekos1, jatekos2, labda;
	jatekos1.setAlakzat('|');
	jatekos1.setSor(ps / 2);
	jatekos1.setOszlop(0);
	jatekos2.setAlakzat('|');
	jatekos2.setSor(ps / 2);
	jatekos2.setOszlop(po - 1);
	labda.setAlakzat('o');
	labda.setOszlop(ps / 2);
	labda.setSor(po / 2);
	// pálya alap megadása
	palya = new char* [ps];
	for (size_t i = 0; i < ps; i++)
	{
		palya[i] = new char[po];
	}

	for (size_t i = 0; i < ps; i++)
	{
		for (size_t j = 0; j < po; j++)
		{
			palya[i][j] = ' ';
		}
	}

	// pálya meghivása
	do
	{
		cout << "\033[2J\033[1;1H"; // Clear screen
		cout << "jatekos1 Pontszam: " << jatekos1.pontszam << '\t' << "jatekos2 Pontszam:" << jatekos2.pontszam << endl; // Jatékos1 és Játékos2 pontszámai

		rajzol(palya, po, ps, jatekos1, jatekos2, labda);
		palya[labda.getsor()][labda.getOszlop()] = ' ';

		if (labda.getOszlop() == jatekos1.getOszlop() + 1 && labda.getsor() == jatekos1.getsor()) // ha labda találkozik a jatekos1-el akkor visszaüti 3 opcioba
		{
			int randomNumber = rand() % 3 + 1; // jobbra megy fix, és 3 közül választ: fel | le | egyenes
			irany_x_tengely = false;
			switch (randomNumber)
			{
			case 1:
				irany_y_tengely = 1;
				break;
			case 2:
				irany_y_tengely = 2;
				break;
			case 3:
				irany_y_tengely = 3;
				break;
			}
		}
		else if (labda.getOszlop() == jatekos2.getOszlop() - 1 && labda.getsor() == jatekos2.getsor()) // ha labda találkozik a jateko2-el akkor visszaüti 3 opcioba
		{
			int randomNumber = rand() % 3 + 1; // balra megy fix, és 3 közül választ: fel | le | egyenes
			irany_x_tengely = true;
			switch (randomNumber)
			{
			case 1:
				irany_y_tengely = 1;
				break;
			case 2:
				irany_y_tengely = 2;
				break;
			case 3:
				irany_y_tengely = 3;
				break;
			}
		}

		else if (labda.getOszlop() == -1) // jatekos2 pontja, labda vissza a kezdő helyre, és a Jatekos1 kezd, mert jatekos2 kapott pontot
		{
			jatekos2.pontszam++;
			irany_x_tengely = false;
			irany_y_tengely = 3;
			labda.setSor(po / 2);
			labda.setOszlop(ps / 2);
		}
		else if (labda.getOszlop() == ps) // jatekos1 pontja, labda vissza a kezdő helyre, és a Jatekos2 kezd, mert jatekos1 kapott pontot
		{
			jatekos1.pontszam++;
			irany_x_tengely = true;
			irany_y_tengely = 3;
			labda.setSor(po / 2);
			labda.setOszlop(ps / 2);
		}

		if (irany_x_tengely == true) // Balra megy a labda
		{
			if (irany_y_tengely == 1) // balra fel megy a labda
			{
				labda.setOszlop(labda.getOszlop() - 1);
				labda.setSor(labda.getsor() - 1);
				if (labda.getsor() == 0) //ha szélén van akkor visszapattan
				{
					irany_y_tengely = 2;
				}
			}
			else if (irany_y_tengely == 2)// balra le megy a labda
			{
				labda.setOszlop(labda.getOszlop() - 1);
				labda.setSor(labda.getsor() + 1);
				if (labda.getsor() == po - 1) //ha szélén van akkor visszapattan
				{
					irany_y_tengely = 1;
				}
			}
			else // Csak balra megy a labda
			{
				labda.setOszlop(labda.getOszlop() - 1);
			}

		}
		if (irany_x_tengely == false) // Jobbra megy a labda
		{
			if (irany_y_tengely == 1) // jobbra fel megy a labda
			{
				labda.setOszlop(labda.getOszlop() + 1);
				labda.setSor(labda.getsor() - 1);
				if (labda.getsor() == 0) //ha szélén van akkor visszapattan
				{

					irany_y_tengely = 2;
				}
			}
			else if (irany_y_tengely == 2) // jobbra le megy a labda
			{
				labda.setOszlop(labda.getOszlop() + 1);
				labda.setSor(labda.getsor() + 1);
				if (labda.getsor() == po - 1) //ha szélén van akkor visszapattan
				{
					irany_y_tengely = 1;
				}
			}
			else // csak Jobbra megy a labda
			{
				labda.setOszlop(labda.getOszlop() + 1);
			}
		}

		clearBuffer(); // meghivás törli a sokszor keütött karaktereket

		static bool ballShouldSleep = false;
		if (!ballShouldSleep) {
			this_thread::sleep_for(chrono::milliseconds(300)); // Delay a labda miatt
			ballShouldSleep = true;
		}

		if (_kbhit()) {
			c = _getch();

			switch (c)
			{
			case 'w':
				if (jatekos1.getsor() > 0)
				{
					palya[jatekos1.getsor()][jatekos1.getOszlop()] = ' ';
					jatekos1.setSor(jatekos1.getsor() - 1);
				}
				break;
			case 's':
				if (jatekos1.getsor() < ps - 1)
				{
					palya[jatekos1.getsor()][jatekos1.getOszlop()] = ' ';
					jatekos1.setSor(jatekos1.getsor() + 1);
				}
				break;
			case 'o':
				if (jatekos2.getsor() > 0)
				{
					palya[jatekos2.getsor()][jatekos2.getOszlop()] = ' ';
					jatekos2.setSor(jatekos2.getsor() - 1);
				}
				break;
			case 'l':
				if (jatekos2.getsor() < ps - 1)
				{
					palya[jatekos2.getsor()][jatekos2.getOszlop()] = ' ';
					jatekos2.setSor(jatekos2.getsor() + 1);
				}
				break;
			}
		}
		ballShouldSleep = false;
		if (jatekos1.pontszam >= 5)
		{
			cout << "jatekos1 nyert" << endl;
			exit(-1);
		}
		if (jatekos2.pontszam >= 5)
		{
			cout << "jatekos2 nyert" << endl;
			exit(-1);
		}
	} while (c != 'q');

	for (size_t i = 0; i < ps; i++)
	{
		delete[] palya[i];
	}
	delete[] palya;
}
