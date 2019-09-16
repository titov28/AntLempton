#ifndef ANT_H
#define ANT_H

struct Ant {
	int x = 0, y = 0;
	int lastX = 0, lastY = 0;
};

void StepRight(struct Ant *ant, int MAXSIZEX, int MAXSIZEY); // шаг вправо

void StepLeft(struct Ant *ant, int MAXSIZEX, int MAXSIZEY); // шаг влево

int CheckOutboundArray(struct Ant *ant, int MAXSIZEX, int MAXSIZEY); // проверка выхода за границу массива -1 нет , 0 это Х , 1 это У

int CheckCoordinateChanges(struct Ant *ant); // определение какие координаты изменились 0 это Х, 1 это У




#endif