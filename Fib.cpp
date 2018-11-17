#include <iostream>
#include <conio.h>
#include<ctime>
using namespace std;

//exponential time
int fib(unsigned int n)
{
	if (n < 2) return n;
	return fib(n - 1) + fib(n - 2);
}
//polynomial time
void p_fib(int k)
{
	int a, b;
	a = 0;
	b = 1;
	while (k <= 0)
	{
		cout << "ERROR! Enter the number greater than zero: ";
		cin >> k;
	}
	while (k != 0)
	{
		a = a + b;
		b = a - b;
		k = k - 1;
		if (k == 0)
			cout << a << " ";
	}
}
void ForWorkOfFibonacci()
{
	unsigned int start_time = 0, end_time = 0;
	unsigned int number = 42;

	//exponential time
	start_time = clock();
	cout << fib(number);
	end_time = clock();
	cout << "\n\ntime: " << end_time - start_time << " milliseconds\n\n\n";

	start_time = end_time = 0;

	//polynomial time
	start_time = clock();
	p_fib(number);
	end_time = clock();
	cout << "\n\ntime: " << end_time - start_time << " milliseconds";
}

int main()
{
	ForWorkOfFibonacci();
	
	_getch();
}
