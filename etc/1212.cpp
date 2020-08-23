#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	string s, out = "";
	cin >> s;

	for (int i = 0; i < s.size();i++) {
		switch (s[i]){
		case '0':
			if (i == 0)
				out+= "0";
			else
				out+= "000";
			break;
		case '1':
			if (i == 0)
				out+= "1";
			else
				out+= "001";
			break;

		case '2':
			if (i == 0)
				out+= "10";
			else
				out+= "010";
			break;

		case '3':
			if (i == 0)
				out+= "11";
			else
				out+= "011";
			break;

		case '4':
			out+= "100";
			break;
		case '5':
			out+= "101";
			break;
		case '6':
			out+= "110";
			break;
		case '7':
			out+= "110";
			break;
		default:
			break;
		}
	}
	cout << out << endl;
	return 0;
}