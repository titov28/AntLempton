#include <cmath>
#include "Ant.h"




void StepRight(struct Ant *ant, int MAXSIZEX, int MAXSIZEY) {
	if (CheckCoordinateChanges(ant) == 0) {
		
		ant->lastY = ant->y; //����. ������� ����������

		if (ant->x - ant->lastX > 0) { // ���������� ������.
			++ant->y; // ������. �
		}
		else {// ����� ���������� ������.
			--ant->y; // ������. �
		}

		ant->lastX = ant->x; //����. ������� ����������
	}
	else {
		ant->lastX = ant->x; //����. ������� ����������
		

		if (ant->y - ant->lastY > 0) { // ���������� ������.
			--ant->x; // ������. �
		}
		else {// ����� ���������� ������.
			++ant->x; // ������. �
		}

		ant->lastY = ant->y; //����. ������� ����������
	}

	/*int temp = CheckOutboundArray(ant, MAXSIZEX, MAXSIZEY);
	switch (temp) {
	case -1:
		return;
		break;
	case 0:
		if (ant->x < 0) {
			ant->x = MAXSIZEX - 1;
			ant->lastX = MAXSIZEX;
		}
		else {
			ant->x = 0;
			ant->lastX = -1;
		}
		break;
	case 1:
		if (ant->y < 0) {
			ant->y = MAXSIZEY - 1;
			ant->lastY = MAXSIZEY;
		}
		else {
			ant->y = 0;
			ant->lastY = -1;
		}
		break;
	}*/
}

void StepLeft(struct Ant *ant, int MAXSIZEX, int MAXSIZEY) {
	if (CheckCoordinateChanges(ant) == 0) {
		
		ant->lastY = ant->y; //����. ������� ����������

		if (ant->x - ant->lastX > 0) { // ���������� ������.
			--ant->y; // ������. �
		}
		else {// ����� ���������� ������.
			++ant->y; // ������. �
		}

		ant->lastX = ant->x; //����. ������� ����������
	}
	else {
		ant->lastX = ant->x; //����. ������� ����������
		

		if (ant->y - ant->lastY > 0) { // ���������� ������.
			++ant->x; // ������. �
		}
		else {// ����� ���������� ������.
			--ant->x; // ������. �
		}

		ant->lastY = ant->y; //����. ������� ����������
	}

	/*int temp = CheckOutboundArray(ant, MAXSIZEX, MAXSIZEY);
	switch (temp) {
	case -1:
		return;
		break;
	case 0:
		if (ant->x < 0) {
			ant->x = MAXSIZEX - 1;
			ant->lastX = MAXSIZEX;
		}
		else {
			ant->x = 0;
			ant->lastX = -1;
		}
		break;
	case 1:
		if (ant->y < 0) {
			ant->y = MAXSIZEY - 1;
			ant->lastY = MAXSIZEY;
		}
		else {
			ant->y = 0;
			ant->lastY = -1;
		}
		break;
	}*/
}

int CheckOutboundArray(struct Ant *ant, int MAXSIZEX, int MAXSIZEY) {
	if (ant->x < 0 || ant->x > MAXSIZEX - 1) {
		return 0;
	}
	else if(ant->y < 0 || ant->y > MAXSIZEY - 1)
	{
		return 1;
	}
	else {
		return -1;
	}
}

int CheckCoordinateChanges(struct Ant *ant) {
	if ((abs(ant->x - ant->lastX) > 0)) {
		return 0;
	}
	else {
		return 1;
	}
}