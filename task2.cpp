#include <iostream>
#include <cmath>

bool IsPositive(int number)
{
	if(number >= 0)
		return true;
	return false;
}

bool IsPrime(int n)
{

	if (n <= 1) 
		return false;

	for (int i = 2; i <= sqrt(n); i++)
       		if (n % i == 0) 
			return false;
    	return true;
}

bool IsAlternating(int *array, int size)
{
	for(int i = 0; i < size - 1; i++)
		if(IsPositive(array[i]) == IsPositive(array[i+1]))
			return false;
	return true;
}

int RemovePrimes(int *&array, int size) // удаляются элементы вместе, чтобы было быстрее
{
	int *buff;
	int array_size_difference = 0;

	for(int i = 0; i < size; i++)
	{
		if(IsPrime(array[i]))
		{
			array[i] = 2;
			array_size_difference++;
		}
	}

	if(array_size_difference == 0)
		return size;

	buff = new int[size - array_size_difference];

	for(int i = 0, j = 0; i < size; i++)
		if(array[i] != 2)
			buff[j++] = array[i];
	delete [] array;
	array = buff;
	return size - array_size_difference;
}

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	int *array, size;
	cout << "Введите размер массива: ";
	cin >> size;

	array = new int[size];
	cout << "Введите элементы массива: ";
	for(int i = 0; i < size; i++)
		cin >> array[i];

	if(IsAlternating(array, size))
	{
		cout << "Массив знакочередующийся" << endl;
		return 0;
	}
	
	size = RemovePrimes(array, size);
	cout << "Массив после удаления простых чисел: ";
	for(int i = 0; i < size; i++)
		cout << array[i] << ' ';

	cout << endl;

	if(IsAlternating(array, size))
		cout << "Теперь массив знакочередующийся" << endl;
	else
		cout << "Всё ещё не знакочередующийся" << endl;

}
