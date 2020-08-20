#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#pragma warning(disable: 4996);
using namespace std;

int main() {
	string bracket;
	cin >> bracket;
	stack<char> s;
	int cnt=0;
	for (int i = 0; i < bracket.size(); i++) {
		// 레이저로 자르는 경우에 stack 크기만큼 증가
		if (bracket[i] == '(' && bracket[i + 1] == ')') { 
			cnt += s.size();
			i++;
		}
		else if (bracket[i] == '(')
			s.push(bracket[i]);
		// 마지막 닫힐 때는 마지막 조각 단 하나 추가
		else if (bracket[i] == ')') {
			s.pop();
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}