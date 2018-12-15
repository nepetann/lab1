#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <random>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int n, m;
	cin >> n >> m;
	cout << "\n";
	vector < vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = rand() % 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}

	int mysquare = 0;
	vector<int> d(m, -1), d1(m), d2(m);
	stack<int> MyStack;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			if (a[i][j] == 1)
				d[j] = i;
		while (!MyStack.empty()) MyStack.pop();
		for (int j = 0; j < m; ++j)
		{
			while (!MyStack.empty() && d[MyStack.top()] <= d[j])
				MyStack.pop();

			d1[j] = MyStack.empty() ? -1 : MyStack.top();
			MyStack.push(j);
		}
		while (!MyStack.empty()) MyStack.pop();
		for (int j = m - 1; j >= 0; --j) {
			while (!MyStack.empty() && d[MyStack.top()] <= d[j])  MyStack.pop();
			d2[j] = MyStack.empty() ? m : MyStack.top();
			MyStack.push(j);
		}
		for (int j = 0; j < m; ++j)
			mysquare = max(mysquare, (i - d[j]) * (d2[j] - d1[j] - 1));
	}

	cout << "\n\n" << mysquare;
	_getch();
}
