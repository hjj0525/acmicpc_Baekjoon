#include <iostream>
#include <cstdio>
#include <string>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	string str;
	
	while (getline(cin, str)) {
		int lower = 0;
		int upper = 0;
		int number = 0;
		int space = 0;

		for (char x : str) {
			if (x >= 'a' && x <= 'z')
				lower++;
			else if (x >= 'A' && x <= 'Z')
				upper++;
			else if (x >= '0' && x <= '9')
				number++;
			else if (x == ' ')
				space++;
		}
		cout << lower << ' ' << upper << ' ' << number << ' ' << space << endl;
	}
	return 0;
}