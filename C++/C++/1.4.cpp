#include "1.4.h"
#include <iostream>
#include <string>

using namespace std;

int Question_1_4::run() {
	string s = "hello world dmitrij";
	char* c = new char[s.length() + 2*2 + 1];
	for (int i = 0; i < s.length(); i++) {
		c[i] = s[i];
	}
	*(c + s.length()) = '\0';

	Question_1_4::replaceSpaces(c);
	cout << c << endl;
	cin >> s;
	return 0;
}

void Question_1_4::replaceSpaces(char* str) {
	int finalLength = 0;
	int initialLength = 0;

	// first pass
	while (*str != '\0') {
		if (*str == ' ') {
			finalLength += 3;
		}
		else {
			finalLength++;
		}
		initialLength++;
		str++;
	}

	// second pass
	char* finalEnd = str + (finalLength - initialLength);
	*finalEnd = '\0';
	finalEnd--;
	for (int i = 1; i <= initialLength; i++) {
		char c = *(str - i);
		if (c == ' ') {
			*finalEnd = '0';
			finalEnd--;
			*finalEnd = '2';
			finalEnd--;
			*finalEnd = '%';
		}
		else {
			*finalEnd = c;
		}
		finalEnd--;
	}
}