#include "1.2.h"
#include <iostream>
#include <string>

using namespace std;

int Question_1_2::run() {
	char str[] = "testing";
	reverse(str);
	cout << str << endl;
	string s;
	getline(cin, s);
	return 0;
}

void Question_1_2::reverse(char* str) {
	if (*str == '\0') {
		return;
	}
	char* end = str;
	while (*(end + 1) != '\0') {
		end++;
	}
	while (end > str) {
		exchange(str, end);
		str++;
		end--;
	}
}

void Question_1_2::exchange(char* x, char* y) {
	char tmp = *x;
	*x = *y;
	*y = tmp;
}
