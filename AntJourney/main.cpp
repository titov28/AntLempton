#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <Windows.h>
#include "Ant.h"

using namespace std;



void Print(char **field, int sizeX, int sizeY, Ant &ant);
void HardPrint(char **field2, int sizeN1, int sizeN2, char **field, int sizeX, int sizeY, Ant &ant);

char **  UpgradeFieldandAny(char **field, int &maxSizeX, int &maxSizeY, Ant &ant);
char ** CopyArray(char **field, int sizeX, int sizeY, int sizeX1, int sizeY1, int flag);

int main() {

	int maxSizeX = 80;
	int maxSizeY = 80;

	int n1 = 300;
	int n2 = 80;

	Ant myAnt = {10, 10, 10, 11};
	char **field = new char*[maxSizeX];
	char **field2 = new char*[n1];


	for (int i = 0; i < maxSizeX; i++) {
		field[i] = new char[maxSizeY];
		field2[i] = new char[n2];
		for (int j = 0; j < maxSizeY; j++) {
			field[i][j] = ' ';
			field2[i][j] = ' ';
		}
	}

	int count = 0;

	while (true) {

		field = UpgradeFieldandAny(field, maxSizeX, maxSizeY, myAnt);

		if (field[myAnt.y][myAnt.x] == ' ') {
			field[myAnt.y][myAnt.x] = 'X';
			
			StepRight(&myAnt, maxSizeX, maxSizeY);
		}
		else {
			field[myAnt.y][myAnt.x] = ' ';
			
			StepLeft(&myAnt, maxSizeX, maxSizeY);
		}

		if (count == 10) {
		    HardPrint(field2, n1, n2, field, maxSizeX, maxSizeY, myAnt);
			//Print(field, maxSizeX, maxSizeY, myAnt);
			count = 0;
		}
		//this_thread::sleep_for(chrono::milliseconds(100));

		count++;
	}

	

	system("pause");

	return 0;
}


void HardPrint(char **field2, int sizeN1, int sizeN2, char **field, int sizeX, int sizeY, Ant &ant) {
	COORD position;
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < sizeN1; i++) {
		for (int j = 0; j < sizeN2; j++) {
			if (i < sizeX && j < sizeY) {
				if (field2[i, j] != field[i, j]) {
					position.X = i;
					position.Y = j;
					SetConsoleCursorPosition(hout, position);
					printf_s("%c", field[j][i]);
				}
			}
		}
		//printf_s("\n");
	}


	printf_s("\nSize x = %4d y = %4d", sizeX, sizeY);
	printf_s("\nAnt x = %3d y = %3d LastX = %3d LastY = %3d", ant.x, ant.y, ant.lastX, ant.lastY);
}


void Print(char **field, int sizeX, int sizeY, Ant &ant) {
	system("cls");
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			printf_s("%c", field[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\nSize x = %d y = %d", sizeX, sizeY);
	printf_s("\nAnt x = %d y = %d LastX = %d LastY = %d", ant.x, ant.y, ant.lastX, ant.lastY);
}

char **  UpgradeFieldandAny(char **field, int &maxSizeX, int &maxSizeY, Ant &ant) {
	int sizeX = maxSizeX;
	int sizeY = maxSizeY;
	int flag = 1;
	
	if ((ant.x < 0 || ant.y < 0 ) || (ant.x >= maxSizeX || ant.y >= maxSizeY)) {
		sizeX = maxSizeX + 15;
		sizeY = maxSizeY + 15;
		if (ant.x < 0 || ant.y < 0) {
			ant.x += 15;
			ant.lastX = ant.x + 1;
			ant.y += 15;
			ant.lastY = ant.y + 1;
			flag = 0;
		}
	}else {
		return field;
	}

	char ** field2 = CopyArray(field, maxSizeX, maxSizeY, sizeX, sizeY, flag);

	maxSizeX = sizeX;
	maxSizeY = sizeY;

	return field2;
}

char ** CopyArray(char **field, int sizeX, int sizeY, int sizeX1, int sizeY1, int flag) {
	char **field2 = new char*[sizeX1];
	int x = sizeX1 - sizeX;
	int y = sizeY1 - sizeY;

	for (int i = 0; i < sizeX1; i++) {
		field2[i] = new char[sizeY1];
		for (int j = 0; j < sizeY1; j++) {
			field2[i][j] = ' ';
		}
	}

	if (flag == 0) {
		for (int i = 0; i < sizeX; i++) {
			for (int j = 0; j < sizeY; j++) {
				field2[i + x][j + y] = field[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < sizeX; i++) {
			for (int j = 0; j < sizeY; j++) {
				field2[i][j] = field[i][j];
			}
		}
	}


	for (int i = 0; i < sizeX; i++) {
		delete[] field[i];
	}

	delete[] field;

	
	return field2;
}