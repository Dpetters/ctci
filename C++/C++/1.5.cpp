#include <string>
#include <iostream>
#include <sstream>

#include "1.5.h"


using namespace std;

int Question_1_5::run() {
	string s;
	cin >> s;
	cout << compress(s) << endl;
	cout << "Press any character to exit." << endl;
	cin >> s;
	return 0;
}

string Question_1_5::intToString(int i) {
	stringstream convert;
	convert << i;
	return convert.str();
}

string Question_1_5::compress(const string& str) {
	int count = 1;
	int newLength = 2;
	char newChar, lastChar = str.at(0);
	for (unsigned int i = 1; i < str.length(); i++) {
		newChar = str[i];
		if (lastChar != newChar) {
			newLength++;
			newLength += intToString(count).length();
			count = 1;
			lastChar = newChar;
		}
		else {
			count++;
		}
	}

	if (newLength >= str.length()) {
		return str;
	}
	
	string newstr;
	count = 1;
	lastChar = str.at(0);
	for (unsigned int i = 1; i < str.length(); i++) {
		newChar = str.at(i);
		if (lastChar != newChar) {		
			newstr += lastChar;
			newstr += intToString(count);
			lastChar = newChar;
			count = 1;
		}
		else 
		{
			count++;
		}
	}
	newstr += lastChar;
	newstr += intToString(count);

	return newstr;
}