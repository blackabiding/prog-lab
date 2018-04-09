// lab24.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
int main()
{
	int x = 1;
	switch (x)
	{
	case 0:
	{const int stc = 100;
	int **a = NULL, i = 0, j = 0, elem = 1;
	int studcount; double aver[stc]; int sum = 0, less3 = 0, onlybest = 0; bool best = true;
	printf_s("Введите количество студентов: "); scanf_s("%d", &studcount);
	a = (int**)malloc(studcount * sizeof(int*));
	for (i = 0; i < studcount; i++) {
		a[i] = NULL;
		j = 0; best = true; sum = 0;
		do {
			printf_s("a[%d][%d]= ", i, j);
			scanf_s("%d", &elem);
			if (elem != 0) {
				a[i] = (int*)realloc(a[i], (j + 1) * sizeof(int));
				a[i][j] = elem;
				j++;
				sum += elem;
				if (elem != 5 && elem != 4) best = false;
			}

		} while (elem != 0);
		aver[i] = double(sum) / j;
		if (j < 3) less3++;
		if (best) onlybest++;
	}
	for (int i = 0; i < studcount; i++)
	{
		printf_s("Средняя оценка %d-го студента = %.2lf\n", i, aver[i]);
	}
	printf_s("Количество студентов с оценками меньше 3 штук = %d\n", less3);
	printf_s("Количество студентов с только 4 и 5 =  %d\n", onlybest);
	free(a);

	break; }
	case 1:
	{
		int strnum;
		printf_s("Введите кол-во строк: "); scanf_s("%d", &strnum);
		int **a = NULL; int *m;
		a = (int**)malloc(strnum * sizeof(int*));
		m = (int*)malloc(strnum * sizeof(int));
		
		for (int i = 0; i < strnum; i++)
		{
			printf_s("Длина %d-ой строки: ", i);
			scanf_s("%d", &m[i]);
			a[i] = (int*)malloc(m[i] * sizeof(int));
			for (int j = 0; j < m[i]; j++)
			{
				printf_s("a[%d][%d] = ", i, j);
				scanf_s("%d", &a[i][j]);
			}
		}
		int min = a[0][0], max = a[0][0]; int imax = 0, imin = 0;
		for (int i = 0; i < strnum; i++)
		{
			for (int j = 0; j < m[i]; j++)
			{
				if (a[i][j] > max) {
					max = a[i][j]; imax = i;
				}
				if (a[i][j] < min) {
					min = a[i][j]; imin = i;
				}
			}
		}
		int maxlen; if (m[imax] > m[imin]) { maxlen = m[imax]; a[imin] = (int*)realloc(a[imin], maxlen*sizeof(int)); }
		else {
			maxlen = m[imin]; a[imax] = (int*)realloc(a[imax], maxlen * sizeof(int));
		}
		int *temp = (int*)malloc(maxlen * sizeof(int));
		int t; t = m[imin]; m[imin] = m[imax]; m[imax] = t;
		for (int j = 0; j < maxlen; j++)
		{
			temp[j] = a[imax][j];
			a[imax][j] = a[imin][j];
			a[imin][j] = temp[j];
		}
		for (int i = 0; i < strnum; i++)
		{
			for (int j = 0; j < m[i]; j++)
			{
				printf_s("%d ", a[i][j]);
			}
			printf_s("\n");
		}
		break;
	}
	}
	return 0;
}