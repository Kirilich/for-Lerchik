#include "stdafx.h"

#include "matrixx.h"

#include <iostream>

#include <fstream>
/*
Создание матрицы, только выделение памяти.
*/
double** createMatrix(int rows, int columns) {
	double** M = new double*[rows];
	for (int row = 0; row < rows; ++row) {
		M[row] = new double[columns];
	}
	return M;
}
/*
Освобождение памяти
кол-во столбиков не надо
*/
void deleteMatrix(double** &M, int rows, int coluvns) {
	for (int row = 0; row < rows; ++row) {
		delete[] M[row];
	}
	delete[] M;
	M = nullptr;
}

void inputMatrix(double** M, int rows, int columns) {
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < columns; ++col) {
			std::cout << "M(" << row + 1 << ", " << col + 1 << ") = ";
			std::cin >> M[row][col];
		}
	}
}

void printMatrix(double** M, int rows, int columns, const char* str) {
	std::cout << str;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < columns; ++col) {
			std::cout << M[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

double** zeros(int rows, int columns) {
	double** M = createMatrix(rows, columns);
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < columns; ++col) {
			M[row][col] = 0.0;
		}
	}
	return M;
}

double** ones(int rows, int columns) {
	double** M = createMatrix(rows, columns);
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < columns; ++col) {
			M[row][col] = 1.0;
		}
	}
	return M;
}

double** eye(int size) {
	double** M = zeros(size, size);
	for (int row = 0; row < size; ++row) {
		M[row][row] = 1.0;
	}
	return M;
}

double** linspace(int from, int to) {
	int size = (from > to) ? (from - to) : (to - from);
	++size;
	double** M = createMatrix(1, size);
	if (from < to) {
		for (int i = 0; i < size; ++i) {
			M[0][i] = from;
			++from;
		}
	}
	else {
		for (int i = 0; i < size; ++i) {
			M[0][i] = from;
			--from;
		}
	}
	return M;
}

double** plusMatrix(double** A, double** B, int rows, int columns) {
	double** C = createMatrix(rows, columns);
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < columns; ++col) {
			C[row][col] = A[row][col] + B[row][col];
		}
	}
	return C;
}

double** mulMatrix(double** A, double B, int rows, int columns) {
	double** C = createMatrix(rows, columns);
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < columns; ++col) {
			C[row][col] = A[row][col]*B;
		}
	}
	return C;
}

double** multMatrix(double** A, int rowsA, int columnsA, double** B, int rowsB, int columnsB) {
	double** C = zeros(rowsA, columnsB);
	for (int rowA = 0; rowA < rowsA; ++rowA) {
		for (int colB = 0; colB < columnsB; ++colB) {
			for (int colA = 0; colA < columnsA; ++colA) {
				C[rowA][colB] += A[rowA][colA] * B[colA][colB];
			}
		}
	}
	return C;
}
double** transpose(double** A, int rows, int columns) {
	double** B = createMatrix(columns, rows);
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < columns; ++col) {
			B[col][row] = A[row][col];
		}
	}
	return B;
}
void saveMatrix(const char *fname, double** A, int rows, int columns) {
	std::ofstream outFile(fname);
	if (!outFile) {
		throw "Can not write to file"; //генерация исключений
	}
	outFile << rows << " " << columns << std::endl;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < columns; ++col) {
			outFile << A[row][col] << " ";
		}
		outFile << std::endl;
	}
	outFile.close();
}
