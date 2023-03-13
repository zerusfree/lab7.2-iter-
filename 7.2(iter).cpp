#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a,const int n);
void Sort(int** a,const int n);
void Change(int** a, const int row1, const int row2, const int n);

int main()
{
	int n = 4;
	int Low = 0;
	int High = 100;
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];


	Create(a, n, Low, High);
	Print(a, n);
	Sort(a, n);
	Print(a, n);

	return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1 );
}

void Print(int** a, const int n)
{
	cout << endl;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}

	cout << endl;
}

void Sort(int** a, const int n)
{
	for (int i0 = 0; i0 < n - 1; i0++)
		for (int i1 = 0; i1 < n - i0 - 1; i1++)
			if ((a[i1][i1] < a[i1 + 1][i1 + 1]))
				Change(a, i1, i1 + 1, n);

}

void Change(int** a, const int row1, const int row2, const int n)
{
	int tmp;
	tmp = a[row1][row1];
	a[row1][row1] = a[row2][row2];
	a[row2][row2] = tmp;

}
