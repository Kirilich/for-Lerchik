// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "matrixx.h"
#include <fstream>

int main()
{
	int n = 0;
	int m = 0;
	do {
		std::cout << "n = ";
		std::cin >> n;
	} while (n < 1);
	do {
		std::cout << "m = ";
		std::cin >> m;
	} while (m < 1);
	
	double** Z = zeros(n, m);
	printMatrix(Z, n, m, "Z =\n");

	double** O = ones(n, m);
	printMatrix(O, n, m, "O =\n");

	double** L = linspace(1, m);
	printMatrix(L, 1, m, "L =\n");

	double** A = plusMatrix(O, O, n, m);
	printMatrix(A, n, m, "O + O =\n");

	double** Lt = transpose(L, 1, m);
	//printMatrix(C, n, m, "C =\n");

	double** B = multMatrix(Lt, m, 1, L, 1, m);
	printMatrix(B, m, m, "B =\n");

	try {
		saveMatrix("result.txt", B, m, m);
	}
	catch (const char *error) {
		std::cout << "Error: " << error << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error." << std::endl;
	}

	deleteMatrix(Z, n, m);
	deleteMatrix(O, n, m);
	deleteMatrix(L, 1, m);
	deleteMatrix(A, n, m);
	deleteMatrix(B, m, m);
	deleteMatrix(Lt, m, 1);
	/*double** M = createMatrix(n, m);

	inputMatrix(M, n, m);

	printMatrix(M, n, m, "M = \n");

	deleteMatrix(M, n, m);*/
    return 0;
}

/*double** createMatrix(int rows, int columns);
void deleteMatrix(double** &M, int rows, int columns);
void inputMatrix(double** M, int rows, int columns);
void printMatrix(double** M, int rows, int columns, const char* str = "");*/

