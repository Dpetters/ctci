#include "1.6.h"
#include "1.7.h"
#include <iostream>
#include <string>

using namespace std;

int Question_1_7::run() {
	int matrix[][5] = { { 1, 2, 3, 4, 5 },
	{ 6, 7, 8, 9, 10 },
	{ 11, 12, 13, 14, 15 },
	{ 16, 17, 18, 19, 20 },
	{ 0, 22, 23, 24, 25 } };
	int* matrixPtr = (int*)matrix;
	cout << "original matrix is :" << endl;
	printMatrix(matrixPtr, 5, 5);
	setColAndRowToZero(matrixPtr, 5, 5);
	cout << "processed matrix is: " << endl;
	printMatrix(matrixPtr, 5, 5);
	string s;
	cin >> s;
	return 0;
}

void Question_1_7::printMatrix(int* matrix, int m, int n) {
	for (int i = 0; i<m; ++i) {
		for (int j = 0; j<n; ++j) {
			cout << matrix[i*n + j] << " ";
		}
		cout << endl;
	}
}

const MatrixLoc* Question_1_7::findLocOfZero(int* matrix, int m, int n) {
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (*(matrix + i+j*n) == 0) {
				MatrixLoc l;
				l.x = i;
				l.y = j;
				return &l;
			}
		}
	}
	return nullptr;
}

void Question_1_7::setColAndRowToZero(int* matrix, int m, int n) {
	const MatrixLoc* l = findLocOfZero(matrix, m, n);
	if (l == nullptr) {
		return;
	}
	for (int i = 0; i < m; i++) {
		*(matrix + i + (*l).y*n) = 0;
	}
	for (int i = 0; i < n; i++) {
		*(matrix + (*l).x + i*n) = 0;
	}
	return;
}