#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float max = -1; // максимальный элемент
	int n; // порядок матрицы
	int x,y; // индексы максимального элемента
	float **matrix; // матрица

	setlocale(LC_ALL, "russian");


	cout << "Введите порядок матрицы: ";
	cin >> n;

	matrix = new float*[n];
	for(int i = 0; i < n; i++)
		matrix[i] = new float[n];// выделение памяти под массив

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			if(fabs(matrix[i][j]) > max)
			{
				max = fabs(matrix[i][j]);
				x = i;
				y = j;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(i != x)
		{	
			for(int j = 0; j < n; j++)
			{
				if(j != y)
				{
					cout << matrix[i][j] << " ";
				}
			}
			cout << endl;
		}
	}

	for(int i = 0; i < n; i++)
	{
		delete [] matrix[i]; // отчищаем память
	}
	delete [] matrix;
}
