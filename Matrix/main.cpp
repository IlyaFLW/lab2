#include <iostream>
#include "MyVector.h"
#include "Matrix.h"


int main(int argc, char* argv[])
{
	TMatrix<int> a(5), b(5), c(5);
	int i, j, g = 5;
	cout << "TEST MATRIX" << endl;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < g; j++)
		{
			a[i][j] = 10;
			b[i][j] = 5;
		}
		g--;
	}


	c = a + b;


	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b= " << endl << b << endl;
	cout << "Matrix c = a + b " << endl << c << endl;
	return 0;
}