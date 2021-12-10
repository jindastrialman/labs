#include <iostream>

struct date
{
	int h;
	int m;
	int s;
	char type; // 'e' for end, 's' for start;
};

bool operator<=(const date &a1, const date &a2)
{
	if(a1.h < a2.h)
		return true;
	if(a1.h == a2.h)
	{
		if(a1.m < a2.m)
			return true;
		if(a1.m == a2.m)
		{
			if(a1.s < a2.s)
				return true;
			if(a1.s == a2.s)
				if(a1.type >= a2.type)
					return true;
		}
	}
	return false;	
}

void swap(date* a, date* b)
{
    date t = *a;
    *a = *b;
    *b = t;
}
 
int partition (date arr[], int low, int high)
{
    date pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void sort(date *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

date* maximum_overlap(date *times, int count)
{
	sort(times, 0, count - 1);
	date *result = new date[2];
	int maxCount = 0, curCount = 0;

	for(int i = 0; i < count; i++)
	{
		if(times[i].type == 's')
			curCount++;
		else
			curCount--;
		
		if(maxCount < curCount)
		{
			maxCount = curCount;
			result[0] = times[i];
			int j;
			
			for(j = i; times[j].type != 'e'; j++);
						result[1] = times[j];
		}
	}
	for(int i = 0; i < count; i++) std::cout << times[i].h << ' ' << times[i].m << ' ' << times[i].s <<' ' << times[i].type<< std::endl;
	return result;
}

int main()
{
	setlocale(LC_ALL, "russian");
	date *times;
	int count;
	std::cout << "Введите колличество посетителей";
	std::cin >> count;
	count *= 2;
	times = new date[count];
	std::cout << "Введите время прихода и ухода в формате \"чч мм сс чч мм сс\"";
	for(int i = 0; i < count; i++)
	{
		int h,m,s;
		std::cin >> h >> m >> s;
		times[i].h = h;
		times[i].m = m;
		times[i].s = s;

		if(i % 2 == 0)
			times[i].type = 's';
		else
			times[i].type = 'e';
	}

	date *result = maximum_overlap(times, count);
	
	std::cout << "В этом промежутке было больше всего посетителей: " << std::endl;
	std::cout << result[0].h << ' ' << result[0].m << ' ' << result[0].s << std::endl;
	std::cout << result[1].h << ' ' << result[1].m << ' ' << result[1].s << std::endl;
}
