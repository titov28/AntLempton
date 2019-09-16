#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include "Ant.h"

using namespace std;



void Print(char **field, int sizeX, int sizeY, Ant &ant);
char **  UpgradeFieldandAny(char **field, int &maxSizeX, int &maxSizeY, Ant &ant);
char ** CopyArray(char **field, int sizeX, int sizeY, int sizeX1, int sizeY1, int flag);

int main() {

	int maxSizeX = 10;
	int maxSizeY = 10;

	Ant myAnt = {0, 0 ,0 ,1};
	char **field = new char*[maxSizeX];

	for (int i = 0; i < maxSizeX; i++) {
		field[i] = new char[maxSizeY];
		for (int j = 0; j < maxSizeY; j++) {
			field[i][j] = ' ';
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

		if (count == 1000) {
			Print(field, maxSizeX, maxSizeY, myAnt);
			count = 0;
		}
		//this_thread::sleep_for(chrono::milliseconds(1000));

		count++;
	}

	

	system("pause");

	return 0;
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