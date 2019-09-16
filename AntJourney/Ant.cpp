#include <cmath>
#include "Ant.h"




void StepRight(struct Ant *ant, int MAXSIZEX, int MAXSIZEY) {
	if (CheckCoordinateChanges(ant) == 0) {
		
		ant->lastY = ant->y; //сохр. текущие координаты

		if (ant->x - ant->lastX > 0) { // координаты увелич.
			++ant->y; // увелич. у
		}
		else {// иначе координаты уменьш.
			--ant->y; // уменьш. у
		}

		ant->lastX = ant->x; //сохр. текущие координаты
	}
	else {
		ant->lastX = ant->x; //сохр. текущие координаты
		

		if (ant->y - ant->lastY > 0) { // координаты увелич.
			--ant->x; // уменьш. х
		}
		else {// иначе координаты уменьш.
			++ant->x; // увелич. х
		}

		ant->lastY = ant->y; //сохр. текущие координаты
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
		
		ant->lastY = ant->y; //сохр. текущие координаты

		if (ant->x - ant->lastX > 0) { // координаты увелич.
			--ant->y; // уменьш. у
		}
		else {// иначе координаты уменьш.
			++ant->y; // увелич. у
		}

		ant->lastX = ant->x; //сохр. текущие координаты
	}
	else {
		ant->lastX = ant->x; //сохр. текущие координаты
		

		if (ant->y - ant->lastY > 0) { // координаты увелич.
			++ant->x; // увелич. х
		}
		else {// иначе координаты уменьш.
			--ant->x; // уменьш. х
		}

		ant->lastY = ant->y; //сохр. текущие координаты
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