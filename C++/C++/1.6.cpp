#include "1.6.h"
#include <iostream>
#include <string>

using namespace std;

int Question_1_6::run() {
	int matrix[][5] = { { 1, 2, 3, 4, 5 },
						{ 6, 7, 8, 9, 10 },
						{ 11, 12, 13, 14, 15 },
						{ 16, 17, 18, 19, 20 },
						{ 21, 22, 23, 24, 25 } };
	int* matrixPtr = (int*)matrix;
	cout << "original matrix is :" << endl;
	printMatrix(matrixPtr, 5, 5);
	rotate90(5, matrixPtr);
	cout << "rotated matrix is: " << endl;
	printMatrix(matrixPtr, 5, 5);
	string s;
	cin >> s;
	return 0;
}

void Question_1_6::printMatrix(int* matrix, int m, int n) {
	for (int i = 0; i<m; ++i) {
		for (int j = 0; j<n; ++j) {
			cout << matrix[i*n + j] << " ";
		}
		cout << endl;
	}
}

void Question_1_6::rotate90(int n, int* matrix) {
	for (int layer = 0; layer < n / 2; ++layer) {
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first; i < last; ++i) {
			int offset = i - first;
			// save top
			int top = matrix[first*n + i];

			// left to top
			matrix[first*n + i] = matrix[(last - offset)*n + first];

			// bottom to left
			matrix[(last - offset)*n + first] = matrix[last*n + (last - offset)];

			// right to bottom
			matrix[last*n + (last - offset)] = matrix[i*n + last];

			// top to right
			matrix[i*n + last] = top;
		}
	}

}