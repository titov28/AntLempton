#ifndef ANT_H
#define ANT_H

struct Ant {
	int x = 0, y = 0;
	int lastX = 0, lastY = 0;
};

void StepRight(struct Ant *ant, int MAXSIZEX, int MAXSIZEY); // ��� ������

void StepLeft(struct Ant *ant, int MAXSIZEX, int MAXSIZEY); // ��� �����

int CheckOutboundArray(struct Ant *ant, int MAXSIZEX, int MAXSIZEY); // �������� ������ �� ������� ������� -1 ��� , 0 ��� � , 1 ��� �

int CheckCoordinateChanges(struct Ant *ant); // ����������� ����� ���������� ���������� 0 ��� �, 1 ��� �




#endif