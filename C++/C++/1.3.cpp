#include "1.3.h"
#include <iostream>
#include <string>

using namespace std;

int Question_1_3::run() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	if (isPermutation(s1, s2)) {
		cout << "is permutation" << endl;
	}
	else {
		cout << "is not permutation" << endl;
	}
	cout << "Press any key to exit..." << endl;
	cin >> s1;
	return 0;
}

bool Question_1_3::isPermutation(const string s1, const string s2) {
	if (s1.length() != s2.length()) {
		return false;
	}

	int letterCounts[256] = { 0 };

	for (int i = 0; i < s1.length(); i++) {
		letterCounts[(int)s1[i]]++;
		letterCounts[(int)s2[i]]--;
	}

	for (int i = 0; i < 256; i++) {
		if (letterCounts[i] != 0) {
			return false;
		}
	}
	return true;
}