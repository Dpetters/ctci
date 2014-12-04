#include <iostream>
#include <string>
#include "1.1.h"

using namespace std;


int Question_1_1::run() {
	string s;
	while (1)
	{
		getline(cin, s);
		if (s == "exit") {
			return 0;
		}
		if (onlyUniqueChars(s.c_str())) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
}

bool Question_1_1::onlyUniqueChars(const char* s) {
	long l = 0;
	int tmp;
	while (*s != '\0') {
		tmp = (int)(*s)-97;
		if (isIthDigitOne(l, tmp)) {
			return false;
		}
		l |= (1 << tmp);
		s = s + 1;
	}
	return true;
}

bool Question_1_1::isIthDigitOne(long l, int i) {
	if (i > 255 || i < 0) {
		return false;
	}
	else {
		return (l & (1 << i)) != 0;
	}
}