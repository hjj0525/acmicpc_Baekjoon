#include <iostream>
#include <cstdio>
#include <string>
#include <list>
#include <algorithm>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	string s;
	cin >> s;
	int M;
	cin >> M;
	list<char> List;
	// 문자열의 문자들 list에 하나씩 삽입하기
	for (char c : s)
		List.push_back(c);

	list<char>::iterator pos = List.end();
	while (M--) {
		char order;
		cin >> order;
		char ch;
		if (order == 'P') {
			cin >> ch;
			List.insert(pos, ch);
		}
		else if (order == 'L') {
			if (pos != List.begin())
				pos--;
		}
		else if (order == 'D') {
			if (pos != List.end())
				pos++;
		}
		else if (order == 'B') {
			if (pos != List.begin()) {
				pos--;
				pos = List.erase(pos);
			}
		}
	}
	for (char c : List)
		cout << c;
	cout << endl;
	return 0;
}