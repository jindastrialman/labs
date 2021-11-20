#include <iostream>

using namespace std;

int **matrix;
int size;
int a, b, c; // [x][y]: x - откуда, y - куда

bool IsAnyRoadToC()
{
	for(int i = 0; i < size; i++)
		if(matrix[i][c - 1] == 1)
			return true;
	return false;	
}

bool IsAnyRoadToB()
{
	for(int i = 0; i < size; i++)
		if(matrix[i][b - 1] == 1)
			return true;
	return false;
}

bool SecondPathFind(int);

bool FirstPathFind(int location)
{
	for(int i = 0; i < size; i++)
	{
		if(matrix[location][i] > 0)
		{
			matrix[location][i] = 0;

			if(i == c - 1)
				if(SecondPathFind(c - 1))
					return true;
			else
				FirstPathFind(i);

			matrix[location][i] = 1;
		}
	}
	return false;
}

bool SecondPathFind(int location)
{
	for(int i = 0; i < size; i++)
	{
		if(matrix[location][i] > 0)
		{
			matrix[location][i] = 0;

			if(i == b - 1)
				return true;
			else
				if(SecondPathFind(i))
					return true;

			matrix[location][i] = 1;
		}
	}
	return false;
}

int main()
{

	setlocale(LC_ALL, "russian");
	do
	{
		cout << "Введите колличество пунктов назначения, A, B, C: \n";
		cin >> size >> a >> b >> c;
	} while (size < a || size < b || size < c);

	cout << "Введите Матрицу смежности";
	matrix = new int* [size];
	for(int i = 0; i < size; i++)
	{
		matrix[i] = new int [size];
		for(int j = 0; j < size; j++)
			cin >> matrix[i][j];
	}

	if(!IsAnyRoadToC() || !IsAnyRoadToB())
	{
		cout << "Пути к B через C нет" << endl;
		return 0;
	}

	if(FirstPathFind(a - 1)) cout << "Путь из A в B через C существует";
	else cout << "Пути из A в B через C нет";

	for(int i = 0; i < size; i++)
		delete [] matrix[i]; // отчищаем память
	delete [] matrix;
}
