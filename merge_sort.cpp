#include <iostream>
#include <conio.h>
#include<ctime>
#include<vector>
#include<random>
using namespace std;

void merge_sort(vector<int> &arr, int left, int right, int &comparison, int& permutation)
{
	if (right == left)
	{
		comparison++;
		return;
	}
	if (right - left == 1)
	{
		comparison++;
		if (arr[right] < arr[left])
		{
			permutation++;
			swap(arr[right], arr[left]);
		}
		return;
	}
	int m = (right + left) / 2;

	merge_sort(arr, left, m, comparison, permutation);
	merge_sort(arr, m + 1, right, comparison, permutation);

	int *buf = new int[arr.size()];
	int xleft = left, xright = m + 1, cur = 0;

	while (right - left + 1 != cur) {
		if (xleft > m) {
			comparison++;
			buf[cur++] = arr[xright++];
			permutation++;
		}
		else if (xright > right) {
			comparison++;
			buf[cur++] = arr[xleft++];
			permutation++;
		}
		else if (arr[xleft] > arr[xright]) {
			comparison++;
			buf[cur++] = arr[xright++];
			permutation++;
		}
		else {
			comparison++;
			buf[cur++] = arr[xleft++];
			permutation++;
		}
	}
	for (int i = 0; i < cur; i++)
	{
		arr[i + left] = buf[i];
		permutation++;
	}
}

int main()
{
	unsigned int start_time = 0, end_time = 0;
	int comparison = 0, permutation = 0;
	//array of 100 random numbers
	cout << "Array of merge sort: \n";
	vector<int> arr1(100);
	for (int i = 0; i < 100; i++)
	{
		arr1[i] = 1 + rand() % 100;
		cout << arr1[i] << ", ";
	}
	cout << "\n\n";
	start_time = clock();
	merge_sort(arr1, 0, 100 - 1, comparison, permutation);
	end_time = clock();
	for (int i = 0; i < arr1.size(); i++)
		cout << arr1[i] << "  ";

	cout << "\n\nsorting time: " << end_time - start_time << " milliseconds";
	start_time = 0, end_time = 0;

	_getch();
}
