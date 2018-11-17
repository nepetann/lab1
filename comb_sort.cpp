#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>
#include <random>
using namespace std;

void comb_sort(vector<double> sort) //сортировка расчёской
{
	int n = 0; //кол-во перестановок
	double fakt = 1.2473309; // фактор уменьшения
	double step = sort.size() - 1;
	int comparsion = 0; //кол-во сравнений

	while (step >= 1)
	{
		for (int i = 0; i + step < sort.size(); ++i)
		{
			if (sort[i] > sort[i + step])
			{
				comparsion++;
				swap(sort[i], sort[i + step]);
				n++;
			}
		}
		step /= fakt;
	}
	for (int i = 0; i < sort.size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < sort.size() - i - 1; j++)
		{
			if (sort[j] > sort[j + 1]) {
				comparsion++;
				swap(sort[j], sort[j + 1]);
				swapped = true;
				++n;
			}
		}

		if (!swapped)
			break;
	}
	for (int i = 0; i < sort.size(); i++)
		cout << sort[i] << "  ";
	cout << "\npermutations: " << n << ", comparsions: " << comparsion << endl;
}

int main()
{
	srand(time(NULL));

	vector<double> arr(50); //тестовый массив
	for (int i = 0; i < 50; i++)
	arr[i] = 1 + rand() % 30;
	comb_sort(arr);

	_getch();
}
