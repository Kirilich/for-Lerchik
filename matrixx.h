#pragma once

#ifndef __MlCH__
#define __MlCH__



double** createMatrix(int rows, int columns);
void deleteMatrix(double** &M, int rows, int coluvns);
void inputMatrix(double** M, int rows, int columns);
void printMatrix(double** M, int rows, int columns, const char* str = "");
double** zeros(int rows, int columns);
double** ones(int rows, int columns);
double** eye(int size);
double** linspace(int from, int to);
double** plusMatrix(double** A, double** B, int rows, int columns);//сложение матриц
double** mulMatrix(double** A, double B, int rows, int columns);//умножение на число
double** multMatrix(double** A,int rowsA, int columnsA, double** B, int rowsB, int columnsB); //умножение одной матрицы на другую
double** transpose(double** A, int rows, int columns);
void saveMatrix(const char *fname, double** A, int rows, int columns);
#endif // !__MlCH__