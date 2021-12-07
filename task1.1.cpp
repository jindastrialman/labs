#include <iostream>

int min(int *arr, int size)
{
	int min = arr[0];

	for(int i = 1; i < size; i++)
		if(min > arr[i])
			min = arr[i];

	return min;
}

int sum_between_positives(int *arr, int size)
{
	int sum = 0, first_positive_index = -1, last_positive_index = -1;
	for(int i = 0; i < size; i++)
	{
		if(arr[i] > 0){
			if(first_positive_index == -1)
				first_positive_index = i;
			last_positive_index = i;
		}
	}

	if(first_positive_index < 0)
		return sum;

	for(int i = first_positive_index; i <= last_positive_index; i++)
		sum += arr[i];

	return sum;
}

void push_zeros(int * &arr, int size)
{
	int zero_offset = 0;
	for(int i = 0; i < size; i++)
		if(arr[i] == 0) zero_offset++;

	int *buff = new int[size];
	for(int i = 0; i < zero_offset; i++) buff[i] = 0;
	for(int i = 0, j = zero_offset; i < size; i++)
		if(arr[i] != 0)
			buff[j++] = arr[i];

	delete [] arr;
	arr = buff;
}

using namespace std;

int main()
{	
	setlocale(LC_ALL, "russian");

	int *arr, size;

	cout << "Введите размер массива : ";
	cin >> size;

	arr = new int[size];

	cout << "Введите элементы массива : ";
	for(int i = 0; i < size ; i++) cin >> arr[i];

	cout << "Минимальный элемент массива - " << min(arr, size) << endl;
	cout << "Сумма элементов массива между первым и последним положительным элементом - " << sum_between_positives(arr, size) << endl;
	cout << "Элементы равные нулю убраны в начало и теперь массив такой :\n";
	push_zeros(arr, size);

	for(int i = 0 ; i < size; i++) cout << arr[i] << ' ';
	cout << "Сумма элементов массива между первым и последним положительным элементом всё ещё равна - " << sum_between_positives(arr, size) << endl;
	delete [] arr;
}
