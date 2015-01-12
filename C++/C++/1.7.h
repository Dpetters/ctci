#ifndef __Question_1_7__
#define __Question_1_7__

using namespace std;

struct MatrixLoc {
	int x;
	int y;
};

class Question_1_7 {
public:
	int run();
	const MatrixLoc* findLocOfZero(int* matrix, int m, int n);
	void setColAndRowToZero(int* matrix, int m, int n);
	void printMatrix(int* matrix, int m, int n);
};

#endif // __Question_1_7__