#include <iostream>

float matrix_mult(float ** matrix, int size)
{
	float result = 1;

	for(int i = 0; i < size/2; i++)
	{
		for(int j = i + 1; j < size - i - 1; j++)
		{
			if(matrix[i][j] != 0)
				result *= matrix[i][j];
			if(matrix[size - i - 1][j] != 0)
				result *= matrix[size - i - 1][j];
		}

	}
	return result;
}

using namespace std;

int main()
{
	int n; // порядок матрицы
	float **matrix; // матрица

	setlocale(LC_ALL, "russian");


	cout << "Введите порядок матрицы: ";
	cin >> n;

	matrix = new float*[n];
	for(int i = 0; i < n; i++)
		matrix[i] = new float[n];// выделение памяти под массив

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> matrix[i][j];

	cout << "Если умножить элементы, то получится : " << matrix_mult(matrix, n);

	for(int i = 0; i < n; i++)
	{
		delete [] matrix[i]; // отчищаем память
	}
	delete [] matrix;
}
