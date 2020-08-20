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
		// �������� �ڸ��� ��쿡 stack ũ�⸸ŭ ����
		if (bracket[i] == '(' && bracket[i + 1] == ')') { 
			cnt += s.size();
			i++;
		}
		else if (bracket[i] == '(')
			s.push(bracket[i]);
		// ������ ���� ���� ������ ���� �� �ϳ� �߰�
		else if (bracket[i] == ')') {
			s.pop();
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}