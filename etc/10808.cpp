#include <iostream>
#include <cstdio>
#include <string>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	string str;
	int eng[26] = { 0, };
	cin >> str;

	for (int i = 0; i < str.size(); i++)
		eng[str[i] - 97]++;
	for (int i = 0; i < 26; i++)
		cout << eng[i] << " ";
	return 0;
}