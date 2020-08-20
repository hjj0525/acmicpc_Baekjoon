#include <iostream>
#include <cstdio>
#include <string>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			if (str[i] > 'z' - 13)
				str[i] = str[i] +(- 'z' + 'a') + 12;
			else
				str[i] += 13;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			if (str[i] > 'Z' - 13)
				str[i] = str[i] +(- 'Z' + 'A') + 12;
			else
				str[i] += 13;
		}
	}
	cout << str << endl;
	return 0;
}