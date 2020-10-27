#include <iostream>
#include "MyVector.h"
#include "Matrix.h"


int main(int argc, char* argv[])
{
	TMatrix<int> a(5), b(5), c(5);
	int i, j;
	cout << "TEST MATRIX" << endl;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
		{
			a[i][j] = i;
			b[i][j] = i;
		}
	c = a + b;

	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b= " << endl << b << endl;
	cout << "Matrix c = a + b " << endl << c << endl;

	return 0;
}